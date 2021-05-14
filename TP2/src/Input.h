/*
 * Input.h
 *
 *  Created on: 14 may. 2021
 *      Author: Emiliano Gomez Iglesias
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <float.h>


#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */


/** \brief Receives a char array and validates it. (It doesn't admit numbers or special characters, including spaces)
 *
 * \param dato[] char array where the input information is going to be saved
 * \param msg[] char input message
 * \param errorMsg[] char error message
 * \param len int array length
 * \return int returns 0 if OK or -1 if error
 *
 */
int getString(char dato[], char msg[], char errorMsg[], int len);

/** \brief Receives a char parameter and turns it into capital
 *
 * \param msg[] char enter character message
 * \return char capital character
 *
 */
char getUpperChar(char msg[]);

/** \brief validates that a parameter is int type and that this parameter is within a given range
 *
 * \param msg[] char enter message
 * \param errorMsg[] char error message
 * \param minRange int minimal range
 * \param maxRange int maximal range
 * \return int validated int number
 *
 */
int getInt(char msg[], char errorMsg[], int minRange, int maxRange);

/** \brief validates that a parameter is float type and that this parameter is within a given range
 *
 * \param msg[] char enter message
 * \param errorMsg[] char error message
 * \param minRange float minimal range
 * \param maxRange float maximal range
 * \return float validated float number
 *
 */
float getFloat(char msg[], char errorMsg[], float minRange, float maxRange);
