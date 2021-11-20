#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "File.h"
#include "Controller.h"
#include "Menu.h"


//1.
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* linkedlist donde se cargaran los empleadso
 * \return int 0 si ok, -1 si error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);//limpio la lista para que al abrir el texto se cargue desde la primer posicion
		pFile=File_OpenTXTFileForReading(path);//abro el archivo para lectura de texto
		if(pFile!=NULL)
		{
			retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
		File_CloseFile(pFile); //cierro el archivo
	}
	return retorno;
}

//2.
/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardara el listado de empleados
 * \return int 0 si ok, -1 si error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);//limpio la lista para que al abrir el archivo se cargue desde la primer posicion
		pFile = File_OpenBINFileForReading(path);//abro el archivo para lectura binaria
		if(pFile != NULL)
		{
			retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		}
		File_CloseFile(pFile);//cierro el archivo
	}
	return retorno;
}

//3.
/** \brief Permite dar de alta un empleado, cargando los datos por teclado
 *
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardara el empleado
 * \return int 0 si ok, -1 si error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado;
	int id;
	char nombre[TAM_NOMBRE];
	int horasTrabajadas;
	int sueldo;
	int index;

	if(pArrayListEmployee != NULL)
	{
		pEmpleado = (Employee*) employee_new();
		if(pEmpleado != NULL)
		{
			if(!employee_CargarNombre(nombre)&&
			   !employee_CargarHorasTrabajadas(&horasTrabajadas)&&
			   !employee_CargarSueldo(&sueldo))
			{
				if(!employee_CargarId(&id))//como crea un archivo de texto, lo verifico luego de que se hayan cargado correctamente las otras variables para no generar un id erroneo
				{
					if(!employee_setEmployee(pEmpleado, id, nombre, horasTrabajadas, sueldo))
					{
						retorno = ll_add(pArrayListEmployee, pEmpleado);
						if(retorno == 0)
						{
							index = controller_getIndexEmployeeById(pArrayListEmployee, id);
							printf("  ID	NOMBRE		   HORAS 	SUELDO\n");
							controller_PrintOneEmployee(pArrayListEmployee, index);
							printf("\n");
						}
					}
				}
			}
			if(retorno ==-1 && pEmpleado != NULL)
			{
				employee_delete(pEmpleado);//si ocurrio algun error y no se pudo agregar el empleado a la linkedlist, libera la memoria reservada
			}
		}
	}
	return retorno;
}

//4.
/** \brief Permite modificar cada uno de los campos de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si ok, -1 si error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	int retorno = -1;
	int idEmpleadoAModificar;
	int opcion;
	int index;
	char nombre[TAM_NOMBRE];
	int horasTrabajadas;
	int sueldo;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(CargarEntero(&idEmpleadoAModificar, "Ingrese el id del empleado a modificar: ","El id ingresado es invalido." , 1, MAX_ID, 2)==0)
		{
			index = controller_getIndexEmployeeById(pArrayListEmployee, idEmpleadoAModificar);
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, index);
			if(pEmpleado != NULL)
			{
				do
				{
					printf("  ID	NOMBRE		   HORAS 	SUELDO\n");
					controller_PrintOneEmployee(pArrayListEmployee, index);
					printf("\n");
					opcion = Menu_MostrarMenuModificacionesEmpleados();
					switch(opcion)
					{
						case 1:
							if(!employee_CargarNombre(nombre))
							{
								retorno = employee_setNombre(pEmpleado, nombre);
								Menu_AnalizarRetorno(retorno, "Se modifico con exito el nombre", "El nombre no se pudo modificar");
							}
							system("pause");
						break;

						case 2:
							if(!CargarEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas: ", "La cantidad de horas ingresada es invalida.", 0, 1000, 2))
							{
								retorno = employee_setHorasTrabajadas(pEmpleado, horasTrabajadas);
								Menu_AnalizarRetorno(retorno, "Se modificaron con exito las horas trabajadas.", "Las horas trabajadas no se pudieron modificar.");
							}
							system("pause");
						break;

						case 3:
							if(!CargarEntero(&sueldo, "Ingrese el sueldo: ", "El sueldo ingresado es invalido.", 0, MAX_SUELDO, 2))
							{
								retorno = employee_setSueldo(pEmpleado, sueldo);
								Menu_AnalizarRetorno(retorno, "Se modifico con exito el sueldo.", "El sueldo del empleado no se pudo modificar.");
							}
							system("pause");
						break;

						case 0:
							printf("Volviendo al menu principal\n");
							system("pause");
						break;

					}
				}while(opcion!=0);
			}
		}

	}
	return retorno;
}

//5.
/** \brief Baja de empleado. Permite dar de baja un empleado, eliminandolo de la linkedlist y liberando la memoria que ocupaba
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si ok, -1 si error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado;
	char opcion = 'n';
	int id;
	int index;
	if(pArrayListEmployee != NULL)
	{
			if(controller_ListEmployee(pArrayListEmployee)!=-1)
			{
				if(!CargarEntero(&id, "Ingrese el id del empleado a borrar: ", "El id ingresado es invalido.", 1, MAX_ID, 2))
				{
					index = controller_getIndexEmployeeById(pArrayListEmployee, id);
					if(index != -1)
					{
						controller_PrintOneEmployee(pArrayListEmployee, index); //muestro el empleado a borrar
						CargarChar(&opcion, "Desea borrar este empleado? (s/n): ","La respuesta ingresada es incorrecta." , 0, 2); //confirmo la eliminacion
						if(opcion == 's')
						{
							pEmpleado = (Employee*) ll_pop(pArrayListEmployee, index); //borro el empleado de la linkedlist
							employee_delete(pEmpleado); //libero la direccion de memoria del empleado
							retorno = 0;
						}
					}
					else
					{
						retorno = -2;
					}
				}
			}
	}
	return retorno;
}

//6.
/** \brief Listar empleados. Muestra una lista de los empleados cargados en la linkedlist
 *
 * \param pArrayListEmployee LinkedList* lista de donde se recuperaran los empleados
 * \return int 0 si ok, -1 si error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int tamLista;
	if(pArrayListEmployee != NULL)
	{
		tamLista = ll_len(pArrayListEmployee);
		if(tamLista>0)
		{
			printf("  ID	NOMBRE		   HORAS 	SUELDO\n");
			for(int i=0; i<tamLista; i++)
			{
				controller_PrintOneEmployee(pArrayListEmployee, i);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//7.
/** \brief Ordenar empleados por nombre o por id, indicando criterio ascendente o descendente
 *
 * \param pArrayListEmployee LinkedList* lista a ordenar
 * \return int 0 si ok, -1 si error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int criterio;
	if(pArrayListEmployee != NULL)
	{
		do
		{
			opcion = Menu_MostrarMenuOrdenamiento();

			switch(opcion)
			{
				case 1:
					if(CargarEntero(&criterio, "Indique el criterio de ordenamiento (0-descendente / 1-ascendente): ", "El criterio ingresado es invalido." , 0, 1, 2)==-1)
					{
						break;
					}
					retorno = ll_sort(pArrayListEmployee, employee_CompareByName, criterio);
					opcion = 0;
				//system("pause");
				break;

				case 2:
					if(CargarEntero(&criterio, "Indique el criterio de ordenamiento (0-descendente / 1-ascendente): ", "El criterio ingresado es invalido." , 0, 1, 2)==-1)
					{
						break;
					}
					retorno = ll_sort(pArrayListEmployee, employee_CompareById, criterio);
					opcion = 0;
				//system("pause");
				break;

				case 0:
					printf("Volviendo al menu principal\n");
				system("pause");
				break;
			}
		}while(opcion != 0);
	}
	return retorno;
}

//8.
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista de donde se recuperaran los datos a guardar
 * \return int 0 si ok, -1 si error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int tamLista;
    FILE* pFile;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    if(path != NULL && pArrayListEmployee != NULL)
    {
    	pFile = File_OpenTXTFileForWriting(path);
    	if(pFile != NULL)
    	{
        	tamLista = ll_len(pArrayListEmployee);
        	{
        		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");//imprimo la cabecera en el archivo
            	for(int i=0; i<tamLista; i++)
            	{
            		retorno = controller_getEmployee(pArrayListEmployee, i, &id, nombre, &horasTrabajadas, &sueldo);
            		if(retorno)
            		{
            			break;
            		}
            		else
            		{
                		fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
            		}
            	}
        	}
        	File_CloseFile(pFile);
    	}
    }
    return retorno;
}

//9.
/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista de donde se recuperaran los datos que se guardaran en el archivo
 * \return int 0 si ok, -1 si error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    char cabeceraArchivo[]="id,nombre,horasTrabajadas,sueldo";
	int tamLista;
	Employee* pEmpleado;

    if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = File_OpenBINFileForWriting(path);//abro el archivo para escritura binaria
		tamLista = ll_len(pArrayListEmployee);
		if(pFile!=NULL)
		{
			if(fwrite(cabeceraArchivo, sizeof(cabeceraArchivo), 1, pFile)==1)//escribo en el archivo binario la cabecera con los titulos
			{
				for(int i=0; i<tamLista; i++)
				{
					//unboxing del empleado
					pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
					if(pEmpleado != NULL)
					{
						fwrite(pEmpleado, sizeof(Employee), 1, pFile);//imprimo el empleado en el archivo
						retorno = 0;
					}
					else
					{
						retorno = -1;
						break;
					}
				}
			}
			File_CloseFile(pFile); //cierro el archivo
		}
	}
    return retorno;
}

//10.
/// @fn int controller_getEmployee(LinkedList*, int, int*, char*, int*, int*)
/// @brief Permite obtener todos los campos de un empleado y cargar cada uno a variables pasadas como parametro
///
/// @param pArrayListEmployee linkedlist de empleados
/// @param index indice del empleado
/// @param pId puntero a la variable donde se guardara el id
/// @param nombre puntero al array donde se guardara el nombre
/// @param pHorasTrabajadas puntero a la variable donde se guardaran las horas trabajadas
/// @param pSueldo puntero a la variable donde se guardara el sueldo
/// @return 0 si ok, -1 si error
int controller_getEmployee(LinkedList* pArrayListEmployee, int index, int* pId, char* nombre, int* pHorasTrabajadas, int* pSueldo)
{
	int retorno = -1;
	Employee* pAuxEmployee;
	if(pArrayListEmployee != NULL && pId != NULL && nombre!= NULL && pHorasTrabajadas != NULL && pSueldo != NULL)
	{
		//unboxing
		pAuxEmployee = (Employee*) ll_get(pArrayListEmployee, index);
		if(pAuxEmployee != NULL)
		{//asigno cada campo al auxiliar
			if(!employee_getId(pAuxEmployee, pId) &&
					!employee_getNombre(pAuxEmployee, nombre) &&
					!employee_getHorasTrabajadas(pAuxEmployee, pHorasTrabajadas) &&
					!employee_getSueldo(pAuxEmployee, pSueldo))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

//11.
/// @fn int controller_PrintOneEmployee(LinkedList*, int)
/// @brief Imprime por pantalla todos los datos de un empleado
///
/// @param pArrayListEmployee linked list donde se almacenan todos los empleados
/// @param index indice del empleado a mostrar
/// @return 0 si ok, -1 si error
int controller_PrintOneEmployee(LinkedList* pArrayListEmployee, int index)
{
	int retorno=-1;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	if(pArrayListEmployee != NULL && index >=0)
	{
		if(!controller_getEmployee(pArrayListEmployee, index, &auxId, auxNombre, &auxHorasTrabajadas, &auxSueldo))
		{
			printf("%4d	%-20s %4d 	%4d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
			retorno = 0;
		}
	}
	return retorno;
}

//12.
/// @fn int controller_getIndexEmployeeById(LinkedList*, int)
/// @brief permite obtener el indice de un empleado, pasando su id por parametro
///
/// @param pArrayListEmployee puntero a la linkedlist
/// @param id id a buscar
/// @return -1 si no encontro el id, sino retorna el indice cuyo id coincide con el buscado
int controller_getIndexEmployeeById(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	int auxId;
	int tamLista;
	Employee* pEmpleado;
	if(pArrayListEmployee!=NULL && id>0)
	{
		tamLista = ll_len(pArrayListEmployee);
		if(tamLista>0)
		{
			for(int i=0; i<tamLista; i++)
			{
				pEmpleado = ll_get(pArrayListEmployee, i);
				if(pEmpleado != NULL)
				{
					employee_getId(pEmpleado, &auxId);
					if(auxId == id)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	}
	return retorno;
}
