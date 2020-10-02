#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        printf("%s\n", "Usage: ./recover image");
        return 1;
    }

    // Open file
    FILE *f = fopen(argv[1], "r");
    if (!f)
        {return 1;}
    
    // counter of i'th JPEG, index of i'th byte that srart the first JPEG
    int counter = 0;
    int starter = 0;    
    
    FILE *img = NULL;
    
    
    // Read 512 bytes into a buffer 
    // char *buffer = malloc(sizeof(char)*512);
    BYTE *buffer = malloc(sizeof(BYTE) * 512);   //// >>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<    or typedef uint8_t BYTE;

    while(fread(buffer, sizeof(BYTE), 512, f) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // bitwise arithmetic
            {
                // Makeing a new JPEG, filenames: ###.jpg
                char filename[8];
                sprintf(filename, "%03i.jpg", counter);  // print not to a terminal, but a string "filename". print 002.jpg/NULL
                
                // if first JPEG
                if (starter == 0)
                {
                    // open a new file (img) and write in the first JPEG
                    img = fopen(filename, "w");
                    if (!img)
                         {return 3;}
                    fwrite(buffer, sizeof(BYTE), 512, img);
                    starter ++;
                    counter ++;
                }
                // if not first JPEG
                else 
                {
                    fclose(img);
                    img = fopen(filename, "w");
                    if (!img)
                        {return 3;}
                    fwrite(buffer, sizeof(BYTE), 512, img);
                    counter ++;
                }
            }
        else if (starter != 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }
    fclose(img);
    free(buffer);
    fclose(f);
}