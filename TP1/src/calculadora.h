#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED



#endif // CALCULADORA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/** \brief Muestra el menu de opciones de una calculadora cuando aún no se ingresó ningún operando
 *
 * \param pOpcion int* puntero donde se guarda la opcion elegida
 * \return int 1 si se pudo elegir la opcion, '0 si ocurrio algun error
 *
 */
int menuOpciones0(int* pOpcion);

/** \brief Muestra el menu de opciones de una calculadora cuando se ingresó sólo el primer operando.
 *
 * \param pOpcion int* puntero donde se guarda la opcion elegida
 * \param operando1 float primer operando ingresado
 * \return int 1 si se pudo elegir la opcion, 0 si ocurrió algún error.
 *
 */
int menuOpciones1(int* pOpcion, float operando1);

/** \brief Muestra el menu de opciones de una calculadora cuando se ingresaron los dos operandos
 *
 * \param pOpcion int* puntero donde se guarda la opcion elegida
 * \param operando1 float primer operando ingresado
 * \param operando2 float segundo operando ingresado
 * \return int 1 si se pudo elegir la opcion, 0 si ocurrió algún error.
 *
 */
int menuOpciones2(int* pOpcion, float operando1, float operando2);

/** \brief Permite el ingreso del primer operando float por consola y lo guarda, sin validarlo como numero.
 *
 * \param pOperando1 float* puntero al primer operando ingresado
 * \param pFlagOperando int* puntero a la bandera que indica si se ingresó el primer operando
 * \return int 1 si se guardo con exito, 0 si no se pudo guardar
 *
 */
int getPrimerOperandoFloat(float* pOperando1, int* pFlagOperando);

/** \brief Permite el ingreso del segundo operando float por consola y lo guarda, sin validarlo como numero.
 *
 * \param pOperando2 float* puntero al segundo operando float ingresado
 * \param pFlagOperando int* puntero a la bandera que indica si se ingresó el segundo operando
 * \return int 1 si se guardo con exito, 0 si no se pudo guardar
 *
 */
int getSegundoOperandoFloat(float* pOperando2, int* pFlagOperando);

/** \brief suma dos flotantes y guarda el resultado
 *
 * \param operando1 float primer operando de la suma
 * \param operando2 float segundo operando de la suma
 * \param pSuma float* puntero al resultado de la suma
 * \return int 1 si se pudo hacer el calculo, 0 si no se pudo realizar
 *
 */
int sumarDosFloat(float operando1, float operando2, float* pSuma);

/** \brief resta dos flotantes y guarda el resultado
 *
 * \param operando1 float primer operando de la resta
 * \param operando2 float segundo operando de la resta
 * \param pResta float* puntero al resultado de la resta
 * \return int 1 si se pudo hacer el calculo, 0 si no se pudo realizar
 *
 */
int restarDosFloat(float operando1, float operando2, float* pResta);

/** \brief permite dividir dos numero float, validando que el divisor sea distinto de 0 y guarda el resultado
 *
 * \param operando1 float dividendo
 * \param operando2 float divisor
 * \param pDivision float* puntero al resultado de la division
 * \return int 1 si se pudo hacer el calculo, 0 si no se pudo realizar
 *
 */
int dividirDosFloat(float operando1, float operando2, float* pDivision);

/** \brief permite multiplicar dos numeros float y guardar el resultado
 *
 * \param operando1 float primer operando de la multiplicacion
 * \param operando2 float segundo operando de la multiplicacion
 * \param pProducto float* puntero al producto de los operandos
 * \return int 1 si se pudo hacer el calculo, 0 si no se pudo realizar
 *
 */
int multiplicarDosFloat(float operando1, float operando2, float* pProducto);

/** \brief Calcula el factorial de un numero tipo float, validando que sea entero y positivo
 *
 * \param operando float operando al que se le calculara el factorial
 * \param pFactorial double* puntero al resultado del factorial
 * \return int 1 si se pudo hacer el calculo, 0 si no se pudo realizar
 *
 */
int factorial(float operando, double* pFactorial);
