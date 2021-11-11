//this dato actual con el que estoy trabajando
#include "Employee.h"


//1.
Employee* employee_new()
{
	Employee* nuevoEmpleado;
	nuevoEmpleado = (Employee*) calloc(1,sizeof(Employee));
	return nuevoEmpleado;
}

//2.
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pNuevoEmpleado = NULL;
	pNuevoEmpleado = employee_new();
	if(pNuevoEmpleado != NULL && idStr!=NULL && nombreStr!= NULL && horasTrabajadasStr != NULL && sueldoStr!=NULL &&
			!isValidId(idStr) && !isValidNombre(nombreStr) && !isValidHorasTrabajadas(horasTrabajadasStr) && !isValidSueldo(sueldoStr))
	{
		if(employee_setId(pNuevoEmpleado, atoi(idStr))||
		employee_setNombre(pNuevoEmpleado, nombreStr)||
		employee_setHorasTrabajadas(pNuevoEmpleado, atoi(horasTrabajadasStr))||
		employee_setSueldo(pNuevoEmpleado, atoi(sueldoStr)))
		{
			employee_delete(pNuevoEmpleado); //si alguno de los campos no se pudo cargar, el empleado no se carga y se libera la memoria reservada
		}
	}
	return pNuevoEmpleado;
}

//3.
void employee_delete(Employee* pEmpleado)
{
	if(pEmpleado != NULL)
	{
		free(pEmpleado);
	}
}

//4.
int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if(this!=NULL && id>0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

//5.
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this !=NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

//6.
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

//7.
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

//8.
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno = -1;

	if(this !=NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

//9.
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno = -1;

	if(this !=NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

//10.
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo>0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

//11.
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

//los empleados que le paso a la funcion hay que levantarlos de la lista.
//12.
int employee_CompareByName(void* e1, void* e2)
{
	int retorno = -1;
	Employee* pEmpleado1 = NULL;
	Employee* pEmpleado2 = NULL;

	char nombreEmpleado1[500];
	char nombreEmpleado2[500];

	if(e1 != NULL && e2 != NULL)
	{
		//unboxing
		pEmpleado1 = (Employee*)e1;
		pEmpleado2 = (Employee*)e2;
		if(!employee_getNombre(pEmpleado1, nombreEmpleado1) &&
		!employee_getNombre(pEmpleado2, nombreEmpleado2))
		{
			if(stricmp(nombreEmpleado1, nombreEmpleado2)>0)
			{
				retorno = 1;
			}
			else
			{
				if(stricmp(nombreEmpleado1, nombreEmpleado2)<0)
				{
					retorno = -1;
				}
				else
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

//13.
int employee_CompareById(void* e1, void* e2)
{
	int retorno = -1;
	Employee* pEmpleado1;
	Employee* pEmpleado2;
	int idEmpleado1;
	int idEmpleado2;

	if(e1 != NULL && e2 != NULL)
	{
		//unboxing
		pEmpleado1 = (Employee*) e1;
		pEmpleado2 = (Employee*) e2;
		employee_getId(pEmpleado1, &idEmpleado1);
		employee_getId(pEmpleado2, &idEmpleado2);

		if(idEmpleado1>idEmpleado2)
		{
			retorno = 1;
		}
		else
		{
			if(idEmpleado1<idEmpleado2)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

//15.
int isValidId(char* idStr)
{
	int retorno = -1;
	if(idStr!= NULL && atoi(idStr)>0 && !EsNumerica(idStr, sizeof(idStr)))
	{
		retorno = 0;
	}
	return retorno;
}

//15.
int isValidNombre(char* nombreStr)
{
	int retorno = -1;
	if(nombreStr != NULL && !EsAlfabetica(nombreStr, sizeof(nombreStr)) && (strlen(nombreStr)<=(TAM_NOMBRE-1)))
	{
		retorno = 0;
	}
	return retorno;
}

//16.
int isValidHorasTrabajadas(char* horasTrabajadasStr)
{
	int retorno = -1;
	if(horasTrabajadasStr!= NULL && atoi(horasTrabajadasStr)>0 && !EsNumerica(horasTrabajadasStr, sizeof(horasTrabajadasStr)))
	{
		retorno = 0;
	}
	return retorno;
}

//17.
int isValidSueldo(char* sueldoStr)
{
	int retorno = -1;
	if(sueldoStr!= NULL && atoi(sueldoStr)>0 && atoi(sueldoStr)<=MAX_SUELDO && !EsNumerica(sueldoStr, sizeof(sueldoStr)))
	{
		retorno = 0;
	}
	return retorno;
}

//18.
int employee_CargarNombre(char* nombre)
{
	int retorno = -1;
	if(nombre != NULL)
	{
		retorno = CargarStringNormalizado(nombre, TAM_NOMBRE, "Ingrese el nombre del empleado: ", "El nombre ingresado es invalido.", 0, 2);
	}
	return retorno;
}

//19.
int employee_CargarHorasTrabajadas(int* pHorasTrabajadas)
{
	int retorno = -1;
	if(pHorasTrabajadas != NULL)
	{
		retorno = CargarEntero(pHorasTrabajadas, "Ingrese las horas trabajadas: ", "La cantidad de horas ingresada es invalida", 0, 1000, 2);
	}
	return retorno;
}

//20.
int employee_CargarSueldo(int* pSueldo)
{
	int retorno = -1;
	if(pSueldo != NULL)
	{
		retorno = CargarEntero(pSueldo, "Ingrese el sueldo del empleado: ", "El sueldo ingresado es invalido.", 0, MAX_SUELDO, 2);
	}
	return retorno;
}

//21.
int employee_CargarId(int* pId)
{
	int retorno = -1;
	FILE* pFileId;
	int auxId;
	if(pId!=NULL)
	{
		pFileId=File_OpenTXTFileForReading("nextId.txt");
		if(fscanf(pFileId,"%d", &auxId)==1)
		{
			File_CloseFile(pFileId);
			*pId=auxId;
			auxId++;
			File_WriteNextIdTXTFile("nextId.txt", auxId);
			retorno = 0;
		}
	}
	return retorno;
}

//22.
int employee_setEmployee(Employee* pEmpleado, int id, char* nombre, int horasTrabajadas, int sueldo)
{
	int retorno = -1;
	if(pEmpleado != NULL)
	{
		if(!employee_setId(pEmpleado, id)&&
		   !employee_setNombre(pEmpleado, nombre)&&
		   !employee_setHorasTrabajadas(pEmpleado, horasTrabajadas)&&
		   !employee_setSueldo(pEmpleado, sueldo))
		{
			retorno = 0;
		}
	}
	return retorno;
}
