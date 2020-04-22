# Display last 10 lines of the access.log file and print a new line (for aesthetic reasons)
run-task-1:
	tail -10 access.log && echo

# Runs task 2, I use 'cat' to read 'access.log' file, then I use 'grep' to print only the matching parts of the file
# and also I use 'uniq' to only display unique IP adderesses
run-task-2:
	cat ./access.log | grep -E -o '[0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}' | uniq
