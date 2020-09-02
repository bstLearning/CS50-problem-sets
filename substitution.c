#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int key_val(int c, string v);
int encipher(string pt, string v);

int main(int argc, string argv[])
{
    if (key_val(argc, argv[1]) == 0) /// if val == 0 then validated key value
    {
        printf("%s\n", "Enciphering.");  
        
        string pt = get_string("plaintext: ");
        encipher(pt, argv[1]);
    }
    else if (key_val(argc, argv[1]) != 0)
    {
        printf("%s\n", "Usage: ./substitution key");
    }
}


/// Validate the Key
int key_val(int c, string v)
{
    if (c == 1)
    {
        printf("%s\n", "Usage: ./substitution key");
        return 1;
    }
    else if (c == 2)
    {
        int checker = 0;
        for (int i = 0, n = strlen(v); i < n; i++)
        {
            if (isalpha(v[i]) != 0) /// zero if not isalpha
            {
                checker +=  1;   
            }
        }
        if (checker != 26)
        {
            printf("%s\n", "Key must contain 26 characters.");
            return 1;
        }
        else if (checker == 26)
        {
            int checker2 = 0; //// check if repeated char in the array of string
            for (int i = 0, n = strlen(v); i < n; i++) //// but how to show caseinsensitive? 
            {
                for (int x = 0; x < n; x++)
                {
                    if (toupper(v[x]) == toupper(v[i])) /// case-insensitive
                    {
                        checker2 += 1;
                    }
                }
            }
            if (checker2 > strlen(v)) /// if checker2 > strlen(ca), repeated char in the array ca. 
            {
                printf("%s\n", "Key must contain 26 characters."); 
                return 1;
            }
            return 0; //////////// valided succesccfully 
        }
    }
    return 1;
}


/// Encipher. determine what letter it maps to (preserve case, leave non char)
int encipher(string pt, string v) /// plain text, string argv[1] as intput, cipher text as output
{
    ///A 65 , a 97,  for pt[i]. if uppercase then..., else if lowercase then...., else if number then ... else if blank, period...
    for (int i = 0; i < strlen(pt); i++)
    {
        if (isupper(pt[i]))
        {
            int n = (int)pt[i] - 65;
            printf("%c", toupper(v[n])); 
        }
        else if (islower(pt[i]))
        {
            int n = (int)pt[i] - 97;
            printf("%c", tolower(v[n]));
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
    return 0;
}
