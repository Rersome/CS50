#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int colors[3];
            colors[0] = image[i][j].rgbtRed;
            colors[1] = image[i][j].rgbtGreen;
            colors[2] = image[i][j].rgbtBlue;
            int divide = round((colors[0] + colors[1] + colors[2]) / 3.0);
            /*for (int i = 0, j; i < colors - 1; i++)
            {
                for (j = 0; j < colors - i - 1; j++)
                {
                    int var = colors[j];
                    colors[j] = colors[j + 1];
                    colors[j + 1] = var;
                }
            }*/
            image[i][j].rgbtRed = divide;
            image[i][j].rgbtGreen = divide;
            image[i][j].rgbtBlue = divide;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE var;
    for (int i = 0, j; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            var = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = var;
            //printf("%i\n%i\n%i\n", image[i][j].rgbtRed, image[i][j].rgbtBlue, image[i][j].rgbtGreen);
            /*for (int k = width - 1; k >= 0; k--)
            {
                var = image[i][k];
                image[i][k] = image[i][k - 1];
                image[i][k - 1] = var;
                //printf("%i\n%i\n%i\n", image[i][j].rgbtRed, image[i][j].rgbtBlue, image[i][j].rgbtGreen);
            }*/
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE var[height][width];
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;
    float count = 0.0;
    int red = 0;
    int blue = 0;
    int green = 0;
    for (int i = 0, j; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            count = 1;
            up = false;
            down = false;
            right = false;
            left = false;
            red = image[i][j].rgbtRed;
            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;

            if (j > 0)
            {
                left = true;
            }
            if (j < width - 1)
            {
                right = true;
            }
            if (i < height - 1)
            {
                down = true;
            }
            if (i > 0)
            {
                up = true;
            }
            if (up)
            {
                if (left)
                {
                    count++;
                    red += image[i - 1][j - 1].rgbtRed;
                    green += image[i - 1][j - 1].rgbtGreen;
                    blue += image[i - 1][j - 1].rgbtBlue;
                }

                count++;
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;

                if (right)
                {
                    count++;
                    red += image[i - 1][j + 1].rgbtRed;
                    green += image[i - 1][j + 1].rgbtGreen;
                    blue += image[i - 1][j + 1].rgbtBlue;
                }
            }

            if (left)
            {
                count++;
                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
            }

            //count++;
            //var += image[i][j];

            if (right)
            {
                count++;
                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
            }

            if (down)
            {
                if (left)
                {
                    count++;
                    red += image[i + 1][j - 1].rgbtRed;
                    green += image[i + 1][j - 1].rgbtGreen;
                    blue += image[i + 1][j - 1].rgbtBlue;
                }

                count++;
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;

                if (right)
                {
                    count++;
                    red += image[i + 1][j + 1].rgbtRed;
                    green += image[i + 1][j + 1].rgbtGreen;
                    blue += image[i + 1][j + 1].rgbtBlue;
                }
            }
            //printf("%i\n", red);
            var[i][j].rgbtRed = round(red / count);
            var[i][j].rgbtGreen = round(green / count);
            var[i][j].rgbtBlue = round(blue / count);
        }
    }
    for (int i = 0, j; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j] = var[i][j];
        }
    }
}