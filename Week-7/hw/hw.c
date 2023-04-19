// HW due 29.03.2023
// 1. Create a new file
// 2. Copy into the new file text from the given file excluding comments: /* ... */
// Note: /*, *, / are to be coppied too

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printString(char* a, FILE* output)
{
   for (int i = 0; i < 100; i++)
   {
      if (a[i] == '~')
      {
         return;
      }
      fprintf(output, "%c", a[i]);
   }
}
void clearString(char* a)
{
   for (int i = 0; i < 100; i++)
   {
      a[i] = '~';
   }
}
void addString(char* a, char inp)
{
   printf("its fucking stuck in here\n");
   int i = 0;
   while(1)
   {
      if (a[i] == '~')
      {
         a[i] = inp;
         break;
      }
   }
   return;
}

int main()
{
   FILE *input, *output;

   if ((input = fopen("/Users/danielgehrman/Documents/Programming/Uni/Sem-1-NSU/Week-7/hw/input.txt","r")) == NULL)
   {
      printf("Error opening file\n");
      exit(1);
      // Program exits if the file pointer returns NULL.
   }
   if ((output = fopen("/Users/danielgehrman/Documents/Programming/Uni/Sem-1-NSU/Week-7/hw/output.txt","w")) == NULL)
   {
      printf("Error creating file\n");
      exit(1);
      // Program exits if the file pointer returns NULL.
   }

   char inp;
   char onHold[100]; // very lazy/bad/outRightTerrible aproach for using a fixed length array. Should insted be using a dynamic array.
   clearString(onHold); // even lazyer aproach, plz do not bring this up on the interview, i can do better

   fscanf(input, "%c", &inp);

   int holding = 0;
   int commentWarning = 0; // when (holding) — turns true when we se
   int commentStart = 0;


   while (inp)
   {
      if (!holding)
      {
         printf("looping hold = 0...\n");
         if (inp == ((char)92))
         {
            printf("HOOOOLD\n");
            holding = 1;
            addString(onHold, inp); //add inp element into the onHold string array
            commentWarning = 1;
         }
         else
         {
            printf("adding to output\n");
            fprintf(output, "%c", inp);
         }
      }
      else
      {
         printf("looping hold = 1...\n");
         if (commentStart)
         {
            if(inp == '*')
            {
               commentWarning = 1;
            }
            
            if (commentWarning)
            {
               if (inp == ((char)92))
               {
                  commentStart = 0;
                  commentWarning = 0;
                  clearString(onHold); // empty the onHold string array
               }
               else
               {
                  commentWarning = 0;
               }
            }
         }

         if (commentWarning)
         {
            if (inp == '*')
            {
               commentStart = 1;
               commentWarning = 0;
            }
            else
            {
               commentWarning = 0;
               holding = 0;
               printString(onHold, output);// add onHold string array into the output file
               clearString(onHold); // empty the onHold string array
            }
         }
      }

      fscanf(input, "%c", &inp);

      printf("looping 0...\n");
   }

   fclose(input);
   fclose(output);

   return 0;
}