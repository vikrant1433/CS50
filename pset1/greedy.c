#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{

    float dollar;
    
    do
    {
       printf("How much change is owed?\n");
       dollar= GetFloat(); 
    }
    while(dollar<0);
    
    int cents;
    cents =(int)round(dollar * 100);
    // printf("%f\n",cents);
    
    int coins = 0;
    // subtracting 25 from  cents to count the number of 25 cent coins
    while(cents >=25)
    {   
        coins += 1;
        cents -= 25;
    
    }
    // subtracting 10 from  cents to count the number of 10 cent coins
    while(cents >= 10)
    {
        coins += 1;
        cents -= 10;
    }
    // subtracting 5 from  cents to count the number of 5 cent coins
    while(cents >= 5)
    {
        coins += 1;
        cents -= 5;
    }
    // subtracting 1 from  cents to count the number of 1 cent coins
    while(cents >= 1)
    {
        coins += 1;
        cents -= 1;
    }
    printf("%d\n",coins);
    
    return 0;

}

