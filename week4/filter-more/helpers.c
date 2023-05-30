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
                blue += image[i][j + 1].rgbtBlue;;
            }

            if (down)
            {
                if (left)
                {
                    count++;
                    red += image[i + 1][j - 1].rgbtRed;
                    green += image[i + 1][j - 1].rgbtGreen;
                    blue += image[i + 1][j - 1].rgbtBlue;;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE var[height][width];
    bool up = false;
    bool down = false;
    bool right = false;
    bool left = false;

    float count = 0.0;

    int y = 2;
    int redpowx = 0;
    int bluepowx = 0;
    int greenpowx = 0;

    int redpowy = 0;
    int bluepowy = 0;
    int greenpowy = 0;

    int redx = 0;
    int bluex = 0;
    int greenx = 0;

    int redy = 0;
    int bluey = 0;
    int greeny = 0;

    for (int i = 0, j; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            count = 1;

            up = false;
            down = false;
            right = false;
            left = false;

            redx = 0 * (image[i][j].rgbtRed);
            bluex = 0 * (image[i][j].rgbtBlue);
            greenx = 0 * (image[i][j].rgbtGreen);

            redy = 0 * (image[i][j].rgbtRed);
            bluey = 0 * (image[i][j].rgbtBlue);
            greeny = 0 * (image[i][j].rgbtGreen);

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
                    redx += -1 * (image[i - 1][j - 1].rgbtRed);
                    greenx += -1 * (image[i - 1][j - 1].rgbtGreen);
                    bluex += -1 * (image[i - 1][j - 1].rgbtBlue);

                    redy += -1 * (image[i - 1][j - 1].rgbtRed);
                    greeny += -1 * (image[i - 1][j - 1].rgbtGreen);
                    bluey += -1 * (image[i - 1][j - 1].rgbtBlue);
                }

                count++;
                redx += 0 * (image[i - 1][j].rgbtRed);
                greenx += 0 * (image[i - 1][j].rgbtGreen);
                bluex += 0 * (image[i - 1][j].rgbtBlue);

                redy += -2 * (image[i - 1][j].rgbtRed);
                greeny += -2 * (image[i - 1][j].rgbtGreen);
                bluey += -2 * (image[i - 1][j].rgbtBlue);

                if (right)
                {
                    count++;
                    redx += 1 * (image[i - 1][j + 1].rgbtRed);
                    greenx += 1 * (image[i - 1][j + 1].rgbtGreen);
                    bluex += 1 * (image[i - 1][j + 1].rgbtBlue);

                    redy += -1 * (image[i - 1][j + 1].rgbtRed);
                    greeny += -1 * (image[i - 1][j + 1].rgbtGreen);
                    bluey += -1 * (image[i - 1][j + 1].rgbtBlue);
                }
            }

            if (left)
            {
                count++;
                redx += -2 * (image[i][j - 1].rgbtRed);
                greenx += -2 * (image[i][j - 1].rgbtGreen);
                bluex += -2 * (image[i][j - 1].rgbtBlue);

                redy += 0 * (image[i][j - 1].rgbtRed);
                greeny += 0 * (image[i][j - 1].rgbtGreen);
                bluey += 0 * (image[i][j - 1].rgbtBlue);
            }

            //count++;
            //var += image[i][j];

            if (right)
            {
                count++;
                redx += 2 * (image[i][j + 1].rgbtRed);
                greenx += 2 * (image[i][j + 1].rgbtGreen);
                bluex += 2 * (image[i][j + 1].rgbtBlue);

                redx += 0 * (image[i][j + 1].rgbtRed);
                greenx += 0 * (image[i][j + 1].rgbtGreen);
                bluex += 0 * (image[i][j + 1].rgbtBlue);
            }

            if (down)
            {
                if (left)
                {
                    count++;
                    redx += -1 * (image[i + 1][j - 1].rgbtRed);
                    greenx += -1 * (image[i + 1][j - 1].rgbtGreen);
                    bluex += -1 * (image[i + 1][j - 1].rgbtBlue);

                    redx += 1 * (image[i + 1][j - 1].rgbtRed);
                    greenx += 1 * (image[i + 1][j - 1].rgbtGreen);
                    bluex += 1 * (image[i + 1][j - 1].rgbtBlue);
                }

                count++;
                redx += 0 * (image[i + 1][j].rgbtRed);
                greenx += 0 * (image[i + 1][j].rgbtGreen);
                bluex += 0 * (image[i + 1][j].rgbtBlue);

                redx += 2 * (image[i + 1][j].rgbtRed);
                greenx += 2 * (image[i + 1][j].rgbtGreen);
                bluex += 2 * (image[i + 1][j].rgbtBlue);

                if (right)
                {
                    count++;
                    redx += 1 * (image[i + 1][j + 1].rgbtRed);
                    greenx += 1 * (image[i + 1][j + 1].rgbtGreen);
                    bluex += 1 * (image[i + 1][j + 1].rgbtBlue);

                    redy += 1 * (image[i + 1][j + 1].rgbtRed);
                    greeny += 1 * (image[i + 1][j + 1].rgbtGreen);
                    bluey += 1* (image[i + 1][j + 1].rgbtBlue);
                }
            }
            //printf("%i\n", red);
            redpowx = pow(redx, 2);
            greenpowx = pow(greenx, 2);
            bluepowx = pow(bluex, 2);

            redpowy = pow(redy, 2);
            greenpowy = pow(greeny, 2);
            bluepowy = pow(bluey, 2);

            var[i][j].rgbtRed = sqrt(redpowx + redpowy);
            var[i][j].rgbtGreen = sqrt(greenpowx + greenpowy);
            var[i][j].rgbtBlue = sqrt(bluepowx + bluepowy);

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
