/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: Emiliano Gomez Iglesias
 */

#define CHAR_LENGTH 51
#define MIN_SECTOR 1
#define MAX_SECTOR 100
#define MAX_SALARY 200000
#define ID_MAX 2000

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name [CHAR_LENGTH];
    char lastName[CHAR_LENGTH];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif /* ARRAYEMPLOYEES_H_ */


//prototypes

/** \brief To indicate that all position in the array are empty,
 * this function puts the flag (isEmpty) in TRUE in all the
 * positions of the array
 *
 * \param arrayEmployees[] Employee array of employees
 * \param len int array length
 * \return int returns (-1) if error (invalid length) - (0) if OK
 *
 */
int initEmployees(Employee arrayEmployees[],int len);

/** \brief finds an empty positition in a struct array
 *
 * \param Employee arrayEmployees is the array in which we want to find an empty positition
 * \param int len is the size of the array
 * \return (-1) if there aren't any empty positions or the number of the empty position if there is any.
 *
 */
int findEmptyPosition (Employee arrayEmployees[], int len);

/** \brief counts how many not empty positions the given array has
 *
 * \param employee arrayEmployees the array in which the occupied positions will be counted
 * \param len int length of the array
 * \return -1 if error or the number of the occupied positions.
 *
 */
int countFullPositions (Employee arrayEmployees[], int len);

/** \brief allows to enter an employee information and validates it.
 *
 * \param arrayEmployee[] Employee array of employees
 * \param len int length of the array in which we'll be adding the employees information
 * \param idEmployee int id number of the employee
 * \return int returns (-1) if error (invalid length or without free space) - 0 if OK
 *
 */
int enterEmployeeValidation(Employee arrayEmployee[], int len, int idEmployee);

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
int addEmployee(Employee arrayEmployees[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief Searches for an employee by its id in a struct array.
 *
 * \param arrayEmployee[] Employee array where we want to look for an employee by its id
 * \param len int length of the array
 * \param id int id of the employee we are trying to find
 * \return int position of the employee if found or -1 if error or not found.
 *
 */
int findEmployeeById(Employee arrayEmployee[], int len,int id);

/** \brief Removes an employee by entering its ID number (logical deletion)
 *
 * \param arrayEmployee[] Employee array in which the employee needs to be removed
 * \param len int length of the employee array
 * \param id int id of the employee that needs to be removed
 * \return int 0 if removed, -1 if error
 *
 */
int removeEmployee(Employee arrayEmployee[], int len, int id);

/** \brief orders an array acording to a given criteria.
 *
 * \param arrayEmployee[] Employee array to be ordered
 * \param len int number of elements in the array
 * \param order int 1 if increasing order - 0 if decreasing order
 * \return int 0 if ok -1 if error
 *
 */
int sortEmployees(Employee arrayEmployee[], int len, int order);

/** \brief prints the infomation saved in a struct array of employees
 *
 * \param arrayEmployee[] Employee array where the employees' information is saved
 * \param length int length of the array
 * \return int 0 if Ok, -1 if error.
 *
 */
int printEmployees(Employee arrayEmployee[], int length);

/** \brief asks to enter the information of another employee in a struct array
 *
 * \param arrayEmployees[] Employee array of employees where the entered information is saved
 * \param len int length of the employees array
 * \param employeeNumber int quantity of employees entered
 * \return int number of the employees succesfully added to the array
 *
 */
int askToAddEmployee(Employee arrayEmployees[], int len, int employeeNumber);

/** \brief allows to modify a wanted parameter of a employee by its id
 *
 * \param arrayEmployee[] Employee array in which a parameter is to be modified
 * \param len int length of the array
 * \param idEmployee int id of the employee to be modified
 * \param option int option of the parameter to be modified
 * \return int 0 if modified, -1 if error.
 *
 */
int modifyEmployee(Employee arrayEmployee[], int len, int idEmployee,int option);

/** \brief prints an option menu and asks to enter its option numbers
 *
 * \param char option1[] title for the option 1
 * \param char option2[] title for the option 2
 * \param char option3[] title for the option 3
 * \param char option4[] title for the option 4
 * \param int lowerOption lower option number
  * \param int upperOption higher option number
 * \return int the chosen option number
 *
 */
int optionsMenu (char option1[], char option2[], char option3[], char option4[],int lowerOption, int upperOption);

/** \brief makes the addition of available employees salaries from an array
 *
 * \param arrayEmployees[] Employee struct array in which the salaries can be found
 * \param len int length of the array
 * \return float the result of the sum if ok, -1 if error
 *
 */
float totalSalary(Employee arrayEmployees[],int len);

/** \brief Tells the user if the function worked properly or not
 *
 * \param error int condition for error
 * \param state int return of the function
 * \param errorMsg[] char error message if function failed
 * \param successMsg[] char success message if function succeded
 * \return int 0
 *
 */
int functionResult(int error, int state, char errorMsg[], char successMsg[]);

/** \brief counts how many employees from an array have above average salaries
 *
 * \param arrayEmployees[] Employee struct array to look for the information
 * \param len int size of the array
 * \param averageSalary float average salary
 * \return int -1 if error, the number of employees whom salaries are above average
 *
 */
int accountAboveAverageEmployees(Employee arrayEmployees[], int len, float averageSalary);
