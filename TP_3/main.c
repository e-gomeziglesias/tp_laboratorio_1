/*
 ============================================================================
 Name        : TP_3.c
 Author      : Gomez Iglesias, Emiliano
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Práctico 3

****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"

#define GUARDADO 1
#define SIN_GUARDAR 0
#define CARGADO 1
#define SIN_CARGAR 0

int main()
{
	setbuf(stdout,NULL);
	int opcion;
	LinkedList* listaEmpleados;
	int retorno;
	int flagSaveTxt=SIN_GUARDAR;
	int flagLoadTxt=SIN_CARGAR;
	int flagSaveBin=SIN_GUARDAR;
	int flagLoadBin=SIN_CARGAR;

	listaEmpleados = ll_newLinkedList();
	Menu_AnalizarRetornoPunteros(listaEmpleados, "NOTA: La lista se creo con exito", "NOTA: Ocurrio un error al crear la lista dinamica");
	printf("\n\n");

	if(listaEmpleados!=NULL)
	{
		do
		{
			opcion = Menu_MostrarMenuPrincipalOpciones();
			switch(opcion)
			{
				case 1://Cargar los datos de los empleados desde el archivo data.csv (modo texto).
					retorno = controller_loadFromText("data.csv", listaEmpleados);
					Menu_AnalizarRetorno(retorno, "Los empleados se cargaron exitosamente desde el archivo de texto", "No se pudieron cargar los empleados en la lista");
					flagLoadTxt = CARGADO;
					system("pause");
				break;
				case 2://Cargar los datos de los empleados desde el archivo data.bin (modo binario).
					retorno = controller_loadFromBinary("data.bin", listaEmpleados);
					Menu_AnalizarRetorno(retorno, "Los empleados se cargaron exitosamente desde el archivo binario", "No se pudieron cargar los empleados del archivo binario en la lista");
					flagLoadBin = CARGADO;
					system("pause");
				break;

				case 3://Alta de empleado
					if(flagLoadBin==SIN_CARGAR && flagLoadTxt == SIN_CARGAR)
					{
						printf("Primero debe cargar al programa el archivo de texto o el archivo binario.\n");
						system("pause");
						break;
					}
					else
					{
						retorno = controller_addEmployee(listaEmpleados);
						Menu_AnalizarRetorno(retorno, "El empleado fue dado de alta con exito.", "No se pudo concretar el alta del empleado");
						flagSaveTxt=SIN_GUARDAR;
						flagSaveBin=SIN_GUARDAR;
					}
					system("pause");
				break;

				case 4://Modificar datos de empleado
					if(flagLoadBin==SIN_CARGAR && flagLoadTxt == SIN_CARGAR)
					{
						printf("Primero debe cargar al programa el archivo de texto o el archivo binario.\n");
						system("pause");
						break;
					}
					else
					{
						retorno = controller_editEmployee(listaEmpleados);
						Menu_AnalizarRetorno(retorno, "Se modificaron con exito los campos elegidos.", "Uno o mas campos seleccionados no se modificaron");
						if(retorno == 0)
						{
							flagSaveTxt=SIN_GUARDAR;
							flagSaveBin=SIN_GUARDAR;
						}
					}
					system("pause");
				break;

				case 5://Baja de empleado
					if(flagLoadBin==SIN_CARGAR && flagLoadTxt == SIN_CARGAR)
					{
						printf("Primero debe cargar al programa el archivo de texto o el archivo binario.\n");
						system("pause");
						break;
					}
					else
					{
						retorno = controller_removeEmployee(listaEmpleados);
						Menu_AnalizarRetorno(retorno, " ", "No se completo la eliminacion de un empleado.");
						if(retorno == -2)
						{
							printf("No se encontro el empleado elegido.\n");
						}
						if(retorno == 0)
						{
							printf("Se elimino con exito el empleado.\n");
							flagSaveTxt=SIN_GUARDAR;
							flagSaveBin=SIN_GUARDAR;
						}
					}
					system("pause");
				break;

				case 6://Listar empleados
					retorno = controller_ListEmployee(listaEmpleados);
					Menu_AnalizarRetorno(retorno, "Se muestra el listado de empleados", "No se pudo mostrar el listado de empleados");
					system("pause");
				break;

				case 7://Ordenar empleados
					if(flagLoadBin==SIN_CARGAR && flagLoadTxt == SIN_CARGAR)
					{
						printf("Primero debe cargar al programa el archivo de texto o el archivo binario.\n");
						system("pause");
						break;
					}
					else
					{
						retorno = controller_sortEmployee(listaEmpleados);
						Menu_AnalizarRetorno(retorno, "Se ordeno la lista segun el criterio elegido", "No se pudo completar el ordenamiento.");
					}
					system("pause");
				break;

				case 8://Guardar los datos de los empleados en el archivo data.csv (modo texto).
					retorno = controller_saveAsText("data.csv", listaEmpleados);
					Menu_AnalizarRetorno(retorno, "El listado de empleados se guardo con exito (.csv).", "No se pudo guardar el listado (.csv).");
					flagSaveTxt = GUARDADO;
					system("pause");
				break;

				case 9://Guardar los datos de los empleados en el archivo data.bin (modo binario).
						retorno = controller_saveAsBinary("data.bin", listaEmpleados);
						Menu_AnalizarRetorno(retorno, "El listado de empleados se guardo con exito (.bin).", "No se pudo guardar el listado (.bin).");
						flagSaveBin = GUARDADO;
					system("pause");
				break;

				case 10://Salir
					if(flagSaveBin == SIN_GUARDAR)
					{
						printf("No ha guardado las modificaciones en el archivo binario.\n");
						system("pause");
						break;
					}
					if(flagSaveTxt == SIN_GUARDAR)
					{
						printf("No ha guardado las modificaciones en el archivo de texto.\n");
						system("pause");
						break;
					}
					printf("Usted ha salido del programa.\n");
					system("pause");
				break;
			}
		}while(opcion != 0);
	}
    return EXIT_SUCCESS;
}
