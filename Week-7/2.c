#include <stdio.h>
#include <string.h>

int main()
{
    FILE *in;
    in = fopen("/Users/danielgehrman/Documents/Programming/Uni/Sem-1-NSU/Week-7/input.txt", "r");

   if(in == NULL) {
      perror("Error in opening file");
      return(-1);
   }


    char word[100], ansWord[100], c;

    int len = 0, maxLen = 0;

    fscanf(in, "%s", &c);

    while (c != '.')
    {
        printf("%c", c);
        break;
        // if(c == ',')
        // {
        //     if (len > maxLen)
        //     {
        //         memcpy(ansWord, word, sizeof(word));
        //         memset(word, '\0', sizeof(word));
        //         maxLen = len;
        //     }

        //     fscanf(in, "%s", &c);
        //     continue;
        // }

        // word[len] = c;
        // len++;

        // fscanf(in, "%s", &c);
    }

    fclose(in);

    // printf("%d\n", maxLen);
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%c", ansWord[i]);
    // }
    // printf("\n");

    return 0;
}