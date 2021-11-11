/*
 * Input.h
 *
 *  Created on: 1 sep. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */

//1.
/// @fn int CargarFlotante(float*, char*, char*, float, float, int)
/// @brief Permite cargar un numero flotante definido dentro de un rango y con una cantidad definida de reintentos en caso de error
///
/// @param pFlotante puntero a flotante donde se guardara el numero validado
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error en caso de ingreso erroneo
/// @param minimo cota inferior del rango
/// @param maximo cota superior del rango
/// @param reintentos cantidad de reintentos
/// @return 0 si ok, -1 si error.
int CargarFlotante(float* pFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

//2.
/// @fn int CargarEntero(int*, char*, char*, int, int, int)
/// @brief Permite cargar un numero entero definido dentro de un rango y con una cantidad definida de reintentos en caso de error
///
/// @param pEntero puntero a entero donde se guardara el numero validado
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error en caso de ingreso erroneo
/// @param minimo cota inferior del rango
/// @param maximo cota superior del rango
/// @param reintentos cantidad de reintentos
/// @return 0 si ok, -1 si error.
int CargarEntero(int* pEntero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

//3.
/// @fn char CargarChar(char*, char[], char[], int, int)
/// @brief permite cargar un caracter y elegir si cargarlo en mayuscula o en minuscula
///
/// @param pCaracter puntero a char donde se guardará el caracter validado
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error en caso de ingreso de datos fallido
/// @param capital 0 para pasar a minuscula, 1 para pasar a mayuscula
/// @param reintentos cantidad de reintentos en caso de error
/// @return 0 si ok, -1 si error.
int CargarChar(char* pCaracter, char mensaje[], char mensajeError[], int capital, int reintentos);

//4.
/// @fn int CargarEnteroValidadoDistintoDeValor(int*, char[], char[], int, int)
/// @brief permite cargar un valor entero que sea distinto de un valor elegido, con una cantidad de reintentos en caso de error.
///
/// @param pEntero puntero a int donde se almacenará el entero validado
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error en caso de error en el ingreso
/// @param valor valor que no puede tomar el entero
/// @param reintentos cantidad de reintentos en caso de error
/// @return 0 si OK, -1 si error.
int CargarEnteroValidadoDistintoDeValor(int* pEntero, char mensaje[], char mensajeError[], int valor, int reintentos);

//5.
/// @fn int CargarVectorEnterosValidados(int[], int, char[], char[], int, int)
/// @brief Permite cargar un vector con una cantidad de valores definidas por el usuario, dentro de un rango
///
/// @param vector vector donde se almacenarán los valores cargados por el usuario.
/// @param tam tamaño del vector
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error en el ingreso de datos
/// @param minimo cota inferior del rango
/// @param maximo cota superior del rango
/// @param reintentos cantidad de reintentos en caso de carga errónea
/// @return 0 si se pudo cargar, -1 si hubo error.
int CargarVectorEnterosValidados (int vector[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

//6.
/// @fn int CargarVectorFlotantesValidados(int[], int, char[], char[], int, int)
/// @brief Permite cargar un vector con una cantidad de valores definidas por el usuario, dentro de un rango
///
/// @param vector vector donde se almacenarán los valores cargados por el usuario.
/// @param tam tamaño del vector
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error en el ingreso de datos
/// @param minimo cota inferior del rango
/// @param maximo cota superior del rango
/// @param reintentos cantidad de reintentos en caso de carga errónea
/// @return 0 si se pudo cargar, -1 si hubo error.
int CargarVectorFlotantesValidados (float vector[], int tam, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

//7.
/// @fn int CargarAleatoriamenteVectorEnterosValidadosDistintosDeValor(int[], int, char[], char[], int)
/// @brief Permite cargar valores en un vector que sean distintos de un valor en particular
///
/// @param vector vector donde se cargaran los valores
/// @param tam tamaño del vector
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de error al ingresar datos
/// @param valor valor que no podran tomar los numeros cargados
/// @param reintentos cantidad de reintentos en caso de carga erronea
/// @return 0 si ok, -1 si error
int CargarAleatoriamenteVectorEnterosValidadosDistintosDeValor (int vector[], int tam, char mensaje[], char mensajeError[], int valor, int reintentos);

//8.
/// @fn int VerificarSignoEntero(int)
/// @brief permite determinar el signo de un numero entero
///
/// @param valor numero a evaluar signo
/// @return -1 si es negativo, 1 si es positivo, 0 si es cero
int VerificarSignoEntero(int valor);

//9.
/// @fn int VerificarSignoEntero(int)
/// @brief permite determinar el signo de un numero flotante
///
/// @param valor numero a evaluar signo
/// @return -1 si es negativo, 1 si es positivo, 0 si es cero
int VerificarSignoFlotante(float valor);

//10.
/// @fn int VerificarParidad(int)
/// @brief Permite determinar la paridad de un numero
///
/// @param valor numero a evaluar la paridad
/// @return 0 si es par, 1 si es impar
int VerificarParidad(int valor);

//11.
/// @fn int CargarString(char[], int, char[], char[], int)
/// @brief Permite cargar una cadena de caracteres y pasarla a minuscula, mayusculas o normalizarla
///
/// @param cadena cadena a cargar
/// @param tam tamaño de la cadena
/// @param mensaje mensaje de carga
/// @param mensajeError mensaje de error en la carga
/// @param reintentos cantidad de reintentos en caso de error
/// @return 0 si OK, -1 si error.
int CargarString(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos);

//12.
/// @fn int NormalizarString(char[], int, int)
/// @brief Permite normalizar mayusculas y minusculas de una cadena
///
/// @param cadena cadena a normalizar
/// @param tam tamaño de la cadena
/// @param capital -1 para minuscula, 0 para primer letra de cada palabra mayuscula y el resto minuscula, 1 todo mayuscula
/// @return -1 si error, 0 si OK
int NormalizarString(char cadena[], int tam, int capital);

//13.
/// @fn int EsAlfabetica(char[], int)
/// @brief permite determinar si una cadena contiene solo letras o espacios
///
/// @param cadena cadena a controlar
/// @param tam tamano de la cadena
/// @return 0 si ok, -1 si error
int EsAlfabetica(char cadena[], int tam);

//14.
/// @fn int EsNumerica(char[], int)
/// @brief permite determinar si una cadena contiene solo numeros
///
/// @param cadena cadena a controlar
/// @param tam tamano de la cadena
/// @return 0 si ok, -1 si error
int EsNumerica(char cadena[], int tam);
//15.
/// @fn int CargarStringLetras(char[], int, char[], char[], int)
/// @brief permite cargar una cadena solo con letras y/o espacios
///
/// @param cadena cadena a cargar
/// @param tam tamano de la cadena
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de ingreso erroneo
/// @param reintentos cantidad de reintentos
/// @return 0 si ok, -1 si error
int CargarStringLetras(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos);

//16.
/// @fn int CargarStringNormalizado(char[], int, char[], char[], int, int)
/// @brief permite cargar una cadena solo con letras y/o espacios y convertirla a minuscula, mayuscula o solo la primer letra mayuscula
///
/// @param cadena cadena a cargar
/// @param tam tamano de la cadena
/// @param mensaje mensaje de ingreso de datos
/// @param mensajeError mensaje de ingreso erroneo
/// @param capital -1 minuscula, 0 solo la primer letra mayusucula, 1 todo mayuscula
/// @param reintentos cantidad de reintentos
/// @return 0 si ok, -1 si error
int CargarStringNormalizado(char cadena[], int tam, char mensaje[], char mensajeError[], int capital, int reintentos);

//17.
/// @fn int CargarCuit(char[], int, int)
/// @brief Permite cargar un numero de CUIT
///
/// @param cuit cadena donde se almacenara el cuit(incluye los guiones)
/// @param tam tamano de la cadena
/// @param reintentos cantidad de reintentos en caso de ingreso erroneo
/// @return 0 si ok, -1 si error
int CargarCuit(char cuit[], int tam, int reintentos);

