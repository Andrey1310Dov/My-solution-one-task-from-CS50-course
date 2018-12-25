#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //we ensure that a command has been typed in correctly
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
  
    //we get variables that we need
    char *infile = argv[1];
    unsigned char first_byte = 0xff;
    unsigned char second_byte = 0xd8;
    unsigned char third_byte = 0xff;
    unsigned char fourth_byte[16] = {0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef};
    char name_file[8];
    char *outfile = name_file;
    int digit_new_file = 0;


    //open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
   
    //function fseek moves the pointer to the position in the stream. 
    fseek(inptr, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(inptr);
    fseek(inptr, 0, SEEK_SET);

    unsigned char x;
    int check_one_jpg = 0;
    int step = 0;


    for (unsigned long i = 0; i < len;)
    {
        // check first four bytes
        fread(&x, sizeof(unsigned char), 1, inptr);
        step += 1;
        i += 1;
        if (x == first_byte)
        {
            fread(&x, sizeof(unsigned char), 1, inptr);
            step += 1;
            i += 1;

            if (x == second_byte)
            {
                fread(&x, sizeof(unsigned char), 1, inptr);
                step += 1;
                i += 1;
                if (x == third_byte)
                {
                    fread(&x, sizeof(unsigned char), 1, inptr);
                    step += 1;
                    i += 1;
                    for (int j = 0, number_digits_fourth = sizeof(fourth_byte); j < number_digits_fourth; j++)
                    {
                        if (x == fourth_byte[j])
                        {
                            check_one_jpg += 1;
                            // do step as authentic
                            if (check_one_jpg == 1)
                            {
                                step = 4;
                            }
                        }
                    }
                }
            }
        }
        if (check_one_jpg == 2)
        {
            fseek(inptr, - step, SEEK_CUR);
            // do name file
            if (0 <= digit_new_file && digit_new_file <= 9)
            {
                sprintf(name_file, "%s%d%s", "00", digit_new_file, ".jpg");
            }
            else if (10 <= digit_new_file && digit_new_file <= 99)
            {
                sprintf(name_file, "%s%d%s", "0", digit_new_file, ".jpg");
            }
            else if (digit_new_file >= 100)
            {
                sprintf(name_file, "%d%s", digit_new_file, ".jpg");
            }
            digit_new_file += 1;
            //open file to write
            FILE *outptr = fopen(outfile, "w");
            //correct number of steps
            step = step - 4;
            //create place in memory from heap
            unsigned char *place = (unsigned char *)malloc(step * sizeof(unsigned char));
            //read and add to memory's place
            fread(place, step * sizeof(unsigned char), 1, inptr);
            //write from memory's place
            fwrite(place, step * sizeof(unsigned char), 1, outptr);
            //close file for writing
            fclose(outptr);
            // clear memory
            free(place);
            check_one_jpg = 0;
            step = 0;
            i -= 4;
        }
    }

    fseek(inptr, -step, SEEK_CUR);
    //do name next file
    if (0 <= digit_new_file && digit_new_file <= 9)
    {
        sprintf(name_file, "%s%d%s", "00", digit_new_file, ".jpg");
    }
    else if (10 <= digit_new_file && digit_new_file <= 99)
    {
        sprintf(name_file, "%s%d%s", "0", digit_new_file, ".jpg");
    }
    else if (digit_new_file >= 100)
    {
        sprintf(name_file, "%d%s", digit_new_file, ".jpg");
    }
    FILE *outptr = fopen(outfile, "w");
    unsigned char *place = (unsigned char *)malloc(step * sizeof(unsigned char));
    fread(place, step * sizeof(unsigned char), 1, inptr);
    fwrite(place, step * sizeof(unsigned char), 1, outptr);
    fclose(outptr);
    free(place);


    //close infile
    fclose(inptr);

    //success
    return 0;
}
