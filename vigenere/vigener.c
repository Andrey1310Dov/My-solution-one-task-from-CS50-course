#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])

{
    //we checks if a key has been typed in in correctly
    if (argc != 2)
    {
        printf("Print the key the next time \n");
        return 1;
    }
    else
    {
        //we checks if a key has been typed in in correctly
        string key = argv[1];
        for (int z = 0; z < strlen(key); z++)
        {
            //Function isalpha from ctype.h checks argument, transmitted via the parameter сharacter, whether it is lowercase or uppercase alphabet.
            if (isalpha(key[z]) == false)
            {
                printf("Print the key the next time \n");
                return 1;
            }
        }
        //we type in our plaintext
        printf("plaintext: ");
        string text = get_string();
        //we get our cipher with the cycle for
        printf("ciphertext: ");
        for (int i = 0, b = 0, n = strlen(text), k; i < n; i++, b++)
        {
            if (b > (strlen(key) - 1))
            {
                b = 0;
            }
            int k_0 = key[b];
            //Function isupper check symbol, transmitted via the parameter, whether it is uppercase.
            if (isupper(key[b]))
            {
                k = k_0 - 65;
            }
            else
            {
                k = k_0 - 97;
            }
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    int letter = text[i];
                    int letter_2 = letter - 65;
                    int result_2 = (letter_2 + k) % 26;
                    int result = result_2 + 65;
                    printf("%c", result);
                }
                else
                {
                    int letter = text[i];
                    int letter_2 = letter - 97;
                    int result_2 = (letter_2 + k) % 26;
                    int result = result_2 + 97;
                    printf("%c", result);
                }
            }
            else
            {
                printf("%c", text[i]);
                b--;
            }
        }
        printf("\n");
        return 0;
    }
}
