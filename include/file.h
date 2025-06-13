#ifndef LFISY_FILE_H
#define LFISY_FILE_H

#include <lua5.4/lua.h>

typedef struct lfisy_Stat {
  int state;
} lfisy_Stat;

typedef struct {
  char *path;
  int lines;
  char **content;
} lfisy_File;

static int lfisy_File_new(lua_State *L);
void lfisy_open_File(lua_State *L);

#endif
