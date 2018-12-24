#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int main(void)
{
    //here we create variables that we need
    string key;
    string salt;
    int n;
    string hash_password;
    FILE *shadow;
    string user;

    //it checks that an user has been written right
    do
    {
        n = 0;
        printf("Get user: ");
        user = get_string();
        for (int i = 0; i < strlen(user); i++)
        {
            //Function isalpha from ctype.h checks argument, transmitted via the parameter сharacter, whether it is lowercase or uppercase alphabet.
            if (isalpha(user[i]) == false)
            {
                n++;
            }
        }
    }
    while ((strlen(user) > 10) || (n != 0));
    printf("%s\n", user);

    //we get one password from one to five symbols
    do
    {
        n = 0;
        printf("Get password: ");
        key = get_string();
        for (int i = 0; i < strlen(key); i++)
        {
            if (isalpha(key[i]) == false)
            {
                n++;
            }
        }
    }
    while ((strlen(key) > 5) || (n != 0));
    printf("%s\n", key);

    //we get salt for cryptography
    do
    {
        printf("Get salt for password: ");
        salt = get_string();
    }
    while (strlen(salt) > 2);
    printf("%s\n", salt);

    //we create our hash password
    hash_password = crypt(key, salt);
    printf("%s\n", hash_password);

    //we write our user and created the hash-password into file
    shadow = fopen("shadow.txt", "w");
    fprintf(shadow, "%s:%s", user, hash_password);
    fclose(shadow);

}
