#pragma once
#include "luainc.h"
#include <iostream>
#include <typeinfo>
#include <boost/lexical_cast.hpp>

template <class T>
class Property
{
	T _val;
public:
	T const& operator()() const 
	{
		return _val;
	}

	void operator()(T const& _newVal)
	{
		_val = _newVal;
	}
};

namespace Util 
{
	template <typename T>
	static void expose(lua_State * lua, T val, std::string name)
	{
		if (typeid(val).name() == typeid(std::string("")).name())
		{
			lua_pushstring(lua, (const char*)boost::lexical_cast<std::string>(val).c_str());
		}
		else if (typeid(val).name() == typeid(int(6)).name())
		{
			lua_pushinteger(lua, boost::lexical_cast<int>(val));
		}
		else if (typeid(val).name() == typeid(bool(false)).name())
		{
			lua_pushboolean(lua, boost::lexical_cast<bool>(val));
		}
		else
		{
			std::cerr << "Error: Type invalid." << std::endl;
			return;
		}

		lua_setglobal(lua, name.c_str());
	}
}
