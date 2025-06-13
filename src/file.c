#include "file.h"
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>
#include <lua5.4/lua.h>
#include <stdlib.h>

static int lfisy_File_new(lua_State *L) {
  lfisy_File *file = (lfisy_File *)lua_newuserdata(L, 1);
  file->path = calloc(100, 1);
  luaL_getmetatable(L, "lfisy.File");
  lua_setmetatable(L, -2);
  return 1;
}

static int lfisy_File_exists(lua_State *L) {
  lua_pushstring(L, "Verifying file");
  return 1;
}

static const luaL_Reg lfisy_File_meta[] = {
  { "__index", NULL },
  { NULL, NULL }
};

static const luaL_Reg lfisy_File_methods[] = {
  { "exists", lfisy_File_exists },
  { NULL, NULL }
};

void lfisy_open_File(lua_State *L) {
  luaL_newmetatable(L, "lfisy.File");
  luaL_setfuncs(L, lfisy_File_meta, 0);
  lua_newtable(L);
  luaL_setfuncs(L, lfisy_File_methods, 0);
  lua_setfield(L, -2, "__index");
  lua_pop(L, 1);
  lua_pushcfunction(L, lfisy_File_new);
  lua_setfield(L, -2, "File");
}
