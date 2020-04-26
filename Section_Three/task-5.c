#define VALID_OPTIONS 18

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
	int num_of_inputs = VALID_OPTIONS/2;

	char r_path[num_of_inputs][15];
	char p_time[num_of_inputs][15];
	int p_time_int[num_of_inputs];
	int j = 1;
	int k = 1;
	int l = 1;

	char path_name[3][15];
	char path_count[3][7];
	int path_count_int[3];

	//Get data from the file
	for(int i = 1; i <= VALID_OPTIONS; i++){
		if(i <= 7){
	  	fgets(r_path[i],15,stdin);
	  }
	  else if(i <= 14){
	  	fgets(p_time[j],15,stdin);
	    p_time_int[j] = atoi(p_time[j]);
	    j++;
	  }
		else if(i <= 16){
			fgets(path_name[k],15,stdin);
		  k++;
	  }
		else if(i <= 18){
			fgets(path_count[l],15,stdin);
		  path_count_int[l] = atoi(path_count[l]);
		  l++;
		}
	}

	int shortest_time[3] = {0,100,100};
	int longest_time[3] = {0,0,0};
	float average_time[3] = {0,0,0};

	for(int i = 1; i <= path_count_int[1]; i++){
		//Get shortest time for path 1
	  if(p_time_int[i]<shortest_time[1]){
	  	shortest_time[1] = p_time_int[i];
	  }
	  //Get longest time for path 1
	  if(p_time_int[i]>longest_time[1]){
	  	longest_time[1] = p_time_int[i];
	  }
	  //Get average time for path 1
	  average_time[1] = average_time[1] + p_time_int[i];
	}
	for(int i = path_count_int[1]+1; i <= path_count_int[1]+path_count_int[2]; i++){
		//Get shortest time for path 2
	  if(p_time_int[i]<shortest_time[2]){
	  	shortest_time[2] = p_time_int[i];
	  }
	  //Get longest time for path 2
	  if(p_time_int[i]>longest_time[2]){
	  	longest_time[2] = p_time_int[i];
	  }
	  //Get average time for path 2
	  average_time[2] = average_time[2] + p_time_int[i];
	}

	average_time[1] = average_time[1] / path_count_int[1];
	average_time[2] = average_time[2] / path_count_int[2];

	//Print report
	printf("Request path: %s | Number of requests: %d | Shortest time: %d | Longest time: %d | Average time: %.2f\n", path_name[1], path_count_int[1], shortest_time[1], longest_time[1], average_time[1]);
	printf("Request path: %s | Number of requests: %d | Shortest time: %d | Longest time: %d | Average time: %.2f\n", path_name[2], path_count_int[2], shortest_time[2], longest_time[2], average_time[2]);

	return 0;
}
