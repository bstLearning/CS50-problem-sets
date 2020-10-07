import cs50


def main():
    n = number()
    sum = calsd(n) + calfd(n)
    checksum(n, sum, len(str(n)))
    
# get cardnumber from prompt
def number():
    while True:
        n = cs50.get_int("Number: ")
        if n > 0:
            break
    return n
    
# even digits sum (count from second-to-last digit)
def calsd(n):
    sdsum = 0
    for i in range(1, int(len(str(n))/2) + 1):
        d = 100 ** i
        sd = (n % d - n % (d/10)) / (d/10)
        sd *= 2
        if sd >= 10:
            sd = (sd % 100 - sd % 10) / 10 + (sd % 10)
        sdsum += sd
    return sdsum
        
    
# odd digits sum (count from first-to-last digit)
def calfd(n):
    fdsum = 0
    for i in range(int(len(str((n)))/2 + 1)):
        d = 10 * (100 ** i)
        fd = (n % d - n % (d/10)) / (d/10)
        fdsum += fd
    return fdsum

# checksum
def checksum(n, sum, len):
    f2d = (n - n % (10 ** (len-2))) / (10 ** (len-2))  # first 2 digit of cardnumber
    
    if int(sum) % 10 == 0:
        if (f2d == 34 or f2d == 37 ) and len == 15:
            print("AMEX")
        elif 51 <= f2d <= 55 and len == 16:
            print("MASTERCARD")
        elif (f2d - f2d % 10) / 10 == 4 and (len == 13 or len == 16):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
    
    
main()