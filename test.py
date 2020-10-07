
from math import ceil

n = 1234567890

print(len(str(n)))
a = len(str(n))
b= a / 4
print(type(a))
print(type(b))
print(b)
print(int(b))
print(ceil(b))
print(str(b))
print(len(str(b)))
print()

for i in range(int(b)):
    print(10 ** i)
    