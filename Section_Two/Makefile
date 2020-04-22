CC = gcc
FLAGS = -Wall -Wextra -Wpedantic
SECTION_TWO_PATH = ~/ca2/Section_Two

# Syntax:
# target: dependencies
# 	command

# Runs task 1, perform a regex query using grep to get all valid colour codes (6 and 8 chars long)
# Next I pass this list as an argument to a custom C program that adds an ff for all missing alpha values
build-task-1: task-1.c
	${CC} ./task-1.c -o ./build/task-1.exe ${FLAGS}

run-task-1: build-task-1
	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe

run-task-2: build-task-1
	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe | cut -c4-5

# Cleaers the enviornment from old files
clear:
	rm ./build/*

