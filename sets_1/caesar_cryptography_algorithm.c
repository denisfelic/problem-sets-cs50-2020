#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


bool check_arg(string arg);
int apply_cryptography(char ascii_char, int key, bool upper_case);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool arg_is_valid = check_arg(argv[1]);

        // NOT VALID
        if (arg_is_valid == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // BEGIN
        int key = atoi(argv[1]);
        printf("%i \n", key);

        string plain_text = get_string("plaintext: ");
        int plain_text_length = strlen(plain_text);
        char plain_text_chars [plain_text_length];

        // Fill plain_txt_chars
        for (int i = 0; i < plain_text_length; i++)
        {
            plain_text_chars[i] = plain_text[i];
        }


        // Apply key and fill cipher[]
        char cipher[plain_text_length];
        int key_value_int = 0;
        char key_value_char = '!';

        printf("ciphertext: ");
        
        for (int i = 0; i < plain_text_length; i++)
        {

            // UPPER CASE
            if (plain_text_chars[i] > 64 && plain_text_chars[i] < 91)
            {
                cipher[i] = apply_cryptography(plain_text_chars[i], key, true);

            }
            // LOWER CASE
            else if (plain_text_chars[i] > 96 && plain_text_chars[i] < 123)
            {
                cipher[i] = apply_cryptography(plain_text_chars[i], key, false);
            }
            // NOT APPLY Criptography
            else
            {
                cipher[i] = plain_text_chars[i];
            }
            printf("%c", cipher[i]);
        }

        printf("\n");

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Check if arg is valid  ( POSITIVE INTEGER ONLY )
bool check_arg(string arg)
{
    bool is_valid = false;

    for (int i = 0; i < strlen(arg); i++)
    {
        if (arg[i] > 47 && arg[i] < 58)
        {
            is_valid = true;
        }
        else
        {
            is_valid = false;
            break;
        }
    }

    return is_valid;
}


int apply_cryptography(char ascii_char, int key, bool upper_case)
{
    int alph_char_pos = 0;
    int cipher_position = 0;
    int ascii_char_pos = 0;
     
    if (upper_case == true)
    {
        // Convert ascii to alphabetical char position: Ex. A=0, B=1, C=2...
        alph_char_pos = ascii_char - 65;
        cipher_position = (alph_char_pos + key) % 26;
        ascii_char_pos = 65 + cipher_position;
        return ascii_char_pos;
    }
    else 
    {
        alph_char_pos = ascii_char - 97;
        cipher_position = (alph_char_pos + key) % 26;
        ascii_char_pos = 97 + cipher_position;
        return ascii_char_pos;
    }
}