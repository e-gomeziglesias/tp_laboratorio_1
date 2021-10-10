/*
 * Input.c
 *
 *  Created on: 5 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "input.h"


/** \brief Receives a char array and validates it. (It doesn't admit numbers or special characters, including spaces)
 *
 * \param dato[] char array where the input information is going to be saved
 * \param msg[] char input message
 * \param errorMsg[] char error message
 * \param len int array length
 * \return int returns 0 if OK or -1 if error
 *
 */
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
            while (strlen(buffer)>len-1 || ((isalpha(buffer[i])==0) && buffer[i]!=' '))//con el -1 estoy restando el \O de la cadena
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
            else if(buffer[i]==' ')
            {
            	buffer[i+1]=toupper(buffer[i+1]);
            }
        }
        strcpy(dato,buffer);
        returning = 0;
    }
    return returning;
}

/** \brief Receives a char parameter and turns it into capital
 *
 * \param msg[] char enter character message
 * \return char capital character
 *
 */
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


/** \brief validates that a parameter is int type and that this parameter is within a given range
 *
 * \param msg[] char enter message
 * \param errorMsg[] char error message
 * \param minRange int minimal range
 * \param maxRange int maximal range
 * \return int validated int number
 *
 */
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

/** \brief validates that a parameter is float type and that this parameter is within a given range
 *
 * \param msg[] char enter message
 * \param errorMsg[] char error message
 * \param minRange float minimal range
 * \param maxRange float maximal range
 * \return float validated float number
 *
 */
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


