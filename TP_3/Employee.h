#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "File.h"

#define TAM_NOMBRE 128
#define MAX_SUELDO 500000
#define MAX_ID 100000

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[TAM_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

//1.
/// @fn Employee employee_new*()
/// @brief Permite crear el espacio en memoria dinamica para un nuevo empleado e inicializa todos los campos en cero
///
/// @return el puntero al nuevo empleado
Employee* employee_new();

//2
/// @fn Employee* employee_newParametros(char*, char*, char*, char*)
/// @brief Permite crear un nuevo empleado, cargando todos sus campos por parametro. Todos los parametros los recibe como cadena
///
/// @param idStr id del empleado
/// @param nombreStr nombre del empleado
/// @param horasTrabajadasStr horas trabajadas del empleado
/// @param sueldoStr sueldo del empleado
/// @return 0 si ok, -1 si error
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

//3.
/// @fn void employee_delete(Employee*)
/// @brief Permite borrar un empleado. Elimina el puntero al mismo
///
/// @param pEmpleado puntero al empleado a eliminar
void employee_delete(Employee* pEmpleado);

//4.
/// @fn int employee_setId(Employee*, int)
/// @brief Permite cargar el id de un empleado
///
/// @param this puntero al empleado
/// @param id id a cargar
/// @return 0 si ok, -1 si error
int employee_setId(Employee* this,int id);

//5.
/// @fn int employee_getId(Employee*, int*)
/// @brief permite recuperar el id de un empleado cargado
///
/// @param this puntero al empleado
/// @param id puntero a la variable donde se recuperará el id
/// @return 0 si ok, -1 si error
int employee_getId(Employee* this,int* id);

//6.
/// @fn int employee_setNombre(Employee*, char*)
/// @brief permite cargar el nombre de un empleado en la estructura empleado
///
/// @param this puntero a la estructura empleado
/// @param nombre nombre del empleado
/// @return 0 si ok, -1 si error
int employee_setNombre(Employee* this,char* nombre);

//7.
/// @brief permite recuperar el nombre de un empleado cargado
///
/// @param this puntero al empleado
/// @param id puntero a la cadena donde se recuperará el nombre
/// @return 0 si ok, -1 si error
int employee_getNombre(Employee* this,char* nombre);

//8.
/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief Permite cargar las horas trabajadas de un cliente en la estructra employee
///
/// @param this puntero a la estructura
/// @param horasTrabajadas horas a cargar
/// @return 0 si ok, -1 si error
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

//9.
/// @brief permite recuperar las horas trabajadas de un empleado cargado
///
/// @param this puntero al empleado
/// @param id puntero a la variable donde se recuperarán las horas trabajadas.
/// @return 0 si ok, -1 si error
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

//10.
/// @brief permite cargar el sueldo de un empleado cargado
///
/// @param this puntero al empleado
/// @param sueldo a cargar en el empleado
/// @return 0 si ok, -1 si error
int employee_setSueldo(Employee* this,int sueldo);

//11.
/// @fn int employee_getSueldo(Employee*, int*)
/// @brief permite recuperar el sueldo de un empleado
///
/// @param this puntero a la estructura employee
/// @param sueldo puntero a la variable donde se recuperara el sueldo
/// @return 0 si ok, -1 si error
int employee_getSueldo(Employee* this,int* sueldo);

//12.
/// @fn int employee_CompareByName(void*, void*)
/// @brief permite comparar los campos nombre de dos empleados, recibidos como punteros a void
///
/// @param puntero a void del primer empleado
/// @param puntero a void del segundo empleado
/// @return 0 si son iguales, -1 si el nombre del segundo es menor que el primero, 1 si nombre el segundo es mayor que el primero.
int employee_CompareByName(void*, void*);

//13.
/// @fn int employee_CompareById(void*, void*)
/// @brief permite comparar los campos id de dos empleados, recibidos como punteros a void
///
/// @param puntero a void del primer empleado
/// @param puntero a void del segundo empleado
/// @return 0 si los ids son iguales, -1 si el id del segundo es menor que el primero, 1 si el id del segundo es mayor que el primero.
int employee_CompareById(void*, void*);

//14.
/// @fn int isValidId(char*)
/// @brief permite validar un Id, recibido como cadena
///
/// @param idStr id a validar
/// @return 0 si es valido, -1 si no lo es
int isValidId(char* idStr);

//15.
/// @fn int isValidNombre(char*)
/// @brief /// @brief permite validar un nombre, recibido como cadena
///
/// @param nombreStr nombre a validar
/// @return 0 si es valido, -1 si no lo es
///
/// @param nombreStr
/// @return
int isValidNombre(char* nombreStr);

//16.
/// @fn int isValidHorasTrabajadas(char*)
/// @brief permite validar las horas trabajadas, recibido como cadena
///
/// @param horasTrabajadasStr horas a validar
/// @return 0 si es valido, -1 si no lo es
int isValidHorasTrabajadas(char* horasTrabajadasStr);

//17.
/// @fn int isValidSueldo(char*)
/// @brief permite validar un sueldo, recibido como cadena
///
/// @param sueldoStr sueldo a validar
/// @return 0 si es valido, -1 si no lo es
int isValidSueldo(char* sueldoStr);

//18.
/// @fn int employee_CargarNombre(char*)
/// @brief Permite cargar el nombre de un empleado
///
/// @param nombre puntero al array donde se guardara el nombre cargado
/// @return 0 si ok, -1 si error
int employee_CargarNombre(char* nombre);

//19.
/// @fn int employee_CargarHorasTrabajadas(int*)
/// @brief permite cargar las horas trabajadas por un empleado
///
/// @param pHorasTrabajadas puntero a la variable donde se guardaran las horas cargadas
/// @return 0 si ok, -1 si error
int employee_CargarHorasTrabajadas(int* pHorasTrabajadas);

//20.
/// @fn int employee_CargarSueldo(int*)
/// @brief permite cargar el sueldo de un empleado
///
/// @param pSueldo puntero a la variable donde se guardara el sueldo cargado
/// @return 0 si ok, -1 si error
int employee_CargarSueldo(int* pSueldo);

//21.
/// @fn int employee_CargarId(int*)
/// @brief permite cargar un id a un empleado desde un archivo de texto
///
/// @param pId puntero a la variable donde se guardara el id
/// @return 0 si ok, -1 si error
int employee_CargarId(int* pId);

//22.
/// @fn int employee_setEmployee(Employee*, int, char*, int, int)
/// @brief permite setear todos los campos de un empleado
///
/// @param pEmpleado puntero a la variable empleado donde se cargaran los campos
/// @param id id a setearle al empleado
/// @param nombre nombre a setearle al empleado
/// @param horasTrabajadas horas trabajadas a setearle al empleado
/// @param sueldo sueldo a setearle al empleado
/// @return 0 si ok, -1 si error
int employee_setEmployee(Employee* pEmpleado, int id, char* nombre, int horasTrabajadas, int sueldo);

#endif // employee_H_INCLUDED

