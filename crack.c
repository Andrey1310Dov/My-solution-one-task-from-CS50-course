#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    //we check if a hash has been typed in correctly
    if (argc != 2)
    {
        printf("Usage: ./crack hash \n");
        return 1;
    }
    else
    {
        //we create variables that we need
        char salt[3];
        string hash_1;
        hash_1 = argv[1];
        //The function copies the first num characters from a string srcptr in line destptr.
        strncpy(salt, argv[1], sizeof(salt) - 1);
        string hash_check;

        //we create string contained all letters of the alphabet (upper-case and lower-case letters)
        string all = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        //we allocate memory for our password
        char password[6];

        //we search our password with brute force way
        //search the first letter
        for (int i = 0; i < strlen(all); i++)
        {
            password[0] = all[i];
            password[1] = '\0';
            //crypt() is the library function which is used to compute a password hash (we get with unistd.h and _XOPEN_SOURCE)
            hash_check = crypt(password, salt);
            //This feature compares the characters of two strings, string1 and string2.
            if (strcmp(hash_1, hash_check) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
        }

        //search the second letter
        for (int i = 0; i < strlen(all); i++)
        {
            password[0] = all[i];
            for (int j = 0; j < strlen(all); j++)
            {
                password[1] = all[j];
                password[2] = '\0';
                hash_check = crypt(password, salt);
                if (strcmp(hash_1, hash_check) == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
            }
        }

        //search the third letter
        for (int i = 0; i < strlen(all); i++)
        {
            password[0] = all[i];
            for (int j = 0; j < strlen(all); j++)
            {
                password[1] = all[j];
                for (int z = 0; z < strlen(all); z++)
                {
                    password[2] = all[z];
                    password[3] = '\0';
                    hash_check = crypt(password, salt);
                    if (strcmp(hash_1, hash_check) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                }
            }
        }

        //search the fourth letter
        for (int i = 0; i < strlen(all); i++)
        {
            password[0] = all[i];
            for (int j = 0; j < strlen(all); j++)
            {
                password[1] = all[j];
                for (int z = 0; z < strlen(all); z++)
                {
                    password[2] = all[z];
                    for (int d = 0; d < strlen(all); d++)
                    {
                        password[3] = all[d];
                        password[4] = '\0';
                        hash_check = crypt(password, salt);
                        if (strcmp(hash_1, hash_check) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }

        //search the fifth letter
        for (int i = 0; i < strlen(all); i++)
        {
            password[0] = all[i];
            for (int j = 0; j < strlen(all); j++)
            {
                password[1] = all[j];
                for (int z = 0; z < strlen(all); z++)
                {
                    password[2] = all[z];
                    for (int d = 0; d < strlen(all); d++)
                    {
                        password[3] = all[d];
                        for (int a = 0; a < strlen(all); a++)
                        {
                            password[4] = all[a];
                            password[5] = '\0';
                            hash_check = crypt(password, salt);
                            if (strcmp(hash_1, hash_check) == 0)
                            {
                                printf("%s\n", password);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    //we will create a message, if we fail in object
    printf("Your hash is not correct!\n");
    return 1;
}

