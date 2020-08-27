#include <stdio.h>
#include <cs50.h>

long number(void);
long calsd(long cardnumber);
long calfd(long cardnumber);
long length(long cardnumber);
void checksum(long n, int sum, int len);

int main(void)
{
    long n = number();
   
    long cal2 = calsd(n);
    long cal1 = calfd(n);
    long sum = cal2 + cal1;
    
    long len = length(n);
   
    checksum(n, sum, len);
    
}


/// get cardnumber from prompt 
long number(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);
    return n;
}

/// even digits sum
long calsd(long cardnumber)
{
    long sd; ///the second-to-last digit
    long sdsum = 0; /// sum of the digits
    
    for (long d = 100; d < cardnumber * 10; d *= 100) ///Plus every other digits by2, starting from the second-to-last digit
    {
        sd = (cardnumber % d - cardnumber % ( d / 10 )) / (d / 10);
        sd *= 2;
        if (sd >= 10)
        {
            sd = (sd % 100 - sd % 10) / 10 + (sd % 10);
        }
        sdsum += sd;
    }
    return sdsum;
}

/// odd digits sum
long calfd(long cardnumber)
{
    long fd; ///the first-to-last digit
    long fdsum = 0; /// sum of the digits  
    
    for (long d = 10; d < cardnumber * 10; d *= 100) ///Plus every other digits by2, starting from the first-to-last digit
    {
        fd = ((cardnumber % d - cardnumber % (d/10)) / (d/10));
        fdsum += fd;
    }
    return fdsum;
}


/// check length of the cardnumber, unconsidet those start with 0, 00, 000 or so 
long length(long cardnumber)
{
    long len = 0;
    for (long d = 1; d < cardnumber; d *= 10)
    {
        len += 1;
    }
    return len;
}



/// checksum
void checksum(long n, int sum, int len)
{
    long f2d; /// first 2 digit
    long pwr = 1;
    for (int i = 0; i < len - 2; i++) /// 10 to the power of len-2
    {
        pwr *= 10;
    }
    f2d = (n - (n % pwr)) / pwr; /// get first 2 digit of cardnumber
    

    
    
    if (sum % 10 == 0)
    {
        if ((f2d == 34 || f2d == 37) && len == 15)
        {
            printf("AMEX\n");
        }
        else if (51 <= f2d && f2d <= 55 && len == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((f2d - (f2d % 10)) / 10 == 4 && (len == 13 || len == 16))
        {
            printf("VISA\n");
        }
        else printf("INVALID\n");
    }
    else printf("INVALID\n");
}