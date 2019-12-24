#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"convert_to_csv.h"

#include"read_csv.h"



void find_name(const char* csv_filename, const char* name) {
 FILE* inputfile = fopen(csv_filename,"rt"); 

    if (inputfile==NULL || feof(inputfile)){     
        return;
    } 

    char currentline [1000];     

    fgets(currentline,999,inputfile);
int counter=0;

    while (!feof(inputfile)) {

        boolean isequal = TRUE;            

        for(int i = 0; i < strlen(name); i++)  
        {
            if (tolower(currentline[i])!=tolower(name[i])){

                isequal=FALSE;
                break;
            }
        }

        if (isequal && currentline[strlen(name)]==','){   
            puts (currentline);
	    counter = 1;
        }
    
 
        fgets(currentline,999,inputfile);

    }
    if (counter!=1){
	    printf("NAME NOT FOUND\n");
    }
    

    fclose(inputfile);
}

void add_record(const char* csv_filename, const char*name, const int age, const char* city) {
	FILE* inputfile = fopen(csv_filename,"at"); 

    if (inputfile==NULL){     
        return;
    } 

    fprintf(inputfile,"%s, %d, %s\n",name,age,city); 

    fclose(inputfile);

}

void delete_record(const char* csv_filename, const char* name){


    FILE* inputfile = fopen(csv_filename,"rt");  
    char currentline[100];  

    char longerline[10000]; 

    longerline[0]='\0';  

    if (inputfile==NULL){    
        return;
    } 

    fgets(currentline,999,inputfile);

    boolean found=FALSE;   

    while (!feof(inputfile)){    

        int i=0;
        
        for(; i < strlen(name) && (found==FALSE); i++)  
        {
            if (tolower(currentline[i])!=tolower(name[i])){  
                break;
            }
        }

        if (i==strlen(name) && currentline[i]==','){ 
            found=TRUE;
        } else {
            strcat(longerline,currentline);   
        }

        fgets(currentline,999,inputfile);
    }

    fclose(inputfile);   

    inputfile = fopen(csv_filename,"wt");  

    fprintf(inputfile,"%s",longerline);   

    fclose(inputfile);   

}

int main(){
/* Question 1 */
printf("%s\n","Question 1: ");
load_and_convert("input.txt");
/* Question 2 */
  printf("%s\n","Question 2: ");
  read_csv("output.csv");
/* Question 3.1 */
  printf("%s\n","Question 3.1: ");
  find_name("output.csv", "Maria");
  find_name("output.csv", "Jason"); //Jason doesn't exist
/* Question 3.2 */
  printf("%s\n","Question 3.2: ");
  add_record("output.csv", "Jason", 36, "Skookumchuk");
  read_csv("output.csv"); // to print to the screen
/* Question 3.3 */
  printf("%s\n","Question 3.3: ");
  delete_record("output.csv", "Maria");
  read_csv("output.csv"); // to print to the screen
return 0;
}

