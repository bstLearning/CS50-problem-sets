#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //////// get cardnumber from prompt ////////
    long cardnumber;
    do
    {
        cardnumber = get_long("Number: ");
    }
    while (cardnumber < 0);
    
    /////// calculate checksum ///////
    long checksum = 0;
    int length = 0;
    int first2digit = 0;
    long cnd = 0;  /// card number second-to-last digit 
    long cndf = 0; /// card number first-to-last digit 
    
    for (long d = 100; d < cardnumber*10; d *= 100) //iterate start from the second-to-last digit
    {
        cnd = ((cardnumber%d - cardnumber%(d/10)) / (d/10))*2;
        length += 1;
        /// printf("Digit: %li\n", cnd);
        if (cnd >= 10)
        {
            cnd = (cnd%100 - cnd%10) / 10 + (cnd%10);
            checksum += cnd;
        }
        else if (cnd < 10 )
        {
            checksum += cnd;
        }
        
    }
    /// printf("%li\n\n", checksum);
    
    for (long df = 10; df < cardnumber*10; df *= 100) //start fro the first-to-last digit
    {
        length += 1;
        cndf = ((cardnumber%df - cardnumber%(df/10)) / (df/10));
        /// printf("cndf= %li\n", cndf);
        checksum += cndf;
        /// printf("%li\n", checksum);
    }
    ///printf("Length: %i\n", length); ////// get lentgh plus one after evert loop
 
    ////// Check for card lentgh to catagorize wich card belong and validate accordingly ///////
    if (checksum % 10 == 0) /// valid number
    {
        if (length % 2 == 0)
        {
            first2digit += cnd/2 * 10 + cndf;
        }
        else if (length % 2 == 1)
        {
            first2digit += cndf * 10 + cnd;
        }
        
        ///printf ("%i\n", first2digit);
        
        if (length == 15 && (first2digit == 34 || first2digit == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && 51 <= first2digit && first2digit <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (first2digit - (first2digit % 10))/10  == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


void checksum(void)
{
    
}