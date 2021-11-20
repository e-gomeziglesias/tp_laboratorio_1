/*
 * Menu.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */

//1.
/// @fn int Menu_MostrarMenuPrincipalOpciones(void)
/// @brief Muestra el menu principal de opciones
///
/// @return La opcion elegida si ok, -1 si error
int Menu_MostrarMenuPrincipalOpciones (void);

//2.
/// @fn int Menu_MostrarMenuModificacionesEmpleados(void)
/// @brief Muestra el menu de opciones de modificaciones de clientes
///
/// @return La opcion elegida si ok, -1 si error
///
int Menu_MostrarMenuModificacionesEmpleados(void);

//3.
/// @fn int Menu_MostrarMenuListados(void)
/// @brief Muestra el menu de opciones de listados
///
/// @return La opcion elegida si ok, -1 si error
int Menu_MostrarMenuOrdenamiento(void);

//4.
/// @fn void Menu_AnalizarRetorno(int, char[], char[])
/// @brief permite imprimir mensajes por pantalla en funcion del valor de retorno de una funcion
///
/// @param retorno retorno que devuelve una funcion
/// @param mensaje mensaje de exito si el retorno es distinto de -1
/// @param mensajeError mensaje de error si el retorno es igual a -1
void Menu_AnalizarRetorno(int retorno, char mensaje[], char mensajeError[]);

//5.
/// @fn void Menu_AnalizarRetornoPunteros(void*, char[], char[])
/// @brief permite imprimir mensajes por pantalla en funcion del valor de retorno de una funcion que retorna punteros
///
/// @param retorno puntero retornado por una funcion
/// @param mensaje
/// @param mensajeError
void Menu_AnalizarRetornoPunteros(void* pRetorno, char mensaje[], char mensajeError[]);










/*
	//4.2
	/// @fn int Menu_MostrarMenuModificacionesTipo(void)
	/// @brief Muestra el menu de opciones de modificaciones de tipos
	///
	/// @return La opcion elegida si ok, -1 si error
	int Menu_MostrarMenuModificacionesTipo(void);

	//4.3
	/// @fn int Menu_MostrarMenuModificacionesNacionalidad(void)
	/// @brief Muestra el menu de opciones de modificaciones de nacionalidades
	///
	/// @return La opcion elegida si ok, -1 si error
	int Menu_MostrarMenuModificacionesNacionalidad(void);

	//6.
	/// @fn int Menu_MostrarMenuInformes(void)
	/// @brief Muestra el menu de opciones de informes
	///
	/// @return La opcion elegida si ok, -1 si error
	int Menu_MostrarMenuInformes(void);

	//4.
	/// @fn int Menu_MostrarMenuModificaciones(void)
	/// @brief Muestra el menu de opciones de modificaciones
	///
	/// @return La opcion elegida si ok, -1 si error
	int Menu_MostrarMenuModificaciones(void);


	//2.
	/// @fn int Menu_MostrarMenuAltas(void)
	/// @brief Muestra el menu de opciones de altas
	///
	/// @return La opcion elegida si ok, -1 si error
	int Menu_MostrarMenuAltas(void);

	//3.
	/// @fn int Menu_MostrarMenuBajas(void)
	/// @brief Muestra el menu de opciones de bajas
	///
	/// @return La opcion elegida si ok, -1 si error
	int Menu_MostrarMenuBajas(void);
*/
