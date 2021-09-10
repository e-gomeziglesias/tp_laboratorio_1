/*
 * Aritmeticas.h
 *
 *  Created on: 10 sep. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#ifndef ARITMETICAS_H_
#define ARITMETICAS_H_




#endif /* ARITMETICAS_H_ */

//1.
/// @fn float SumarNumeros(float, float)
/// @brief Dados dos numeros flotantes, permite sumarlos
///
/// @param primerNumero primer sumando
/// @param segundoNumero segundo sumando
/// @return el resultado de la suma
float SumarNumeros(float primerNumero, float segundoNumero);

//2.
/// @fn float RestarNumeros(float, float)
/// @brief Dados dos numeros flotantes, permite efectuar la resta
///
/// @param primerNumero minuendo de la operacion
/// @param segundoNumero sustraendo de la operacion
/// @return el resultado de la resta
float RestarNumeros (float primerNumero, float segundoNumero);

//3.
/// @fn float MultiplicarNumeros(float, float)
/// @brief dados dos numeros flotantes, permite realizar la multiplicacion entre ambos
///
/// @param primerNumero primer miembro de la multiplicacion
/// @param segundoNumero segundo miembro de la multiplicacion
/// @return el producto de la multiplicacion
float MultiplicarNumeros (float primerNumero, float segundoNumero);

//4.
/// @fn float DividirNumeros(float, float)
/// @brief dados dos numeros, permite realizar la division siempre que el divisor sea distinto de cero
///
/// @param dividendo dividendo de la multiplicacion
/// @param divisor divisor de la multiplicacion. Se valida que sea distinto de cero
/// @return el resultado de la division
float DividirNumeros (float dividendo, float divisor);

//5.
/// @fn double FactorialNumero(float)
/// @brief Permite calcular el factorial de un numero entero positivo
///
/// @param numero numero entero positivo a calcularle el factorial
/// @return el factorial del numero
double FactorialNumero (float numero);

//6.
/// @fn int ValidarNumeroCero(float)
/// @brief permite validar si un numero es cero
///
/// @param numero numero a validar
/// @return 1 si el numero es 0; 0 si el numero es distinto de cero
int ValidarNumeroCero(float numero);

//7.
/// @fn int ValidarNumeroEnteroPositivo(float)
/// @brief permite validar si un numero es entero positivo
///
/// @param numero numero a validar
/// @return 1 si el numero es entero y positivo, 0 caso contrario.
int ValidarNumeroEnteroPositivo (float numero);
