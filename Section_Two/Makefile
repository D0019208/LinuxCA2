CC = gcc
FLAGS = -Wall -Wextra -Wpedantic
SECTION_TWO_PATH = ~/ca2/Section_Two

# Syntax:
# target: dependencies
# 	command

# Description: Command to build task-1.c
#
# Requirements: task-1.c
build-task-1: task-1.c
	${CC} ./task-1.c -o ./build/task-1.exe ${FLAGS}

# Description: Command to build task-2.c
#
# Requirements: task-2.c
build-task-2: task-2.c
	${CC} ./task-2.c -o ./build/task-2.exe ${FLAGS}

# Description: Command to build task-2.c
#
# Requirements: task-2.c
build-task-3: task-3.c
	${CC} ./task-3.c -o ./build/task-3.exe ${FLAGS}

# Description: Runs task 1 by performing regular expression on the colours.txt file to get all
#              valid colour codes and passes them to task-1.exe to append 'ff' for the alpha value
#							 for 6 digit colour codes.
#
# Requirements: Task 1 must be built.
run-task-1: build-task-1
	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe

# Description: Runs task 2 by utilizing task 1 to get all valid colour codes, append 'ff'.
#              We then get the green value using 'cut', the results then being passed to task-2.exe
#              to convert the green value to a decimal and displaying as a comma separated list.
#
# Requirements: Task 1 and 2 must both be built.
run-task-2: build-task-1 build-task-2
	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe | cut -c4-5 | ./build/task-2.exe

run-task-3: build-task-1 build-task-3
	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe | cut -c2-3 > temp.txt && cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe | cut -c4-5 >> temp.txt && cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe | cut -c6-7 >> temp.txt && cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe | cut -c8-9 >> temp.txt && cat temp.txt | ./build/task-3.exe > rgba-colours.txt && rm temp.txt

# Clears the enviornment from old files
clear:
	rm ./build/* && rm temp.txt && rm rgba-colours.txt
