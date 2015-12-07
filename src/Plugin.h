#ifndef PLUGINLOADER_PLUGIN_H
#define PLUGINLOADER_PLUGIN_H
#include <string>
#include "luainc.h"
#include "Util.hpp"

class Plugin
{
public:
    std::string getAttr(lua_State* lua, std::string attr);
	
	Property<std::string> type;
	Property<std::string> name;
	Property<std::string> version;
	Property<std::string> path;
};


#endif //PLUGINLOADER_PLUGIN_H
