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
	${CC} ./task-1.c -o ./build/task-1 ${FLAGS}

# Description: Command to build task-2.c
#
# Requirements: task-2.c
build-task-2: task-2.c
	${CC} ./task-2.c -o ./build/task-2 ${FLAGS}

# Description: Command to build task-3.c
#
# Requirements: task-3.c
build-task-3: task-3.c
	${CC} ./task-3.c -o ./build/task-3 ${FLAGS}

# Description: Runs task 1 by performing regular expression on the colours.txt file to get all
#              valid colour codes and passes them to task-1.exe to append 'ff' for the alpha value
#							 for 6 digit colour codes. For simplicity, we then create a new text file 'colours-valid.txt'
#							 to store these values so we do not have to run task 1 constantly
#
# Requirements: Task 1 must be built.
run-task-1: build-task-1
	cat ./colours.txt | grep -E -i '#([A-F0-9]{6}|[A-F0-9]{8})$$' | ./build/task-1 > colours-valid.txt && cat ./colours-valid.txt

# Description: Runs task 2 by utilizing task 1's 'colours-valid.txt' that contains all valid colour codes.
#              We then get the green value using 'cut', the results then being passed to task-2.exe
#              to convert the green value to a decimal and displaying as a comma separated list.
#
# Requirements: Task 1 and 2 must both be built.

run-task-2: run-task-1 build-task-2
	cat ./colours-valid.txt | cut -c4-5 | ./build/task-2 && rm colours-valid.txt

# Description: Runs task 3 by utilizing task 1's 'colours-valid.txt'. This command proceeds to split
#							 each colour code into 4 sections, "RR,GG,BB,AA", each section is appended to a temporary text file
#							 which we then use to convert the hex colours to the format 'rgba(RR, GG, BB, AA)'. To put it simply,
#							 I loop through the temp.txt file and fill in a struct representing our RGBA colours. After the loop
#							 has looped x times which we get by dividing the total number of lines in temp.txt by 4 (4 parts to 1 colour)
#							 to get the total number of colours. So every x loops, we switch to looping the next colour of each Struct e.g.
#							 if we filled in each Structs 'RR' value, next we must fill in the 'GG' value and so on. To calculate the Alpha
#							 value, I divided the decimal value of the hex by 255. To sort the new text file, 'rgba-colours.txt' I used the
#							 'sort' tool and sorted by the fourth column (sort -k4).
#
# Requirements: Task 1 and 3 must be built.
run-task-3: run-task-1 build-task-3
	cat ./colours-valid.txt | cut -c2-3 > temp.txt && cat ./colours-valid.txt | cut -c4-5 >> temp.txt && cat ./colours-valid.txt | cut -c6-7 >> temp.txt && cat ./colours-valid.txt | cut -c8-9 >> temp.txt && cat temp.txt | ./build/task-3 | sort -k4 > rgba-colours.txt && rm temp.txt && rm colours-valid.txt && ls

# Clears the enviornment from old files
clear:
	rm ./build/* && rm rgba-colours.txt && rm colours-valid.txt
