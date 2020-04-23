CC = gcc
FLAGS = -Wall -Wextra -Wpedantic

# Syntax:
# target: dependencies
# 	command

# Runs task 1, generates the string and counts the number of words in this string
run-task-1:
	printf "The quick brown fox jumps over the lazy dog\n" | wc -w

# Runs task 2, generates the string and converts all characters to uppercase
run-task-2:
	printf "The quick brown fox jumps over the lazy dog\n" | tr [:lower:] [:upper:]

# Runs task 3, downloads the DKIT home page as .html file
run-task-3:
	curl https://www.dkit.ie -o dkit.html && ls

# Runs task 4, needs access to dkit.html file from previous step, takes first and last line of the file
# and removes <> for each line and replaces them with [] respectively. Lastly, the lines are sorted in reverse.
run-task-4: run-task-3
	head -1 dkit.html | tr '<>' '[]' > ./mangled.txt && tail -1 dkit.html | tr '<>' '[]' >> ./mangled.txt && sort -r -o ./mangled.txt ./mangled.txt && ls

# Cleaers the enviornment from old files
clear:
	rm dkit.html mangled.txt

