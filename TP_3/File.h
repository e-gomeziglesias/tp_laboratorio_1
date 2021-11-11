/*
 * File.h
 *
 *  Created on: 8 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef FILE_H_
#define FILE_H_

//1.
/// @fn FILE* File_OpenTXTFileForWriting(char*)
/// @brief Permite abrir un archivo de texto para escritura
///
/// @param path ruta del archivo de texto
/// @return el puntero a la direccion de memoria del archivo o NULL si hubo error
FILE* File_OpenTXTFileForWriting(char* path);

//2.
/// @fn FILE* File_OpenBINFileForWriting(char*)
/// @brief Permite abrir un archivo binario para escritura
///
/// @param path ruta del archivo binario a leer
/// @return el puntero a la direccion de memoria del archivo o NULL si hubo error
FILE* File_OpenBINFileForWriting(char* path);

//3.
/// @fn FILE* File_OpenTXTFileForReading(char*)
/// @brief permite abrir un archivo de texto para lectura
///
/// @param path ruta del archivo de texto
/// @return el puntero a la direccion de memoria del archivo o NULL si hubo error
FILE* File_OpenTXTFileForReading(char* path);

//4.
/// @fn FILE* File_OpenBINFileForReading(char*)
/// @brief Permite abrir un archivo binario para lectura
///
/// @param path ruta del archivo
/// @return el puntero a la direccion de memoria del archivo o NULL si hubo error
FILE* File_OpenBINFileForReading(char* path);

//5.
/// @fn int File_CloseFile(FILE*)
/// @brief Permite cerrar un archivo
///
/// @param pFile puntero al archivo
/// @return 0 si ok, -1 si error
int File_CloseFile(FILE* pFile);

//6.
/// @fn int File_WriteNextIdTXTFile(char*, int)
/// @brief Recibe el siguiente id que puede utilizarse y lo guarda en un archivo de texto
///
/// @param path ruta del archivo donde se guardara el siguiente id disponible
/// @param nextId siguiente id disponible para cargar un nuevo empleado
/// @return 0 si ok, -1 si error
int File_WriteNextIdTXTFile(char* path, int nextId);

#endif /* FILE_H_ */
