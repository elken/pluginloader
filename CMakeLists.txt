cmake_minimum_required(VERSION 2.8)
project(pluginloader C CXX)
add_compile_options(-std=c++11)
find_package(Boost COMPONENTS filesystem system)
find_package(Lua REQUIRED)
set(SOURCE
    src/main.cpp src/Plugin.h src/PluginType.h src/PluginLoader.cpp src/PluginLoader.h)
include_directories(
    ${LUA_INCLUDE_DIRS}
    ${Boost_LIBRARIES})
add_executable(pluginloader
    ${SOURCE})
target_link_libraries(pluginloader
    ${LUA_LIBRARIES}
    ${Boost_LIBRARIES})