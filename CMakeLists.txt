cmake_minimum_required(VERSION 3.15)

# For the `compile_comands.json`
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# The name of the project
set(PROJECT lfisy)
project(${PROJECT} VERSION 1)

# Path for installation
set(PREFIX /data/data/com.termux/files/usr/lib)
set(LUA_DIR lua/5.4)

# Sources for lfisy
set(SRCDIR src)
set(SOURCES
  ${SRCDIR}/lfisy.c
  ${SRCDIR}/file.c
)

# Include directories for lfisy
set(INCDIRS include)

include_directories(${INCDIRS})

add_library(${PROJECT} SHARED ${SOURCES})

set_target_properties(${PROJECT} PROPERTIES PREFIX "")

install(TARGETS ${PROJECT} DESTINATION ${PREFIX}/${LUA_DIR})
