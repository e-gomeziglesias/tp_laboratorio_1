/*
 * ArrayEmployees.c
 *
 *  Created on: 14 may. 2021
 *      Author: Emiliano Gomez Iglesias
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "ArrayEmployees.h"

int initEmployees(Employee arrayEmployees[],int len)
{
    int i;
    int one;
    int returning;
    one =1;
    returning = -1;
    if(len > 0 && arrayEmployees != NULL)
    {
        for (i=0; i<len; i++)
        {
            arrayEmployees[i].isEmpty=one;
        }
        returning = 0;
    }
    return returning;
}

int findEmptyPosition (Employee arrayEmployees[], int len)
{
    int i;
    int returning;
    returning = -1;
    if(len > 0 && arrayEmployees != NULL)
    {
        for (i=0; i<len; i++)
        {
            if (arrayEmployees[i].isEmpty==1)
            {
                returning = i;
                break;
            }
        }
    }
    return returning;
}

int countFullPositions (Employee arrayEmployees[], int len)
{
    int i;
    int returning;
    int account;
    returning = -1;
    account = 0;
    if(len > 0 && arrayEmployees != NULL)
    {
        for (i=0; i<len; i++)
        {
            if (arrayEmployees[i].isEmpty==0)
            {
                account++;
            }
        }
        returning = account;
    }
    return returning;
}

int enterEmployeeValidation(Employee arrayEmployee[], int len, int idEmployee)
{
    Employee auxEmployee;
    int returning;
    int emptyPosition;
    returning = -1;

    emptyPosition=findEmptyPosition(arrayEmployee,len);
    if (len > 0 && (idEmployee >0 && idEmployee<ID_MAX) && arrayEmployee != NULL && emptyPosition != -1)
    {
        //copy given employee id
        auxEmployee.id=idEmployee;
        //enter last name
        getString(auxEmployee.lastName,"\nIngrese apellido del empleado: ", "\nApellido invalido. Ingrese apellido del empleado: ", CHAR_LENGTH);
        //enter name
        getString(auxEmployee.name,"\nIngrese nombre del empleado: ", "\nNombre invalido. Ingrese nombre del empleado: ", CHAR_LENGTH);
        //enter salary
        auxEmployee.salary = getFloat("\nIngrese sueldo del empleado: ", "\nEl sueldo ingresado en invalido o supera los rangos permitidos. Ingrese sueldo: ",1,MAX_SALARY);
        //enter sector number
        auxEmployee.sector = getInt("\nIngrese el numero del sector del empleado: ", "\nEl numero del sector seleccionado es invalido. Ingrese el numero de sector del empleado: ",MIN_SECTOR, MAX_SECTOR);
        returning = addEmployee(arrayEmployee,len,auxEmployee.id, auxEmployee.name, auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector);
    }

    return returning;
}

int addEmployee(Employee arrayEmployees[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int returning;
    returning = -1;
    i=findEmptyPosition(arrayEmployees,len);
    if (len > 0 && i!=-1 && arrayEmployees != NULL)
    {
        arrayEmployees[i].id=id;
        strcpy(arrayEmployees[i].name,name);
        strcpy(arrayEmployees[i].lastName,lastName);
        arrayEmployees[i].salary=salary;
        arrayEmployees[i].sector=sector;
        arrayEmployees[i].isEmpty=0;
        returning = 0;
    }
    return returning;
}

int findEmployeeById(Employee arrayEmployee[], int len,int id)
{
    int i;
    int returning;
    returning = -1;

    if (len > 0 && (id>0 && id<ID_MAX)&& arrayEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            if (id==arrayEmployee[i].id)
            {
                returning = i;
                break;
            }
        }
    }
    return returning;
}

int removeEmployee(Employee arrayEmployee[], int len, int id)
{
    int i;
    int returning;
    returning = -1;
    if( len >0 && (id >0 && id<ID_MAX)&& arrayEmployee != NULL)
    {
        i=findEmployeeById(arrayEmployee,len,id);
        arrayEmployee[i].isEmpty=1;
        returning = i;
    }
    return returning;
}

int sortEmployees(Employee arrayEmployee[], int len, int order)
{
    int i;
    int j;

    Employee aux;
    int returning;
    returning = -1;
    if (len > 0 && arrayEmployee != NULL)
    {
        switch(order)
        {
            case 1: //increasing order
                for(i=0;i<len-1;i++)
                {
                    for (j=i+1;j<len;j++)
                    {
                        if(stricmp(arrayEmployee[j].lastName,arrayEmployee[i].lastName)<0)
                        {
                            aux=arrayEmployee[i];
                            arrayEmployee[i]=arrayEmployee[j];
                            arrayEmployee[j]=aux;
                        }
                        else if(stricmp(arrayEmployee[j].lastName,arrayEmployee[i].lastName)==0&&(arrayEmployee[j].sector<arrayEmployee[i].sector))
                        {
                            aux=arrayEmployee[i];
                            arrayEmployee[i]=arrayEmployee[j];
                            arrayEmployee[j]=aux;
                        }
                    }
                }

            break;

            case 0://decreasing order
                for(i=0;i<len-1;i++)
                {
                    for (j=i+1;j<len;j++)
                    {
                        if(stricmp(arrayEmployee[j].lastName,arrayEmployee[i].lastName)>0)
                        {
                            aux=arrayEmployee[i];
                            arrayEmployee[i]=arrayEmployee[j];
                            arrayEmployee[j]=aux;
                        }
                        else if(stricmp(arrayEmployee[j].lastName,arrayEmployee[i].lastName)==0&&(arrayEmployee[j].sector>arrayEmployee[i].sector))
                        {
                            aux=arrayEmployee[i];
                            arrayEmployee[i]=arrayEmployee[j];
                            arrayEmployee[j]=aux;
                        }
                    }
                }
            break;
        }
        returning = 0;
    }
    return returning;
}

int printEmployees(Employee arrayEmployee[], int length)
{
    int returning;
    int i;
    char title1[10];
    char title2[10];
    char title3[10];
    char title4[10];
    char title5[10];
    strcpy(title1,"ID");
    strcpy(title2,"Apellido");
    strcpy(title3,"Nombre");
    strcpy(title4,"Sector");
    strcpy(title5,"Sueldo");
    returning = -1;
    if (length >0) //&& arrayEmployee != NULL)
    {
        printf("\n%-10s %-10s %-10s %-10s %-10s\n",title1,title2,title3,title4,title5);
        for (i=0; i<length; i++)
        {
            if(arrayEmployee[i].isEmpty==0)
            {
                printf("\n%-10d %-10s %-10s %-10d %-10.2f",arrayEmployee[i].id,arrayEmployee[i].lastName,arrayEmployee[i].name,arrayEmployee[i].sector,arrayEmployee[i].salary);
            }
        }
        returning = 0;
    }
    return returning;
}

int askToAddEmployee(Employee arrayEmployees[], int len, int employeeNumber)
{
    int state;
    char answer;
    if(len>0 && employeeNumber>0 && arrayEmployees != NULL)
    {
        do
        {
            system("cls");
            printf("\nALTA\n");

            state=enterEmployeeValidation(arrayEmployees,len,employeeNumber);
            if (state == 0)
            {
                employeeNumber++;
            }
            else
            {
                printf("\nNo hay mas espacio disponible para agregar empleados.\n");
            }
            answer = getUpperChar("\nDesea ingresar otro empleado? ('S' o 'N'): ");
        }while(answer !='N');
    }
    return employeeNumber;
}

int modifyEmployee(Employee arrayEmployee[], int len, int idEmployee,int option)
{
    int i;
    int returning;
    Employee auxEmployee;

    returning = -1;
    if( len> 0 && (idEmployee > 0 && idEmployee<ID_MAX)&& arrayEmployee != NULL)
    {
        i=findEmployeeById(arrayEmployee,len,idEmployee);
        switch (option)
        {
            case 1://modify Last name
                //enter last name
                getString(auxEmployee.lastName,"\nIngrese apellido del empleado: ", "\nApellido invalido. Ingrese apellido del empleado: ", CHAR_LENGTH);
                strcpy(arrayEmployee[i].lastName,auxEmployee.lastName);
            break;
            case 2:
                //enter name
                getString(auxEmployee.name,"\nIngrese nombre del empleado: ", "\nNombre invalido. Ingrese nombre del empleado: ", CHAR_LENGTH);
                strcpy(arrayEmployee[i].name,auxEmployee.name);
            break;
            case 3:
                //enter salary
                auxEmployee.salary = getFloat("\nIngrese sueldo del empleado: ", "\nEl sueldo ingresado en invalido o supera los rangos permitidos. Ingrese sueldo: ",1,MAX_SALARY);
                arrayEmployee[i].salary = auxEmployee.salary;
            break;
            case 4:
                //enter sector number
                auxEmployee.sector = getInt("\nIngrese el numero del sector del empleado: ", "\nEl numero del sector seleccionado es invalido. Ingrese el numero de sector del empleado: ",MIN_SECTOR, MAX_SECTOR);
                arrayEmployee[i].sector=auxEmployee.sector;
            break;
            case 0:
                printf("\nSe ha salido del menu de modificacion empleados\n");
            break;
        }
        if (option !=0)
        {
            returning=0;
        }
    }
    return returning;
}

int optionsMenu (char option1[], char option2[], char option3[], char option4[],int lowerOption, int upperOption)
{
    int optionNumber;
    printf("\n%s\n", option1);
    printf("\n%s\n", option2);
    printf("\n%s\n", option3);
    printf("\n%s\n", option4);
    printf("\n");
    optionNumber = getInt("\nIngrese la opcion deseada: ","\nLa opcion ingresada es incorrecta. Ingrese la opcion deseada: ",lowerOption,upperOption);
    return optionNumber;
}

float totalSalary(Employee arrayEmployees[],int len)
{
    int i;
    float sum;
    int returning;

    returning = -1;
    sum = 0;
    if (len > 0 && arrayEmployees != NULL)
    {
        for (i=0;i<len;i++)
        {
            if (arrayEmployees[i].isEmpty==0)
            {
                sum = sum + arrayEmployees[i].salary;
            }
        }
        returning = sum;
    }
    return returning;
}

int functionResult(int error, int state, char errorMsg[], char successMsg[])
{
    int returning;
    if (state == error)
    {
        printf("\n%s\n",errorMsg);
    }
    else
    {
        printf("\n%s\n",successMsg);
    }
    returning = 0;
    return returning;
}

int accountAboveAverageEmployees(Employee arrayEmployees[], int len, float averageSalary)
{
    int i;
    int returning;
    int aboveAverage;
    returning = -1;
    aboveAverage=0;

    if (len >0 && arrayEmployees != NULL)
    {
        for (i=0; i<len;i++)
        {
            if (arrayEmployees[i].salary>averageSalary)
            {
                aboveAverage++;
            }
        }
        returning = aboveAverage;
    }
    return returning;
}

