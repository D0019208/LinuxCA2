CC = gcc
FLAGS = -Wall -Wextra -Wpedantic
SECTION_ONE_PATH = ~/ca2/Section_One

# Syntax:
# target: dependencies
# 	command

# Runs task 3, downloads the DKIT home page as .html file
run-task-3:
	curl https://www.dkit.ie -o dkit.html

# Runs task 4, needs access to dkit.html file from previous step, takes first and last line of the file
# and removes <> for each line and replaces them with [] respectively. Lastly, the lines are sorted in reverse.
run-task-4: ${SECTION_ONE_PATH}/dkit.html
	touch ${SECTION_ONE_PATH}/mangled.txt && head -1 dkit.html | tr '<>' '[]' >> ${SECTION_ONE_PATH}/mangled.txt && tail -1 dkit.html | tr '<>' '[]' >> ${SECTION_ONE_PATH}/mangled.txt && sort -r -o ${SECTION_ONE_PATH}/mangled.txt ${SECTION_ONE_PATH}/mangled.txt

# Cleaers the enviornment from old files
clear:
	rm dkit.html mangled.txt

