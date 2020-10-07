import cs50 


while True:
    h = cs50.get_int("Height: ")
    if 0 < h < 9:
        break

for i in range(1, h+1):
    spacenumber = h+1-i
    print(" " * spacenumber + "#" * i + "  " + "#" * i)

## feedback from sytle50
## Looks good!
## But consider adding more comments!