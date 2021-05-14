/*
 ============================================================================
 Name        : TP2.c
 Author      : Emiliano Gomez Iglesias
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
	setbuf(stdout, NULL);
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

    employeeNumber=1;
    flagOption=0;
    //struct array initialization
    initEmployees(arrayEmployees,QUANTITY);
   do
   {
        //system("cls");
        printf("\n>>>GESTION DE EMPLEADOS<<<\n");
        option = optionsMenu("[1] ALTAS","[2] MODIFICAR","[3] BAJA","[4] INFORMAR",0,4);
        while(option>1&&flagOption==0)
        {
            printf("\nPrimero se deben ingresar empleados.\n");
            option = optionsMenu("[1] ALTAS","[2] MODIFICAR","[3] BAJA","[4] INFORMAR",1,4);
        }
        //system("cls");
        switch (option)
        {
            case 1:
                //Alta de empleados
                employeeNumber=askToAddEmployee(arrayEmployees,QUANTITY,employeeNumber);
                flagOption=1;
            break;
            case 2:
                //system("cls");
                printf("\nMODIFICAR\n");
                auxId=getInt("\nIngrese el numero de ID del empleado a modificar: ", "\nEl ID ingresado es invalido. Ingrese el numero de ID del empleado a modificar: ",1,ID_MAX);
                printf("\nQue parametro desea modificar?\n");
                subOption = optionsMenu("  [1] Apellido\n","  [2] Nombre\n", "  [3] Sueldo\n", "  [4] Sector\n",0,4);
                state = modifyEmployee(arrayEmployees,QUANTITY,auxId, subOption);
                functionResult(-1,state,"No se concreto la modificacion del empleado.","El empleado se modifico exitosamente.");
                //system("pause");
            break;
            case 3:
                //system("cls");
                printf("\nBAJA\n");
                auxId=getInt("\nIngrese el numero de ID del empleado a eliminar: ", "\nEl ID ingresado es invalido. Ingrese el numero de ID del empleado a eliminar: ",1,ID_MAX);
                state=removeEmployee(arrayEmployees,QUANTITY,auxId);
                functionResult(-1,state,"No se concreto la eliminacion del empleado.","El empleado se elimino exitosamente.");
                //system("pause");
                account = countFullPositions(arrayEmployees,QUANTITY);
                if(account==0)
                {
                    flagOption=0;
                }
            break;
            case 4:
                //system("cls");
                printf("\nINFORMAR EMPLEADOS\n");
                subOption=optionsMenu("\n[1] Ordenar empleados.\n","[2] Salarios"," "," ",1,2);
                switch(subOption)
                {
                    case 1:
                        printf("\nCon que criterio desea mostrar el listado de empleados?\n");
                        subOption = optionsMenu("\n   [0] Descendente por nombre y sector.\n","\n   [1] Ascendente por nombre y sector.\n"," "," ",0,1);
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
                        averageSalary = salary/account;
                        salariesAboveAverage=accountAboveAverageEmployees(arrayEmployees,account,averageSalary);
                        functionResult(-1,salariesAboveAverage,"\nERROR. No se pudo completar el informe de salarios.\n","\n>>INFORME DE SALARIOS<<\n");
                        printf("\nEl salario promedio es de $%.2f y hay  %d empleados cuyo salario supera al promedio.\n",averageSalary, salariesAboveAverage);
                    break;
                }
                //system("pause");
            break;
        }
    }while (option != 0);
}
