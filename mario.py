import cs50


def main():
    pyramid()
    
    
def pyramid():
    while True:
        h = cs50.get_int("Height: ")
        if 0 < h < 9:
            break
    
    for i in range(1, h+1):
        spacenumber = h-i
        print(" " * spacenumber + "#" * i + "  " + "#" * i)


main()

# feedback from sytle50
# Looks good!
# But consider adding more comments!