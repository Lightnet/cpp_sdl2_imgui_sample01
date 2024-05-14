# g++
# lmingw32

#mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
#current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))
#ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
ROOT_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
#EXE = main
EXE = main

SDL_PATH = $(ROOT_DIR)/SDL2
SDL_LIBS = -L $(SDL_PATH)/lib/x64
SDL_INCLUDE = -I $(SDL_PATH)/include

IMGUI_DIR = $(ROOT_DIR)/imgui

IMGUI_INCLUDE = -I $(IMGUI_DIR)
IMGUI_INCLUDE += -I $(IMGUI_DIR)/backends
# SRC FILES
#SOURCES = src/main.cpp
SOURCES = src/sdl2_renderer_imgui.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp
SOURCES += $(IMGUI_DIR)/imgui_demo.cpp
SOURCES += $(IMGUI_DIR)/imgui_draw.cpp
SOURCES += $(IMGUI_DIR)/imgui_tables.cpp
SOURCES += $(IMGUI_DIR)/imgui_widgets.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl2.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdlrenderer2.cpp
#SOURCES = src/hello.cpp
#LIBS = -lmingw32 -lSDL2main -lSDL2
LIBS = -lSDL2main -lSDL2 -lopengl32
#FLAGS = 

all:
	g++ $(SDL_INCLUDE) $(SDL_LIBS) $(IMGUI_INCLUDE) -o $(EXE) $(SOURCES) $(LIBS)