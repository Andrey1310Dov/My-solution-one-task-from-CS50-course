// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

int frequency(string note)
{   
    //we create variables that we need
    float f_1;
    int f;
    float n;
    n = 0;
    // if #
    if (note[1] == 35)
    {
        if (note[2] == 52)
        {
            if (note[0] == 66)
            {
                n = n + 2;
                n = n + 1;
            }
            else if ((note[0] >= 70) && (note[0] <= 71))
            {
                n = n - ((72 - note[0]) * 2);
                n = n + 1;
            }
            else if ((note[0] >= 67) && (note[0] < 70))
            {
                n = n - ((72 - note[0]) * 2) + 1;
                n = n + 1;
            }
            else if (note[0] == 65)
            {
                n = n + 1;
            }
        }
        else
        {
            if (note[2] > 52)
            {
                if (note[0] == 66)
                {
                    n = ((note[2] - 52) * 12) + 2;
                    n = n + 1;
                }
                else if ((note[0] >= 70) && (note[0] <= 71))
                {
                    n = ((72 - note[0]) * 2);
                    n = ((note[2] - 52) * 12) - n;
                    n = n + 1;
                }
                else if ((note[0] >= 67) && (note[0] < 70))
                {
                    n = (((72 - note[0]) * 2) - 1);
                    n = ((note[2] - 52) * 12) - n;
                    n = n + 1;
                }
                else if (note[0] == 65)
                {
                    n = n + ((note[2] - 52) * 12);
                    n = n + 1;
                }
            }
            else if (note[2] < 52)
            {
                if (note[0] == 66)
                {
                    n = ((note[2] - 52) * 12) + 2;
                    n = n + 1;
                }
                else if ((note[0] >= 70) && (note[0] <= 71))
                {
                    n = ((72 - note[0]) * 2);
                    n = ((note[2] - 52) * 12) - n;
                    n = n + 1;
                }
                else if ((note[0] >= 67) && (note[0] < 70))
                {
                    n = (((72 - note[0]) * 2) - 1);
                    n = ((note[2] - 52) * 12) - n;
                    n = n + 1;
                }
                else if (note[0] == 65)
                {
                    n = n + ((note[2] - 52) * 12);
                    n = n + 1;
                }
            }
        }
    }
    //if b
    else if (note[1] == 98)
    {
        if (note[2] == 52)
        {
            if (note[0] == 66)
            {
                n = n + 2;
                n = n - 1;
            }
            else if ((note[0] >= 70) && (note[0] <= 71))
            {
                n = n - ((72 - note[0]) * 2);
                n = n - 1;
            }
            else if ((note[0] >= 67) && (note[0] < 70))
            {
                n = n - ((72 + note[0]) * 2) + 1;
                n = n - 1;
            }
            else if (note[0] == 65)
            {
                n = n - 1;
            }
        }
        else
        {
            if (note[2] > 52)
            {
                if (note[0] == 66)
                {
                    n = ((note[2] - 52) * 12) + 2;
                    n = n - 1;
                }
                else if ((note[0] >= 70) && (note[0] <= 71))
                {
                    n = ((72 - note[0]) * 2);
                    n = ((note[2] - 52) * 12) - n;
                    n = n - 1;
                }
                else if ((note[0] >= 67) && (note[0] < 70))
                {
                    n = (((72 - note[0]) * 2) - 1);
                    n = ((note[2] - 52) * 12) - n;
                    n = n - 1;
                }
                else if (note[0] == 65)
                {
                    n = n + ((note[2] - 52) * 12);
                    n = n - 1;
                }
            }
            else if (note[2] < 52)
            {
                if (note[0] == 66)
                {
                    n = ((note[2] - 52) * 12) + 2;
                    n = n - 1;
                }
                else if ((note[0] >= 70) && (note[0] <= 71))
                {
                    n = ((72 - note[0]) * 2);
                    n = ((note[2] - 52) * 12) - n;
                    n = n - 1;
                }
                else if ((note[0] >= 67) && (note[0] < 70))
                {
                    n = (((72 - note[0]) * 2) - 1);
                    n = ((note[2] - 52) * 12) - n;
                    n = n - 1;
                }
                else if (note[0] == 65)
                {
                    n = n + ((note[2] - 52) * 12);
                    n = n - 1;
                }
            }
        }
    }
    // if nor # nor b
    else
    {
        if (note[1] == 52)
        {
            if (note[0] == 66)
            {
                n = n + 2;
            }
            else if ((note[0] >= 70) && (note[0] <= 71))
            {
                n = n - ((72 - note[0]) * 2);
            }
            else if ((note[0] >= 67) && (note[0] < 70))
            {
                n = n - ((72 - note[0]) * 2) + 1;
            }
        }
        else
        {
            if (note[1] > 52)
            {
                if (note[0] == 66)
                {
                    n = ((note[1] - 52) * 12) + 2;
                }
                else if ((note[0] >= 70) && (note[0] <= 71))
                {
                    n = ((72 - note[0]) * 2);
                    n = ((note[1] - 52) * 12) - n;
                }
                else if ((note[0] >= 67) && (note[0] < 70))
                {
                    n = (((72 - note[0]) * 2) - 1);
                    n = ((note[1] - 52) * 12) - n;
                }
                else if (note[0] == 65)
                {
                    n = n + ((note[1] - 52) * 12);
                }
            }
            else if (note[1] < 52)
            {
                if (note[0] == 66)
                {
                    n = ((note[1] - 52) * 12) + 2;
                }
                else if ((note[0] >= 70) && (note[0] <= 71))
                {
                    n = ((72 - note[0]) * 2);
                    n = ((note[1] - 52) * 12) - n;
                }
                else if ((note[0] >= 67) && (note[0] < 70))
                {
                    n = (((72 - note[0]) * 2) - 1);
                    n = ((note[1] - 52) * 12) - n;
                }
                else if (note[0] == 65)
                {
                    n = n + ((note[1] - 52) * 12);
                }
            }
        }
    }
    //function pow raises the value basis a power exponent:
    f_1 = pow(2, n / 12);
    //get frequency 
    f_1 = f_1 * 440;
    f = round(f_1);
    return f;
}

int duration(string fraction)
{   
    //we create variables that we need
    int durations;
    int i = strlen(fraction);
    //we get numbger of 1/8's notes
    if (fraction[i - 1] == 56)
    {
        durations = fraction[i - 3] - 48;
        return durations;
    }
    else if (fraction[i - 1] == 52)
    {
        durations = (fraction[i - 3] - 48) * 2;
        return durations;
    }
    else if (fraction[i - 1] == 50)
    {
        durations = (fraction[i - 3] - 48) * 4;
        return durations;
    }
    else if (fraction[i - 1] == 49)
    {
        durations = 8;
        return durations;
    }
    else
    {
        return 1;
    }
    return 1;
}


bool is_rest(string s)
{  
    //An absence of a note (i.e., silence) is considered a rest, the duration of which is also implied by its shape.
    //we get rest (blank lines in .txt represent rests in our machine-readable format 
    string b;
    b = "";
    //the function strncmp()compares the first num character string string1 with first num character string string2
    if (strncmp(s, b, 1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
