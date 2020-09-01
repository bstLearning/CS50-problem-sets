#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/// index = 0.0588 * L - 0.296 * S - 15.8

int letters_counter(string s);
int words_counter(string s);
int sentences_counter(string s);
float grade(int letters, int words, int sentences);

int main(void)
{
    string s = get_string("Text: ");  
    int letters = letters_counter(s);
    int words = words_counter(s);
    int sentences = sentences_counter(s);
    
    float G = grade(letters, words, sentences);
    if (G > 16)
    {
        printf("Grade 16+\n");
    }
    else if (G < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", G);
    }
    
}


int letters_counter(string s)
{
    int letters = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalnum(s[i]) != 0) /// ceheck if alpahnumeric
        {
            letters += 1;
        }
    }
    return letters;
}

int words_counter(string s)
{
    int words = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isblank(s[i]) != 0) /// ceheck if a blank, tab or so
        {
            words += 1;
        }
    }
    words += 1;
    return words;
}

int sentences_counter(string s)
{
    int sentences = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '!' || s[i] == '.' || s[i] == '?')  /// ceheck if a ! . or ?
        {
            sentences += 1;
        }
    }
    return sentences;
}



float grade(int letters, int words, int sentences)
{
    float L = (float)letters / (float)words*100;
    float S = (float)sentences / (float)words*100;
    float G = 0.0588 * L - 0.296 * S - 15.8;
    return G;
}
