/*
 * Aritmeticas.c
 *
 *  Created on: 10 sep. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdlib.h>
#include <stdio.h>
#include "Aritmeticas.h"

//1. Operaciones Basicas

    //1.1 Suma
    float SumarNumeros(float primerNumero, float segundoNumero)
    {
        //Declaro variables
        float suma;
        //Resolucion
        suma = primerNumero + segundoNumero;
        return suma;
    }
    //1.2 Resta
    float RestarNumeros (float primerNumero, float segundoNumero)
    {
        //Declaro variables
        float resta;
        //Resolucion
        resta = primerNumero - segundoNumero;
        return resta;
    }
    //1.3 Multiplicacion
    float MultiplicarNumeros (float primerNumero, float segundoNumero)
    {
        //Declaro variables
        float producto;
        //Resolucion
        producto = primerNumero*segundoNumero;
        return producto;
    }
    //1.4 Division
    float DividirNumeros (float dividendo, float divisor)
    {
        //Declaro variables
        float division;
        //Resolucion
        division = dividendo / divisor;
        return division;
    }

//2. Funciones
    //1.1 Factorial
    double FactorialNumero (float numero)
    {
        //Declaro variables
        double factorial;
        int i;
        //Resolucion
        for (i = 0; i <= numero ; i++)
        {
            if (i==0)
            {
                factorial = 1;
                i = 1;
            }
            factorial = factorial * i;
        }
        return factorial;
    }

//3. Validaciones
    //3.1.Validar Cero
    int ValidarNumeroCero(float numero)
    {
    	int retorno;
        if (numero == 0)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
        return retorno;
    }
    //3.2 Validar Entero
    int ValidarNumeroEnteroPositivo (float numero)
    {
        int entero;
        int retorno;
        entero = numero;
        if (entero - numero || numero < 0)
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
        }
        return retorno;
    }

