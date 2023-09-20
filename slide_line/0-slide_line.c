#include "slide_line.h"
/**
* slide_line - function  slides and merges an array of integers
* @line: line points to an array of integers containing size elements
* @size: size
* @direction: direction
*
* Return: 0 or 1
*/
int slide_line(int *line, size_t size, int direction)
{

    int slideline[100];
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < (int)size; i++)
        slideline[i] = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
    {
        return (0);
    }

    else if (direction == SLIDE_LEFT)
    {
        k = line[0];
        j = 0;
        slideline[j] = k;
        for (i = 1; i < (int)size; i++)
        {
            if (line[i] == k && line[i] != 0)
            {
                slideline[j] = k += k;
                k = 0;
                j+=1;
            }
            else if (line[i] && slideline[j] != 0)
            {
                j+=1;
                k = line[i];
                slideline[j] = k;
            }
            else if (line[i] != 0)
            {
                k = line[i];
                slideline[j] = k;
            }
        }
    }
    else
    {
        k = line[size - 1];
        j = size - 1;
        slideline[j] = k;
        for (i = size - 2; i >= 0; i--)
        {
            if (line[i] == k && line[i] != 0)
            {
                slideline[j] = k += k;
                k = 0;
                j-=1;
            }
            else if (line[i] && slideline[j] != 0)
            {
                j-=1;
                k = line[i];
                slideline[j] = k;
            }
            else if (line[i] != 0)
            {
                k = line[i];
                slideline[j] = k;
            }
        }
    }
    for (i = 0; i < (int)size; i++)
    {
        line[i] = slideline[i];
    }
    return (1);
}
