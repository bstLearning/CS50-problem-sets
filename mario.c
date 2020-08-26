#include <cs50.h>
#include <stdio.h>

int get_height(void);
void pyramid(int h);

int main(void)
{
    int h = get_height();
    for(int i = 1; i <= h; i++)
    {
        string space = " ";
        int spacenumber = h-i;
        for(int sn = 1; sn <= h-i; sn++) /// sn for space number
        {
            printf("%s", space);
        }
        for(int ls = 1; ls <= i; ls++) /// ls for number of left sharp
        {
            printf("#");
        }
        printf("  ");
        for(int rs = 1; rs <= i; rs++) ///rs for number of right sharp
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    int n;
    do
    {
       n = get_int("Height: ");
    }
    while (n<=0 || n>8);
    return n;
}
