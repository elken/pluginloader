//
// Created by elken on 03/12/15.
//

#ifndef PLUGINLOADER_PLUGIN_H
#define PLUGINLOADER_PLUGIN_H
#include <string>

struct Plugin
{
    std::string type;
    std::string name;
    std::string path;
    std::string version;
    std::string getAttr(lua_State* lua, std::string attr);
};


#endif //PLUGINLOADER_PLUGIN_H
