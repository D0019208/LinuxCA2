# OS CA2

Below you will find how to run each task of Section 1, 2 and 3 along with an explanation of the logic that was used in solving each task.

## Section 1

### Task 1

Here we are simply using printf on the string "The quick brown fox jumps over the lazy dog\n" and piping that data to the 'wc' tool which with the flag 'w' will count all words.
<br /><br />
To run task 1/4, perform the following command while located in 'Section_One' folder
```
> make run-task-1
```

### Task 2

Only difference between Task 1 and 2 is that we are piping the data to the 'tr' tool which with the flags '[:lower:] [:upper:]' turns the string to all uppercase.
<br /><br />
To run task 2/4, perform the following command while located in 'Section_One' folder
```
> make run-task-2
```

### Task 3

For task 3, we simply use the 'curl' tool to download the webpage at https://www.dkit.ie -o dkit.html and then display the directory using the 'ls' to confirm that we have downloaded the html page
<br /><br />
To run task 3/4, perform the following command while located in 'Section_One' folder
```
> make run-task-3
```

### Task 4

To accomplish task 4, our command takes the first and last line of the file and removes <> for each line and replaces them with [] respectively. Lastly, the lines are sorted in reverse and outputed to the 'mangled.txt' file and using the 'ls' tool we confirm that the file has been created.
<br /><br />
To run task 4/4, perform the following command while located in 'Section_One' folder
```
> make run-task-4
```

## Section 2

### Task 1

To complete task 1, we perform a regular expression on the colours.txt file to get all valid colour codes and passes them to task-1.exe to append 'ff' for the alpha value for 6 digit colour codes. 
<br /><br />
For simplicity, we then create a new text file 'colours-valid.txt' to store these values so we do not have to run task 1 constantly
<br /><br />
To run task 1/3, perform the following command while located in 'Section_Two' folder
```
> make run-task-1
```

### Task 2

To complete task 2, we are utilizing task 1's 'colours-valid.txt' that contains all valid colour codes. We then get the green value using 'cut', the results then being passed to task-2.exe to convert the green value to a decimal and displaying as a comma separated list.
<br /><br />
To run task 2/3, perform the following command while located in 'Section_Two' folder
```
> make run-task-2
```

### Task 3

Same as before, task 3 utilizes task 1's 'colours-valid.txt'. This command proceeds to split each colour code into 4 sections, "RR,GG,BB,AA", each section is appended to a temporary text file which we then use to convert the hex colours to the format 'rgba(RR, GG, BB, AA)'. 
<br /><br />
To put it simply, I loop through the temp.txt file and fill in a struct representing our RGBA colours. After the loop has looped x times which we get by dividing the total number of lines in temp.txt by 4 (4 parts to 1 colour) to get the total number of colours. 
<br /><br />
So every x loops, we switch to looping the next colour of each Struct e.g. if we filled in each Structs 'RR' value, next we must fill in the 'GG' value and so on. To calculate the Alpha value, I divided the decimal value of the hex by 255. To sort the new text file, 'rgba-colours.txt' I used the 'sort' tool and sorted by the fourth column (sort -k4).
<br /><br />
To run task 3/3, perform the following command while located in 'Section_Two' folder
```
> make run-task-3
```

### Task 3

Same as before, task 3 utilizes task 1's 'colours-valid.txt'. This command proceeds to split each colour code into 4 sections, "RR,GG,BB,AA", each section is appended to a temporary text file which we then use to convert the hex colours to the format 'rgba(RR, GG, BB, AA)'. 
<br /><br />
To put it simply, I loop through the temp.txt file and fill in a struct representing our RGBA colours. After the loop has looped x times which we get by dividing the total number of lines in temp.txt by 4 (4 parts to 1 colour) to get the total number of colours. 
<br /><br />
So every x loops, we switch to looping the next colour of each Struct e.g. if we filled in each Structs 'RR' value, next we must fill in the 'GG' value and so on. To calculate the Alpha value, I divided the decimal value of the hex by 255. To sort the new text file, 'rgba-colours.txt' I used the 'sort' tool and sorted by the fourth column (sort -k4).
<br /><br />
To run task 3/3, perform the following command while located in 'Section_Two' folder
```
> make run-task-3
```

## Section 3

### Task 1

To complete task 1, we are simply using the 'tail' tool to print the last 10 lines using the '-10' flag
<br /><br />
To run task 1/5, perform the following command while located in 'Section_Two' folder
```
> make run-task-1
```

### Task 2

For task 2, we use 'cat' to read 'access.log' file, then I use 'grep' to print only the matching parts of the file and also I use 'uniq' to only display unique IP adderesses
<br /><br />
To run task 2/5, perform the following command while located in 'Section_Two' folder
```
> make run-task-2
```

### Task 3

Again, we use 'cat' to read 'access.log' file, then we use 'grep' to find lines with 404 status and then we use grep again to only print the 'REQUEST' part, we next filter it using regex
<br /><br />
To run task 3/5, perform the following command while located in 'Section_Two' folder
```
> make run-task-3
```

### Task 4

We use 'grep' to read lines with 'Trident' in it, as Trident is a proprietary browser engine for the Microsoft Windows version of Internet Explorer, then we save those lines in new 'access.ie.log' file
<br /><br />
To run task 4/5, perform the following command while located in 'Section_Two' folder
```
> make run-task-4
```

### Task 5

Runs task 5, First we use 'grep' and 'sort' to create a 'temp1' file with all requested paths then we use 'grep' and 'sort' again to create 'temp2' file with all process times for those request paths then we use 'grep', 'sort' and 'uniq' to create 'temp3' file with all uniq requested paths then we use 'grep', 'sort' and 'uniq' again to create 'temp4' file with all total number of requests to each path then we use 'cat' to merge all 4 'temp' files into 1 'temp.txt' file then we use 'rm' to delete 'temp1', 'temp2', 'temp3' and 'temp4' files and finally using 'cat' we open 'temp.txt' file and we build task-5
<br /><br />
To run task 5/5, perform the following command while located in 'Section_Two' folder
```
> make run-task-5
```

## Authors

* **Nichita Postolachi** - *Section 1: Task 3 and 4. Section 2: All. Section 3: Task 1* - [D0019208](https://github.com/D0019208)
* **German Luter** - *Section 1: Task 1 and 2. Section 3: Task 2-5* - [D00194503REAL](https://github.com/D00194503REAL) 

## Screencast
https://www.youtube.com/watch?v=pKl91mtn4lE&feature=youtu.be
