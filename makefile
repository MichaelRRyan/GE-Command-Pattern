CXX			:= gcc

SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LDFLAGS := $(shell sdl2-config --libs)

CXXFLAGS 	:= -Wall -Wextra -Werror -g -I. ${SDL_CFLAGS} ${SDL_LDFLAGS}

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

BUILD_DIR	:= ./bin
SRC_DIR		:= ./src

TARGET		:= ${BUILD_DIR}/app.bin

SRC			:= ${SRC_DIR}/*.cpp

all			:= build

build:
	@echo ${MSG_START}

	@echo ${CXXFLAGS}

	#remove directory if it exits and then create directory
	rm -rf ${BUILD_DIR} || true

	#create bin directory
	mkdir ${BUILD_DIR}

	${CXX} -o ${TARGET} ${SRC} ${CXXFLAGS}
	@echo ${MSG_END}
	./${TARGET}

.PHONY: clean

clean:
	@echo ${MSG_CLEAN}
	rm -rf ${BUILD_DIR} || true