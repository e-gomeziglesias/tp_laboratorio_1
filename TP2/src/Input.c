/*
 * Input.c
 *
 *  Created on: 14 may. 2021
 *      Author: Emiliano Gomez Iglesias
 */

#include "Input.h"

int getString(char dato[], char msg[], char errorMsg[], int len)
{
    int returning;
	char buffer[1024];
    int i;
    returning = -1;
    if (len > 0 && dato != NULL)
    {
        printf("%s", msg);
        fflush(stdin);
        gets(buffer);
        strlwr(buffer);
        for (i=0; i<strlen(buffer);i++)
        {
            while (strlen(buffer)>len-1 || (isalpha(buffer[i])==0))//con el -1 estoy restando el \O de la cadena
            {
                printf("%s",errorMsg);
                fflush(stdin);
                gets(buffer);
                strlwr(buffer);
                i=0;
            }
            if (i==0)
            {
                buffer[i]=toupper(buffer[i]);
            }
        }
        strcpy(dato,buffer);
        returning = 0;
    }
    return returning;
}

char getUpperChar(char msg[])
{
        char aux;
        char returning;

        printf("%s",msg);
        fflush(stdin);
        scanf("%c",&aux);
        aux=toupper(aux);
        returning = aux;
    return returning;
}

int getInt(char msg[], char errorMsg[], int minRange, int maxRange)
{
    int returning;
    int number;
	char buffer[256];
    int i;
    returning = -1;
    if ((minRange>INT_MIN || maxRange<INT_MAX) && msg != NULL)
    {
        printf("%s", msg);
        fflush(stdin);
        gets(buffer);
        for (i=0; i<strlen(buffer);i++)
        {
            while ((isdigit(buffer[i])==0)|| atoi(buffer) < minRange || atoi(buffer)>maxRange)
            {
                printf("%s",errorMsg);
                fflush(stdin);
                gets(buffer);
                i=0;
            }
        }
        number = atoi(buffer);
        returning = number;

    }
    return returning;
}

float getFloat(char msg[], char errorMsg[], float minRange, float maxRange)
{
    float returning;
    float number;
	char buffer[256];
    int i;
    int flagPoint;
    flagPoint = 0;
    returning = -1;
    if ((minRange>FLT_MIN || maxRange<FLT_MAX) && msg != NULL)
    {
        printf("%s", msg);
        fflush(stdin);
        gets(buffer);
        for (i=0; i<strlen(buffer);i++)
        {
                if((buffer[i]=='.'||buffer[i]==',') && flagPoint==0)
                {
                    buffer[i]='.';
                    flagPoint=1;
                    continue;
                }
                else if(isdigit(buffer[i])==0||(atof(buffer) < minRange || atof(buffer)>maxRange))
                {
                    printf("%s",errorMsg);
                    fflush(stdin);
                    gets(buffer);
                    i=0;
                }
        }
        number = atof(buffer);
        returning = number;
    }
    return returning;
}
