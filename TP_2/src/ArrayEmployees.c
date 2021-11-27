/*
 * ArrayEmployees.c
 *
 *  Created on: 5 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Input.h"
#include "ArrayEmployees.h"


/** \brief To indicate that all position in the array are empty,
 * this function puts the flag (isEmpty) in TRUE in all the
 * positions of the array
 *
 * \param arrayEmployees[] Employee array of employees
 * \param len int array length
 * \return int returns (-1) if error (invalid length) - (0) if OK
 *
 */
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


/** \brief finds an empty positition in a struct array
 *
 * \param Employee arrayEmployees is the array in which we want to find an empty positition
 * \param int len is the size of the array
 * \return (-1) if there aren't any empty positions or the number of the empty position if there is any.
 *
 */
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



/** \brief counts how many not empty positions the given array has
 *
 * \param employee arrayEmployees the array in which the occupied positions will be counted
 * \param len int length of the array
 * \return -1 if error or the number of the occupied positions.
 *
 */
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
/** \brief allows to enter an employee information and validates it.
 *
 * \param arrayEmployee[] Employee array of employees
 * \param len int length of the array in which we'll be adding the employees information
 * \param idEmployee int id number of the employee
 * \return int returns (-1) if error (invalid length or without free space) - 0 if OK
 *
 */

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
        printf("Id del nuevo empleado: %d\n", auxEmployee.id);
        //enter last name
        if(CargarStringNormalizado(auxEmployee.lastName, CHAR_LENGTH, "Ingrese el apellido del empleado: ", "El apellido ingresado es invalido.", 0, 2)==0)
        {
			//enter name
			if(CargarStringNormalizado(auxEmployee.name, CHAR_LENGTH, "Ingrese el nombre del empleado: ", "El nombre ingresado es invalido.", 0, 2)==0)
			{
				//enter salary
				if(CargarFlotante(&(auxEmployee.salary), "Ingrese el sueldo del empleado ($10000- $200000): ", "El sueldo ingresado es invalido.", MIN_SALARY, MAX_SALARY, 2)==0)
				{
					//enter sector number
					if(CargarEntero(&(auxEmployee.sector), "Ingrese el numero del sector: ", "El sector ingresado es invalido.", MIN_SECTOR, MAX_SECTOR, 2)==0)
					{
						printOneEmployee(arrayEmployee[emptyPosition]);
						returning = addEmployee(arrayEmployee,len,auxEmployee.id, auxEmployee.name, auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector);
					}
				}
			}
        }
    }

    return returning;
}

/** \brief Adds/Updates the information of an employee in the arrayEmployees array
 *
 * \param arrayEmployees[] Employee array in which the information will be updated
 * \param len int size of the employee array
 * \param id int id of the employee
 * \param name[] char name of the employee
 * \param lastName[] char last name of the employee
 * \param salary float salary of the employee
 * \param sector int sector of the employee
 * \return int 0 if ok, -1 if error(not available space or invalid array length)
 *
 */
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


/** \brief Searches for an employee by its id in a struct array.
 *
 * \param arrayEmployee[] Employee array where we want to look for an employee by its id
 * \param len int length of the array
 * \param id int id of the employee we are trying to find
 * \return int position of the employee if found or -1 if error or not found.
 *
 */
int findEmployeeById(Employee arrayEmployee[], int len,int id)
{
    int i;
    int returning;
    returning = -1;

    if (len > 0 && (id>0 && id<ID_MAX)&& arrayEmployee != NULL)
    {
        for(i=0; i<len; i++)
        {
            if (id==arrayEmployee[i].id && arrayEmployee[i].isEmpty==0)
            {
                returning = i;
                break;
            }
        }
    }
    return returning;
}

/** \brief Removes an employee by entering its ID number (logical deletion)
 *
 * \param arrayEmployee[] Employee array in which the employee needs to be removed
 * \param len int length of the employee array
 * \param id int id of the employee that needs to be removed
 * \return int 0 if removed, -1 if error
 *
 */
int removeEmployee(Employee arrayEmployee[], int len, int id)
{
    int i;
    int returning;
    char confirmation = 'n';
    returning = -1;
    if( len >0 && (id >0 && id<ID_MAX)&& arrayEmployee != NULL)
    {
    	if((CargarChar(&confirmation, "Desea eliminar al empleado? ('s' - 'n'): ", "La respuesta ingresada es invalida.", 0, 2) != -1) && (confirmation == 's'))
    	{
			i=findEmployeeById(arrayEmployee,len,id);
			arrayEmployee[i].isEmpty=1;
			printOneEmployee(arrayEmployee[i]);
			returning = i;
			fflush(stdin);
    	}
    }
    return returning;
}


/** \brief orders an array acording to a given criteria.
 *
 * \param arrayEmployee[] Employee array to be ordered
 * \param len int number of elements in the array
 * \param order int 1 if increasing order - 0 if decreasing order
 * \return int 0 if ok -1 if error
 *
 */
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


/** \brief prints the infomation saved in a struct array of employees
 *
 * \param arrayEmployee[] Employee array where the employees' information is saved
 * \param length int length of the array
 * \return int 0 if Ok, -1 if error.
 *
 */
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
        printf("\n%-10s %-20s %-20s %-10s %-10s\n",title1,title2,title3,title4,title5);
        for (i=0; i<length; i++)
        {
        	printOneEmployee(arrayEmployee[i]);
        }
        returning = 0;
    }
    return returning;
}

/** \brief prints the infomation of one employee
 *
 * \param oneEmployee employee which information is going to be shown
 *
 */
int printOneEmployee(Employee oneEmployee)
{
	int returning = -1;
    if(oneEmployee.isEmpty==0)
    {
        printf("%-10d %-20s %-20s %-10d %-10.2f\n", oneEmployee.id, oneEmployee.lastName, oneEmployee.name, oneEmployee.sector, oneEmployee.salary);
        returning = 0;
    }
    return returning;
}
/** \brief asks to enter the information of another employee in a struct array
 *
 * \param arrayEmployees[] Employee array of employees where the entered information is saved
 * \param len int length of the employees array
 * \param employeeNumber int quantity of employees entered
 * \return int number of the employees succesfully added to the array
 *
 */
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
                printf("\nNo se pudo cargar el empleado.\n");
            }
            CargarChar(&answer, "Desea ingresar otro empleado? ('S' o 'N'): ", "Ha ingresado una respuesta invalida.", 1, 2);
        }while(answer !='N');
    }
    return employeeNumber;
}

/** \brief allows to modify a wanted parameter of a employee by its id
 *
 * \param arrayEmployee[] Employee array in which a parameter is to be modified
 * \param len int length of the array
 * \param idEmployee int id of the employee to be modified
 * \param option int option of the parameter to be modified
 * \return int 0 if modified, -1 if error.
 *
 */
int modifyEmployee(Employee arrayEmployee[], int len, int idEmployee,int option)
{
    int i;
    int returning;
    Employee auxEmployee;

    returning = -1;
    if( len> 0 && (idEmployee > 0 && idEmployee<ID_MAX)&& arrayEmployee != NULL)
    {
        i=findEmployeeById(arrayEmployee,len,idEmployee);
        system("cls");
        printOneEmployee(arrayEmployee[i]);
        switch (option)
        {
            case 1://modify Last name
                //enter last name
            	if(CargarStringNormalizado(auxEmployee.lastName, CHAR_LENGTH, "Ingrese el apellido del empleado: ", "El apellido ingresado es invalido.", 0, 2)==0)
            	{
            		strcpy(arrayEmployee[i].lastName,auxEmployee.lastName);
            		printOneEmployee(arrayEmployee[i]);
            	}
            	else
            	{
            		option = 0;
            	}
            break;
            case 2:
                //enter name
            	if(CargarStringNormalizado(auxEmployee.name, CHAR_LENGTH, "Ingrese el nombre del empleado: ", "El nombre ingresado es invalido.", 0, 2)==0)
            	{
            		strcpy(arrayEmployee[i].name,auxEmployee.name);
            		printOneEmployee(arrayEmployee[i]);
            	}
            	else
            	{
            		option = 0;
            	}

            break;
            case 3:
                //enter salary
            	if(CargarFlotante(&(auxEmployee.salary), "Ingrese el sueldo del empleado ($10000- $200000): ", "El sueldo ingresado es invalido.", MIN_SALARY, MAX_SALARY, 2)==0)
            	{
            		arrayEmployee[i].salary = auxEmployee.salary;
            		printOneEmployee(arrayEmployee[i]);
            	}
            	else
            	{
            		option = 0;
            	}
            break;
            case 4:
                //enter sector number
            	if(CargarEntero(&(auxEmployee.sector), "Ingrese el numero del sector: ", "El sector ingresado es invalido.", MIN_SECTOR, MAX_SECTOR, 2)==0)
            	{
            		arrayEmployee[i].sector=auxEmployee.sector;
            		printOneEmployee(arrayEmployee[i]);
            	}
            	else
            	{
            		option = 0;
            	}
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


/** \brief prints an option menu and asks to enter its option numbers
 *
 * \param char option1[] title for the option 1
 * \param char option2[] title for the option 2
 * \param char option3[] title for the option 3
 * \param char option4[] title for the option 4
 * \param char option0[] title for the option 0
 * \param int lowerOption lower option number
  * \param int upperOption higher option number
 * \return int the chosen option number
 *
 */
int optionsMenu (char option1[], char option2[], char option3[], char option4[], char option0[], int lowerOption, int upperOption)
{
    int optionNumber = -1;
    printf("\n%s\n", option1);
    printf("\n%s\n", option2);
    printf("\n%s\n", option3);
    printf("\n%s\n", option4);
    printf("\n%s\n", option0);
    printf("\n");
    fflush(stdin);
    CargarEntero(&optionNumber, "Ingrese la opcion deseada: ", "La opcion ingresada es invalida.", lowerOption, upperOption, 2);
    fflush(stdin);
    return optionNumber;
}

/** \brief makes the addition of available employees salaries from an array
 *
 * \param arrayEmployees[] Employee struct array in which the salaries can be found
 * \param len int length of the array
 * \return float the result of the sum if ok, -1 if error
 *
 */
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

/** \brief Tells the user if the function worked properly or not
 *
 * \param error int condition for error
 * \param state int return of the function
 * \param errorMsg[] char error message if function failed
 * \param successMsg[] char success message if function succeded
 * \return int 0
 *
 */
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


/** \brief counts how many employees from an array have above average salaries
 *
 * \param arrayEmployees[] Employee struct array to look for the information
 * \param len int size of the array
 * \param averageSalary float average salary
 * \return int -1 if error, the number of employees whom salaries are above average
 *
 */
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
            if (arrayEmployees[i].salary>averageSalary && arrayEmployees[i].isEmpty == 0)
            {
                aboveAverage++;
                printOneEmployee(arrayEmployees[i]);
            }
        }
        returning = aboveAverage;
    }
    return returning;
}
