#include "read_csv.h"
#include<stdio.h>
#include<stdlib.h>


void read_csv(const char* csv_filename){
    FILE* inputfile = fopen(csv_filename,"rt");  
    if (inputfile==NULL){     
        return;
    } 

    char currentline [1000]; 

    fgets(currentline,999,inputfile);

    while (!feof(inputfile)){    

        puts(currentline);
        fgets(currentline,999,inputfile);

    }

    fclose(inputfile);  

}

