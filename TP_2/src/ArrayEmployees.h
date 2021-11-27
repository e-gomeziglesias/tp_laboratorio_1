/*
 * ArrayEmployees.h
 *
 *  Created on: 5 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



#endif /* ARRAYEMPLOYEES_H_ */



#define CHAR_LENGTH 51
#define MIN_SECTOR 1
#define MAX_SECTOR 100
#define MAX_SALARY 200000
#define MIN_SALARY 10000
#define ID_MAX 2000

typedef struct
{
    int id;
    char name [CHAR_LENGTH];
    char lastName[CHAR_LENGTH];
    float salary;
    int sector;
    int isEmpty;
} Employee;

//prototypes
int countFullPositions (Employee arrayEmployees[], int len);
int initEmployees(Employee arrayEmployees[],int len);
int findEmptyPosition (Employee arrayEmployees[], int len);
int enterEmployeeValidation(Employee arrayEmployee[], int len, int idEmployee);
int addEmployee(Employee arrayEmployees[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee arrayEmployee[], int len,int id);
int removeEmployee(Employee arrayEmployee[], int len, int id);
int sortEmployees(Employee arrayEmployee[], int len, int order);
int printEmployees(Employee arrayEmployee[], int length);
int printOneEmployee(Employee oneEmployee);
int askToAddEmployee(Employee arrayEmployees[], int len, int employeeNumber);
int modifyEmployee(Employee arrayEmployee[], int len, int idEmployee,int option);
int optionsMenu (char option1[], char option2[], char option3[], char option4[], char option0[], int lowerOption, int upperOption);
int functionResult(int error, int state, char errorMsg[], char successMsg[]);
float totalSalary(Employee arrayEmployees[],int len);
int accountAboveAverageEmployees(Employee arrayEmployees[], int len, float averageSalary);
