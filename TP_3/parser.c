#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "File.h"


//1.
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pAuxEmployee;
	char idStr[50];
	char nombreStr[150];
	char horasTrabajadasStr[50];
	char sueldoStr[50];
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		//falsa lectura para no cargar en el archivo las cabeceras
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr)==4)
			{
				if(!isValidId(idStr) && !isValidNombre(nombreStr) && !isValidHorasTrabajadas(horasTrabajadasStr))
				{
					pAuxEmployee = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

					if(pAuxEmployee != NULL)
					{
						retorno = ll_add((pArrayListEmployee), pAuxEmployee); //agrego el elemento a la linkedlist
					}
				}
			}
			if(feof(pFile)) //parche del while(feof) para evitar la potencial doble lectura
			{
				File_WriteNextIdTXTFile("nextId.txt", atoi(idStr)+1);
				break;
			}
		}
	}
	return retorno;
}

//2.
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int tamCabecera;
	int nextId;
	Employee* pAuxEmployee;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		tamCabecera = strlen("id,nombre,horasTrabajadas,sueldo\n");
		fseek(pFile,tamCabecera,SEEK_SET);//ubico el indicador despues de la cabecera para saltearla
		while(!feof(pFile))
		{
			pAuxEmployee = employee_new();
			if(pAuxEmployee != NULL)
			{
				if(fread(pAuxEmployee, sizeof(Employee), 1, pFile)==1)
				{
					retorno = ll_add(pArrayListEmployee, pAuxEmployee);
					employee_getId(pAuxEmployee, &nextId);//necesario para conseguir luego el siguiente id y guardarlo en archivo
				}
			}
			if(feof(pFile)) //parche del while(feof) para evitar la potencial doble lectura
			{
				File_WriteNextIdTXTFile("nextId.txt", nextId+1);
				break;
			}
		}
	}
	return retorno;
}

