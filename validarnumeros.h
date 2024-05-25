#include <stdio.h>
#include <ctype.h>
#include <string.h>

int validarnumero(char cadena[])
{
    int i = 0;
    int flag = 0; 

    while (i < strlen(cadena) && flag == 0)
    {
        int esnumero = isdigit(cadena[i]);
        if (esnumero != 0) 
        {
            flag = 1; 
            break;
        }
        i++;
    }

    return flag;
}