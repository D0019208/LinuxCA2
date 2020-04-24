# Display last 10 lines of the access.log file and print a new line (for aesthetic reasons)
run-task-1:
	tail -10 access.log && echo

# Runs task 2, I use 'cat' to read 'access.log' file, then I use 'grep' to print only the matching parts of the file
# and also I use 'uniq' to only display unique IP adderesses
run-task-2:
	cat ./access.log | grep -E -o '[0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}[.][0-9]{1,3}' | uniq

# Runs task 3, I use 'cat' to read 'access.log' file, then I use 'grep' to find lines with 404 status
# and then I use grep again to only print the 'REQUEST' part, I filter it using regex
run-task-3:
	cat ./access.log | grep -h '[4][0][4]' | grep -E -o '\"[A-Za-z0-9 /.-]+\"'

# Runs task 4, I use grep to read lines with 'Trident' in it, 
# as Trident is a proprietary browser engine for the Microsoft Windows version of Internet Explorer,
# then I save those lines in new 'access.ie.log' file
run-task-4:
	grep -h 'Trident' access.log >access.ie.log

# Clears the enviornment from old files
clear:
	rm access.ie.log
