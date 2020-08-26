#include <cs50.h>
#include <stdio.h>

int get_height(void);
void pyramid(int h);

int main(void)
{
    int h = get_height();
    void pyramid(int h);
}


int get_height(void)
{
    int n;
    do
    {
       n = get_int("Height: ");
    }
    while (n<0 || n>8);
    return n;
}


void pyramid(int h)
{
    for(int i = 0; i <= 9; i++)
    {
        printf("#*%i  #*%i\n", i, i);
    }
}