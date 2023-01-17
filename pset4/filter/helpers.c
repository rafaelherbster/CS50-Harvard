#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int media;
    for (int i = 0; i < height; i++) {
        for(int j=0; j < width; j++) {
            media = (int)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue =  media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtRed = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < (width/2); j++) {
            int tmp1 = image[i][j].rgbtBlue;
            int tmp2 = image[i][j].rgbtGreen;
            int tmp3 = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue = tmp1;

            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen = tmp2;

            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][width-1-j].rgbtRed = tmp3;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avgRGB[3] = {0,0,0};
            int count = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int x_coord = i + x;
                    int y_coord = j + y ;
                    if (x_coord < 0 || x_coord >= height || y_coord < 0 || y_coord >= width)
                    {
                        continue;
                    }
                    else
                    {
                        avgRGB[0] += temp[x_coord][y_coord].rgbtBlue;
                        avgRGB[1] += temp[x_coord][y_coord].rgbtGreen;
                        avgRGB[2] += temp[x_coord][y_coord].rgbtRed;
                        count++;
                    }
                }
            }
            image[i][j].rgbtBlue = round(avgRGB[0]/count);
            image[i][j].rgbtGreen = round(avgRGB[1]/count);
            image[i][j].rgbtRed = round(avgRGB[2]/count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
