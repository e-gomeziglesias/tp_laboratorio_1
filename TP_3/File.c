/*
 * File.c
 *
 *  Created on: 8 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "File.h"

//1.
FILE* File_OpenTXTFileForWriting(char* path)
{
	FILE* pFile = NULL;
	if(path!=NULL)
	{
		pFile = fopen(path,"w");
	}
	return pFile;
}

//2.
FILE* File_OpenBINFileForWriting(char* path)
{
	FILE* pFile = NULL;
	if(path!=NULL)
	{
		pFile = fopen(path,"wb");
	}
	return pFile;
}

//3.
FILE* File_OpenTXTFileForReading(char* path)
{
	FILE* pFile = NULL;
	if(path!=NULL)
	{
		pFile = fopen(path,"r");
	}
	return pFile;
}

//4.
FILE* File_OpenBINFileForReading(char* path)
{
	FILE* pFile = NULL;
	if(path!=NULL)
	{
		pFile = fopen(path,"rb");
	}
	return pFile;
}

//5.
int File_CloseFile(FILE* pFile)
{
	int retorno = -1;
	if(pFile != NULL)
	{
		fclose(pFile);
		retorno = 0;
	}
	return retorno;
}

//6.
int File_WriteNextIdTXTFile(char* path, int nextId)
{
	int retorno = -1;
	FILE* pFileId;
	if(path != NULL && nextId>0)
	{
		pFileId=File_OpenTXTFileForWriting(path);
		if(pFileId!=NULL)
		{
			fprintf(pFileId, "%d", nextId);//imprime en el archivo el siguiente id utilizable
		}
		File_CloseFile(pFileId);
		retorno = 0;
	}
	return retorno;
}
