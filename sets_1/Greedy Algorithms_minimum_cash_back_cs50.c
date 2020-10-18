#include <stdio.h>
#include <cs50.h>
#include <math.h>

int user_input(void);

int main(void)
{ 
    int cents = user_input();
    printf("%i\n", cents);

    int QUARTER = 25;
    int DIMES = 10;
    int NICKLES = 5;
    int PENNIES = 1;

    int total_coins = 0;

    while(cents >= 1)
    {
        // 25C - QUARTER
        while(cents >= QUARTER)
        {
            cents = cents - QUARTER;
            total_coins++;
            printf("Total Cents: %i | -25C | Cents: %i \n", total_coins, cents);

        }

        // 10C - DIMES
        while(cents >= DIMES)
        {
            cents = cents - DIMES;
            total_coins++;
            printf("Total Cents: %i | -10C | Cents: %i \n", total_coins, cents);

        }

        // 5C - NICKLES
        while(cents >= NICKLES)
        {
            cents = cents - NICKLES;
            total_coins++;
            printf("Total Cents: %i | -5C | Cents: %i \n", total_coins, cents);

        }

        // 1C - PENNIES
        while(cents >= PENNIES)
        {
            cents = cents - PENNIES;
            total_coins++;
            printf("Total Cents: %i | -1C | Cents: %i \n", total_coins, cents);

        }
    }

    
    printf("END| Cents: %i | Rest: %i \n", total_coins, cents);
}

int user_input(void)
{
    float change; 
    do
    {
        change =  get_float("Change Owed: ");
    }
    while(change < 0);
    int cents = round(change * 100);
    return cents;
}

