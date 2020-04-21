CC = gcc
FLAGS = -Wall -Wextra -Wpedantic
SECTION_TWO_PATH = ~/ca2/Section_Two

# Syntax:
# target: dependencies
# 	command

# Runs task 1, perform a regex query using grep to get all valid colour codes (6 and 8 chars long)
# Next I pass this list as an argument to a custom C program that adds an ff for all missing alpha values
run-task-1: task-1.c
	 ${CC} ./task-1.c -o ./build/task-1.exe ${FLAGS}

	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1.exe

# Runs task 4, needs access to dkit.html file from previous step, takes first and last line of the file
# and removes <> for each line and replaces them with [] respectively. Lastly, the lines are sorted in reverse.
run-task-4: ${SECTION_ONE_PATH}/dkit.html
	touch ${SECTION_ONE_PATH}/mangled.txt && head -1 dkit.html | tr '<>' '[]' >> ${SECTION_ONE_PATH}/mangled.txt && tail -1 dkit.html | tr '<>' '[]' >> ${SECTION_ONE_PATH}/mangled.txt && sort -r -o ${SECTION_ONE_PATH}/mangled.txt ${SECTION_ONE_PATH}/mangled.txt

# Cleaers the enviornment from old files
clear:
	rm dkit.html mangled.txt

