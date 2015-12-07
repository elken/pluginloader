if(WIN32)
    cmake_minimum_required(VERSION 3.1.0)
    set(CMAKE_CXX_STANDARD 11)
else()
    cmake_minimum_required(VERSION 2.8.12)
    add_compile_options(-std=c++11)
endif()

project(pluginloader C CXX)
set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost COMPONENTS filesystem system)
find_package(Lua REQUIRED)

set(SOURCE
    src/main.cpp 
	src/Plugin.h 
	src/Plugin.cpp 
	src/PluginType.h 
	src/PluginLoader.cpp 
	src/PluginLoader.h
	src/Util.hpp)
include_directories(
    ${LUA_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR})
add_executable(pluginloader
    ${SOURCE})
target_link_libraries(pluginloader
    ${LUA_LIBRARIES}
    ${Boost_LIBRARIES})
if (MSVC)
	set_target_properties(${PROJECT} PROPERTIES
	WIN32_EXECUTABLE YES
	LINK_FLAGS "/ENTRY:mainCRTStartup"
)
endif ()