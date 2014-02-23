#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    int height;

    
    // prompt user untill height is between 1 and 23
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height > 23 || height < 0);
    
    for (int i = 0; i < height; i++)    // loop for number of rows
    {
        for (int j = height; j > (i+1); j--)    //loop for 
        {
            printf(" ");
        }
        for (int k = -2; k < i; k++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    
    return 0;


}

