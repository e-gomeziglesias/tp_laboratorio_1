/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

//1.
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo .csv
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardaran los empleados
 * \return int 0 si ok, -1 si error
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

//2.
/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* ruta del archivo .bin
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardaran los empleados
 * \return int 0 si ok, -1 si error
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

