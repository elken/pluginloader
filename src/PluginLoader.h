//
// Created by elken on 03/12/15.
//

#ifndef PLUGINLOADER_PLUGINLOADER_H
#define PLUGINLOADER_PLUGINLOADER_H
#include <vector>
#include "luainc.h"
#include "Plugin.h"

class PluginLoader
{
    std::vector<Plugin> pluginVector;
    lua_State* lua;

public:
    PluginLoader();
    ~PluginLoader();
    bool load();
    bool run(Plugin plugin);
    void runAll();
};


#endif //PLUGINLOADER_PLUGINLOADER_H
