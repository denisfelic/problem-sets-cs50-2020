#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (argc == 2 && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else 
    {
        string key = argv[1];
        int key_length = strlen(key);
        char key_arr[key_length];
        
        // validade key
        for (int i = 0; i < key_length; i++)
        {
            if ((key[i] > 96 && key[i] < 123) || (key[i] > 64 && key[i] < 91))
            {
                key_arr[i] = key[i];
            }
            else
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
        
        // verify if have duplicated elements
        int qtd_equals = 0;
        for (int i = 0; i < key_length; i++)
        {
            for (int j = 0; j < key_length; j++)
            {
                if (key_arr[i] == key_arr[j] && i != j)
                {
                    qtd_equals++;
                }
                if (qtd_equals > 1)
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }
                
        
        
        
        
        string plain_text = get_string("plaintext: ");
        int text_length = strlen(plain_text);
        char cipher[text_length];
        printf("ciphertext: ");
        
        for (int i = 0; i < text_length; i++)
        {
            // LOWERCASE
            if (plain_text[i] > 96 && plain_text[i] < 123)
            {      
                cipher[i] = plain_text[i];
                int index_alph_of_ascii = cipher[i] - 97;
                cipher[i] = tolower(key_arr[index_alph_of_ascii]);
            }
            // UPPERCASE
            else if (plain_text[i] > 64 && plain_text[i] < 91)
            {
                cipher[i] = plain_text[i];
                int index_alph_of_ascii = cipher[i] - 65;
                cipher[i] = toupper(key_arr[index_alph_of_ascii]);
            }
            // NON-ALPHABETIC
            else
            {
                cipher[i] = plain_text[i];
            }
            
            printf("%c", cipher[i]);
        }
        printf("\n");
        return 0;
    }
    return 1;
}

