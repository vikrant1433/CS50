#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool check_agrv (string argv);

int main (int argc, char* argv[])
{   
    if (argc != 2)
    {   
        printf("HOW DARE YOU NOT GIVE ME THE CORRECT NUMBER OF ARGUMENTS!\n");
        return 1;
    }
    if (!check_agrv (argv[1]))
    {   
        printf("Keyword must only contain letters A-Z and a-z\n");
        return 1;
    }
    
    string s = GetString();
        
    int len_argv = strlen(argv[1]);       
    int c, k;
    int cycle = 'a' ^ 'A';
    
    for (int i = 0, j = 0, n = strlen(s); i < n; i++)
    {   j = j % len_argv;
        k = argv[1][j] % cycle ;
        k -= 1;
        c = (s[i] + k);
        if (isalpha(s[i]))
        {
            if (islower(s[i]))
                printf("%c", c > 'z'  ?  (c % 'z') + 'a' - 1 : c );
            else
                printf("%c", c > 'Z'  ?  (c % 'Z') + 'A' - 1 : c );
            j++;
        }
        else
            printf("%c",s[i]);
    }

    printf("\n");
    return 0;

}

bool check_agrv(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
        if (!(isalpha(s[i])))
            return false;
         
    return true;

}


