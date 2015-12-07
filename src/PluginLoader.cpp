#include "PluginLoader.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include "luainc.h"
#include <string>
#include "Util.hpp"

namespace fs = boost::filesystem;

PluginLoader::PluginLoader()
{
    lua = luaL_newstate();
    luaL_openlibs(lua);
}

PluginLoader::~PluginLoader()
{
    lua_close(lua);
}

bool PluginLoader::load()
{
    bool status = false;
    fs::path path("../plugins");

    try
    {
        if (fs::exists(path))
        {
            if(fs::is_directory(path))
            {
                for (fs::directory_entry& x : fs::directory_iterator(path))
                {
                    Plugin plugin;
                    if (luaL_dofile(lua, x.path().string().c_str()))
                    {
                        std::cout << "Failed to load " << x.path() << std::endl;
                    }
                    else
                    {
                        plugin.type(plugin.getAttr(lua, "ptype"));
						plugin.name(plugin.getAttr(lua, "name"));
                        plugin.version(plugin.getAttr(lua, "pver"));
						plugin.path(x.path().string());
                        lua_setglobal(lua, plugin.path().c_str());
                        pluginVector.push_back(plugin); 
						std::cout << plugin.type() << " " << plugin.name() << " " << plugin.version() << std::endl;
						status = true;
						Util::expose(lua, std::string("testing 2"), "testVar");
						Util::expose(lua, 7, "testInt");
						Util::expose(lua, false, "testBool");
                    }
                }
            }
        }
    }

    catch (const boost::filesystem::filesystem_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    runAll();

	return status;
}

bool PluginLoader::run(Plugin plugin)
{
    lua_State* L = lua_newthread(lua);
    lua_getglobal(L, plugin.path().c_str());
    lua_getfield(L, -1, "run");
    lua_pushstring(L, plugin.path().c_str());
    return lua_pcall(L, 1, LUA_MULTRET, 0);
}

void PluginLoader::runAll()
{
  for(auto& plugin : pluginVector)
  {
    run(plugin);
  }
}
