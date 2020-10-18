#include <stdio.h>
#include <cs50.h>
#include <math.h>

int check_result(int result, int total_digits, int first_digit, int second_digit);
int get_digit_at_index(int index, long last_digit, int count);
int main(void)
{
    long card_number = get_long("Number: ");
    long card_number_original = card_number;
    int last_digit = 0;
    int count = 0;
    int current_digit = 0;
    int digit_sum = 0;
    int num_rests = 0;
    int second_digit = 0;
 
    // Running all digits
    while (card_number != 0)
    {
        last_digit = card_number % 10;
        card_number =  round(card_number / 10);  

        // ignore last digit and go in two in two
        if (count > 0 && count % 2 != 0)
        {
            current_digit = (2 * last_digit);

            if (current_digit < 9)
            {
                digit_sum += current_digit;
            }
            
            // have two digits, need to separe they
            if (current_digit > 9)
            {
                int helper = current_digit;
                int c = current_digit;
                while (helper > 0)
                {
                    helper = round(helper / 10);
                    c = current_digit % 10;
                    current_digit = helper;
                    digit_sum += c;
                }

            }

        }
        else 
        {
            // other numbers 
            num_rests += last_digit;
        }

        count++;
    }
    // result of sum
    int result = (digit_sum + num_rests) % 10;
    
    // get second digit 
    second_digit = get_digit_at_index(2, card_number_original, count);

    // check if credit card number is valid, and match with this flag
    check_result(result, count, last_digit, second_digit);
   
}

int check_result(int result, int total_digits, int first_digit, int second_digit)
{
    int VALID_CARD = 0;
    if (result != VALID_CARD)
    {
        printf("INVALID\n");
        return -1;
    }
    // VISA
    if ((total_digits == 13 || total_digits == 16) && first_digit == 4)
    {
        printf("VISA\n");
        return 0;
    }
    // AMERICAN EXPRESS
    if (total_digits == 15)
    {
        if ((first_digit == 3 && second_digit == 4) || (first_digit == 3 && second_digit == 7))
        {
            printf("AMEX\n");
            return 0;
        }
    }
    // MASTERCARD
    if (total_digits == 16)
    {
        // START WITH 51
        if (first_digit == 5 && second_digit == 1)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // 52
        else if (first_digit == 5 && second_digit == 2)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // 53
        else if (first_digit == 5 && second_digit == 3)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // 54
        else if (first_digit == 5 && second_digit == 4)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // 55
        else if (first_digit == 5 && second_digit == 5)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    printf("INVALID\n");
    return 0;
}

int get_digit_at_index(int index, long credit_card_digits, int count)
{
    int digit_at_index = 0;
    int d_digit = 0;
    while (credit_card_digits != 0)
    {
        digit_at_index = credit_card_digits % 10;
        credit_card_digits =  round(credit_card_digits / 10);  
        d_digit = credit_card_digits;
        if (count == 2)
        {
            return digit_at_index;
            break;
        }
        count--;
    }
    return -1;
}
