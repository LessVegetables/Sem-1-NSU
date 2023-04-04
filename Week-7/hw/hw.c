// HW due 29.03.2023
// 1. Create a new file
// 2. Copy into the new file text from the given file excluding comments: /* ... */
// Note: /*, *, / are to be coppied too

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *input, *output;

    if ((input = fopen("input.txt","r")) == NULL){
       printf("Error opening file\n");
       exit(1);
       // Program exits if the file pointer returns NULL.
    }
    if ((output = fopen("output.txt","w")) == NULL){
       printf("Error creating file\n");
       exit(1);
       // Program exits if the file pointer returns NULL.
    }

    





    return 0;
}