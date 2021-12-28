cmake_minimum_required(VERSION 3.2)

project(rn40-project)

set(SRC_FILES
	src/main.c
	src/input.c
	src/sort.c
	src/bucket.c
)

set(HEADER_FILES
	src/input.h
	src/sort.h
	src/bucket.h
)

add_executable(rn40-project ${SRC_FILES} ${HEADER_FILES})