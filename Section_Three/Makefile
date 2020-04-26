CC = gcc
FLAGS = -Wall -Wextra -Wpedantic

# Command to build task-5.c
build-task-5: task-5.c
	${CC} ./task-5.c -o ./build/task-5 ${FLAGS}

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

# Runs task 4, I use 'grep' to read lines with 'Trident' in it,
# as Trident is a proprietary browser engine for the Microsoft Windows version of Internet Explorer,
# then I save those lines in new 'access.ie.log' file
run-task-4:
	grep -h 'Trident' access.log >access.ie.log

# Runs task 5, First I use 'grep' and 'sort' to create a 'temp1' file with all requested paths
# then I use 'grep' and 'sort' again to create 'temp2' file with all process times for those request paths
# then I use 'grep', 'sort' and 'uniq' to create 'temp3' file with all uniq requested paths
# then I use 'grep', 'sort' and 'uniq' again to create 'temp4' file with all total number of requests to each path
# then I use 'cat' to merge all 4 'temp' files into 1 'temp.txt' file
# then I use 'rm' to delete 'temp1', 'temp2', 'temp3' and 'temp4' files
# and finally using 'cat' I open 'temp.txt' file and I build task-5
run-task-5: build-task-5
	grep -h '[5-9][ ]["]' access.log | grep -E -o '[G][E][T][ ][/]([A-Za-z0-9]){1,20}' | grep -E -o '[/]([A-Za-z0-9]){1,20}' | sort > temp1.txt && grep -h '[5-9][ ]["]' access.log | grep -E -o '\"[A-Za-z0-9 /.-]+\"[ ][0-9][0-9][0-9][ ][0-9][ ]["]' | sort | grep -o '[0-9][ ]["]' | grep -o '[0-9]' > temp2.txt && grep -h '[5-9][ ]["]' access.log | grep -E -o '[G][E][T][ ][/]([A-Za-z0-9]){1,20}' | grep -E -o '[/]([A-Za-z0-9]){1,20}' | sort | uniq -c | grep -E -o '[/]([A-Za-z0-9]){1,20}' > temp3.txt && grep -h '[5-9][ ]["]' access.log | grep -E -o '[G][E][T][ ][/]([A-Za-z0-9]){1,20}' | grep -E -o '[/]([A-Za-z0-9]){1,20}' | sort | uniq -c | grep -o [0-9] > temp4.txt && cat temp1.txt temp2.txt temp3.txt temp4.txt > temp.txt && rm temp1.txt temp2.txt temp3.txt temp4.txt && cat temp.txt | ./build/task-5 && rm temp.txt

# Clears the enviornment from old files
clear:
	rm access.ie.log && rm ./build/* && rm ./temp.txt
