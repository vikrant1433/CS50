#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main (int argc, char* argv[])
{   
  
    if (argc != 2)
    {   
        printf("HOW DARE YOU NOT GIVE ME THE CORRECT NUMBER OF ARGUMENTS!\n");
        return 1;
    }    
    
    int k = atoi(argv[1]);
    


    string s = GetString();
    int c;
    for (int i = 0, n = strlen(s); i < n; i++)
    {   
        c = (s[i] + (k % 26));
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
                printf("%c", c > 'z'  ?  (c % 'z') + 'a' - 1 : c );
            else
                printf("%c", c > 'Z'  ?  (c % 'Z') + 'A' - 1 : c );
            
        }
        else
            printf("%c",s[i]);
    }

    printf("\n");

    return 0;

}
