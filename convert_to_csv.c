#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int boolean;

void load_and_convert (const char* filename){

    FILE* inputfile = fopen(filename,"rt");  

    if (inputfile==NULL){    
        return;
    } 

    char Name [1000];      
    char Age [1000];       
    char Place[1000];      

    fgets(Name,999,inputfile);     
    fgets(Age,999,inputfile);      
    fgets(Place,999,inputfile);    

    fclose(inputfile);   

    FILE* outfile = fopen ("output.csv","wt");    

    int index1=0;   
    int index2=0;   
    int index3=0;   

    while (TRUE) {      

        while ( isspace(Name[index1])){    
            index1++;
        }  

        if (Name[index1]=='\0'){    
            break;
        }

      
        for (;isalpha(Name[index1]);index1++){   
            fputc(Name[index1],outfile);             

        }

        fprintf (outfile,", ");

        while ( isspace(Age[index2])){    
            index2++;
        }  

        for (;isdigit(Age[index2]);index2++){  
            fputc(Age[index2] , outfile);         
        }

        fprintf (outfile,", "); 

        while ( isspace(Place[index3])){      
            index3++;
        }    

        for (;(isalpha(Place[index3]) || Place[index3]=='-');index3++){   
            fputc(Place[index3], outfile);                                       
        }
        
        fputc('\n' , outfile);

    }

    fclose (outfile);

}

