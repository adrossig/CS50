#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float total = image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen;
            int average = (round)(total / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Real colors
            int realBlue = image[i][j].rgbtBlue;
            int realRed = image[i][j].rgbtRed;
            int realGreen = image[i][j].rgbtGreen;
            
            // Calculate the sepia color
            int sepiaBlue = (round)(0.272 * realRed + 0.534 * realGreen + 0.131 * realBlue);
            int sepiaRed = (round)(0.393 * realRed + 0.769 * realGreen + 0.189 * realBlue);
            int sepiaGreen = (round)(0.349 * realRed + 0.686 * realGreen + 0.168 * realBlue);
            
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            // Attribution of sepia
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
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
            float totalRed = 0;
            float totalBlue = 0;
            float totalGreen = 0;
            float counter = 0.00;
            
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int nbrX = i + x;
                    int nbrY = j + y;
                    
                    if (nbrX < 0 || nbrX > (height - 1) || nbrY < 0 || nbrY > (width - 1))
                    {
                        continue;
                    }
                    totalRed += image[nbrX][nbrY].rgbtRed;
                    totalBlue += image[nbrX][nbrY].rgbtBlue;
                    totalGreen += image[nbrX][nbrY].rgbtGreen;
                    
                    counter++;
                }
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
            }
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}
