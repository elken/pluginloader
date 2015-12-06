#include "Plugin.h"

std::string Plugin::getAttr(lua_State* lua, std::string attr)
{
  lua_getfield(lua, -1, attr.c_str());
  std::string returnString = lua_tostring(lua, -1);
  lua_pop(lua, 1);
  return returnString;
}
