CC = gcc
FLAGS = -Wall -Wextra -Wpedantic

# Syntax:
# target: dependencies
# 	command

# This target is the final compile and depends on other targets
run-task-3:
	curl https://www.dkit.ie -o dkit.html

clear:
	rm dkit.html

