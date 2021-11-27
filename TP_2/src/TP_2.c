/*
 ============================================================================
 Name        : TP_2.c
 Author      : Gomez Iglesias, Emiliano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//libraries declaration
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "ArrayEmployees.h"
#define QUANTITY 1000

int main()
{
	setbuf(stdout,NULL);
    //variables declaration
    Employee arrayEmployees [QUANTITY];
    int employeeNumber;
    int state;
    int option;
    int subOption;
    int auxId;
    int flagOption;
    int account;
    float salary;
    float averageSalary;
    int salariesAboveAverage;
    int i;

    employeeNumber=1;
    flagOption=0;
    //struct array initialization
    initEmployees(arrayEmployees,QUANTITY);
   do
   {
	    fflush(stdin);
        system("cls");
        printf("\n>>>GESTION DE EMPLEADOS<<<\n");
        fflush(stdin);
        option = optionsMenu("[1] ALTAS","[2] MODIFICAR","[3] BAJA","[4] INFORMAR","[0] SALIR",0,4);
        while(option>1 && (flagOption==0 || countFullPositions(arrayEmployees, QUANTITY)==0))
        {
        	system("cls");
            printf("\nPrimero se deben ingresar empleados.\n");
            option = optionsMenu("[1] ALTAS","[2] MODIFICAR","[3] BAJA","[4] INFORMAR","[0] SALIR",0,4);
        }
        if(option == -1)
        {
        	printf("\nSe ingresaron demasiadas veces opciones incorrectas. Se termino el programa.\n");
        	system("pause");
        	option = 0;
        }
        system("cls");
        switch (option)
        {
            case 1:
                //Alta de empleados
                employeeNumber=askToAddEmployee(arrayEmployees,QUANTITY,employeeNumber);
                if(employeeNumber >0)
                {
                	printf("Se dieron de alta con exito %i", employeeNumber);
                }
                flagOption=1;
            break;
            case 2:
                system("cls");
                printf("\nMODIFICAR\n");
            	printEmployees(arrayEmployees, QUANTITY);
                CargarEntero(&auxId, "Ingrese el id del empleado a modificar: ", "El id ingresado es invalido.", 1, ID_MAX, 2);
                i = findEmployeeById(arrayEmployees, QUANTITY, auxId);
                if( i != -1)
                {
					printf("\nQue parametro desea modificar?\n");
					subOption = optionsMenu("  [1] Apellido\n","  [2] Nombre\n", "  [3] Sueldo\n", "  [4] Sector\n","  [0] Cancelar\n",0,4);
					state = modifyEmployee(arrayEmployees,QUANTITY,auxId, subOption);
                }
                else
                {
                	state = -1;
                	printf("No se encontro el empleado buscado.");
                }
                functionResult(-1,state,"No se concreto la modificacion del empleado.","El empleado se modifico exitosamente.");
                system("pause");
                fflush(stdin);
            break;
            case 3:
                system("cls");
                printf("\nBAJA\n");
                printEmployees(arrayEmployees, QUANTITY);
                CargarEntero(&auxId, "Ingrese el id del empleado a eliminar: ", "El id ingresado es invalido.", 1, ID_MAX, 2);
                i = findEmployeeById(arrayEmployees, QUANTITY, auxId);
                printOneEmployee(arrayEmployees[i]);
                if(i!=-1)
                {
					state=removeEmployee(arrayEmployees,QUANTITY,auxId);
                }
                else
                {
                	state = -1;
                	printf("\nNo se encontro el empleado ingresado.\n");
                }
				functionResult(-1,state,"No se concreto la eliminacion del empleado.","El empleado se elimino exitosamente.");
				system("pause");
				fflush(stdin);
            break;
            case 4:
                system("cls");
                printf("\nINFORMAR EMPLEADOS\n");
                subOption=optionsMenu("\n[1] Ordenar empleados.\n","[2] Salarios","[0] Volver"," ", " ",0,2);
                switch(subOption)
                {
                    case 1:
                        printf("\nCon que criterio desea mostrar el listado de empleados?\n");
                        subOption = optionsMenu("\n   [0] Descendente por nombre y sector.\n","\n   [1] Ascendente por nombre y sector.\n"," "," ", " ",0,1);
                        state=sortEmployees(arrayEmployees,QUANTITY,subOption);
                        functionResult(-1,state,"\nOcurrio un error al informar empleados\n","\nSe muestran los empleados segun el criterio seleccionado\n");
                        if (state != -1)
                        {
                            printEmployees(arrayEmployees,QUANTITY);
                        }
                    break;
                    case 2:
                        account=countFullPositions(arrayEmployees,QUANTITY);
                        salary = totalSalary(arrayEmployees,QUANTITY);
                        averageSalary = (float) salary/account;
                        salariesAboveAverage=accountAboveAverageEmployees(arrayEmployees, QUANTITY,averageSalary);
                        functionResult(-1,salariesAboveAverage,"\nERROR. No se pudo completar el informe de salarios.\n","\n>>INFORME DE SALARIOS<<\n");
                        printf("\nEl salario total es de %.2f, el salario promedio es de %.2f y hay  %d empleados cuyo salario supera al promedio.\n", salary, averageSalary, salariesAboveAverage);
                    break;
                    case 0:
                    	printf("Volviendo al menu\n");
					break;
                }
                system("pause");
                fflush(stdin);
            break;
            case 0:
                system("cls");
                printf("\nSALIDA DEL PROGRAMA\n");
                printf("\nUsted ha salido del programa.\n");

            	system("pause");
            	fflush(stdin);
            break;
        }
    }while (option != 0);
}

