#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[HEADER_SIZE];
    FILE *img = NULL;
    char var[8];
    int counter = 0;

    while (fread(buffer, sizeof(uint8_t), 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
        buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter == 0)
            {
                sprintf(var, "%03i.jpg", counter);
                img = fopen(var, "w");
                fwrite(&buffer, sizeof(uint8_t), 512, img);
                counter++;
            }
            else if (counter > 0)
            {
                fclose(img);
                sprintf(var, "%03i.jpg", counter);
                img = fopen(var, "w");
                fwrite(&buffer, sizeof(uint8_t), 512, img);
                counter++;
            }
        }
        else if (counter > 0)
        {
            fwrite(&buffer, sizeof(uint8_t), 512, img);
        }
    }
    fclose(file);
    fclose(img);
}