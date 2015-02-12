#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main (int argc, char* argv[]){

  FILE *file;
  char line [1024];
  char *data;
  char *delim = ',';
  int total; int numData; double average;

  //Check for proper input
  if (argc != 2){
    printf("Argument error. Enter expAvg.c file_name\n");
    return;
  }
  
  //Open file_name
  file = fopen(argv[1], "rt");
  if (file == NULL){
    printf("Error opening file.\n");
    return;
  }
  
  //Loop through each line and calculate the average assuming file is formatted:
  //exp_name1,data1,data2,data3,...
  //exp_name2,data1,data2,data3,...
  while (!feof(file)){
    total = 0; //sum of data fields
    numData = 0; // number of data fields
    if (fgets(line, 1024, file) != NULL){ 
        data = strtok(line, delim);
        printf("%s", data); //print name of experiment
        while (data=strtok(NULL,delim)){
          numData ++; //count number of data fields
          total = total + atoi(data); //accumulate data fields
        }
        average = total/numData; //calculate average
        average = ceil(average*100)/100; //round average upwards to the nearest 0.01
        printf(" %.2f\n", average); //print average to two decimal places
    }
  }
  fclose(file);
}
