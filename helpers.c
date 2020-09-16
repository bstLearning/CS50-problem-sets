#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int arv = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = arv;
            image[i][j].rgbtGreen = arv;
            image[i][j].rgbtRed = arv;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) // left part of the img
        {
            /// tmp[i][j] = image[i][width/2-(j-width/2)];
            tmp[i][j] = image[i][width - 1 - j];
        }
        for (int k = 0; k < width; k++ ) // right part of the img
        {
            image[i][k] = tmp[i][k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) 
        {
            long sumBlue = 0, sumGreen = 0, sumRed = 0;
            int counter = 0;

            for (int k = -1; k <= 1; k++) // adjacent nine pixels that form a 3x3 box around the pixel
                {
                    for (int n = -1; n <= 1; n++)
                        {
                            if (i + k < 0 || i + k >= height || j + n < 0 || j + n >= width) /// pixle on edge and corner of img dont have fully 8 adjacent square
                            {
                                
                            }
                            else
                            {
                            sumBlue += image[i+k][j+n].rgbtBlue;
                            sumGreen += image[i+k][j+n].rgbtGreen;
                            sumRed += image[i+k][j+n].rgbtRed;

                            counter++;
                            }
                        }
                }
            tmp[i][j].rgbtBlue = round((float)sumBlue/counter);
            tmp[i][j].rgbtGreen = round((float)sumGreen/counter);
            tmp[i][j].rgbtRed = round((float)sumRed/counter);

        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image[i][k] = tmp[i][k];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    int Gx[3][3] = {{-1, 0, 1},{-2, 0, 2},{-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1},{0, 0, 0},{1, 2, 1}};
    #include <math.h>

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) 
        {
            int sumBlueX = 0, sumGreenX = 0, sumRedX = 0;
            int sumBlueY = 0, sumGreenY = 0, sumRedY = 0;

            for (int k = -1; k <= 1; k++) // adjacent nine pixels that form a 3x3 box around the pixel
                {
                    for (int n = -1; n <= 1; n++)
                        {
                            if (i + k < 0 || i + k >= height || j + n < 0 || j + n >= width) /// pixle on edge and corner of img dont have fully 8 adjacent square
                            {
                                ///  treat the image as if there was a 1 pixel solid black border around the edge of the image
                                sumBlueX += (0 * Gx[k+1][n+1]);
                                sumGreenX += (0 * Gx[k+1][n+1]);
                                sumRedX += (0 * Gx[k+1][n+1]);
                                
                                sumBlueY += (0 * Gy[k+1][n+1]);
                                sumGreenY += (0 * Gy[k+1][n+1]);
                                sumRedY += (0 * Gy[k+1][n+1]);
                            }
                            else 
                            {
                                sumBlueX += (image[i+k][j+n].rgbtBlue * Gx[k+1][n+1]);  
                                sumGreenX += (image[i+k][j+n].rgbtGreen * Gx[k+1][n+1]);
                                sumRedX += (image[i+k][j+n].rgbtRed * Gx[k+1][n+1]);
                                
                                sumBlueY += (image[i+k][j+n].rgbtBlue * Gy[k+1][n+1]);
                                sumGreenY += (image[i+k][j+n].rgbtGreen * Gy[k+1][n+1]);
                                sumRedY += (image[i+k][j+n].rgbtRed * Gy[k+1][n+1]);
                            }
                        }
                }
            int blue = round((float)(sqrt(pow(sumBlueX, 2) + pow(sumBlueY, 2))));
            int green = round((float)(sqrt(pow(sumGreenX, 2) + pow(sumGreenY, 2))));
            int red = round((float)(sqrt(pow(sumRedX, 2) + pow(sumRedY, 2))));
            
            if (blue > 255)
                {blue = 255;}
            else if (green > 255)
                {green = 255;}
            else if (red > 255)
                {red = 255;}
            
            
            tmp[i][j].rgbtBlue = blue;
            tmp[i][j].rgbtGreen = green;
            tmp[i][j].rgbtRed = red;

        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image[i][k] = tmp[i][k];
        }
    }
    
    
    
    return;
}
 