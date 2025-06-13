#include "file.h"
#include <lua5.4/lua.h>
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>

int luaopen_lfisy(lua_State *L) {
  lua_newtable(L);
  lfisy_open_File(L);
  return 1;
}
