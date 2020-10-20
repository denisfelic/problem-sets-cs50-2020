#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int get_number_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    int text_length = strlen(text);
    char text_letters[text_length];
    int num_sentences = 0;
    int num_words = 0;

    // Get number of letters in the text
    int number_of_letters = get_number_letters(text);

    // GET NUMBER OF SENTENCES
    for (int i = 0; i < text_length; i++)
    {
        text_letters[i] = text[i];

        // check if is sentence
        if (text_letters[i] == '.' ||  text_letters[i] == '!' || text_letters[i] == '?')
        {
            num_sentences++;
        }
    }

    // GET NUMBER OF WORDS
    for (int i = 0 ; i < text_length; i++)
    {
        text_letters[i] = text[i];

        // check if is a word
        if ((text_letters[i] == '.') ||  text_letters[i] == '!' || text_letters[i] == '?' || text_letters[i] == ' ' 
            || text_letters[i] == ',')
        {
            text_letters[i] = '_';

        }

    }

    for (int i = 0 ; i < text_length; i++)
    {

        if (text_letters[i] == '_' && text_letters[i + 1] != '_')
        {
            num_words++;
        }
    }

    float L = ((float) number_of_letters / (float) num_words)  * 100;
    float S = ((float) num_sentences / (float) num_words) * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);

    }



}



// get total of letters including numbers
int get_number_letters(string text)
{
    int text_length = strlen(text);
    int total_of_letters = 0;
    bool is_letter = false;
    bool is_number = false;

    // Add letters only
    for (int i = 0; i < text_length; i++)
    {
        is_letter = ((text[i] > 96) && (text[i] < 123)) || ((text[i] > (96 - 32))
                    && (text[i] < (123 - 32)));   // get letter upper-case or lower-case
        is_number = ((text[i] > 47) && (text[i] < 58));
        if (is_letter || is_number)
        {
            total_of_letters++;
        }
    }

    return total_of_letters;
}

