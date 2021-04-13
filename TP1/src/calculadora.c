/*
 * calculadora.c
 *
 *  Created on: 10 abr. 2021
 *      Author: Emiliano Gomez Iglesias
 */

#include "calculadora.h"

int menuOpciones0(int* pOpcion)
{
    int retorno = 0;
    int opcion;

    fflush(stdin);
    if (pOpcion!=NULL)
    {
        printf("***CALCULADORA***\n");
        printf("\n---Menu de Opciones---\n");
        printf("\n");
        printf("    1. Ingresar 1er operando (A=x)\n");
        printf("    2. Ingresar 2do operando (B=y)\n");
        printf("    3. Calcular todas las operaciones\n");
        printf("        a) Calcular la suma (A+B)\n");
        printf("        b) Calcular la resta (A-B)\n");
        printf("        c) Calcular la division (A/B)\n");
        printf("        d) Calcular la multiplicacion (A*B)\n");
        printf("        e) Calcular el factorial (A!)\n");
        printf("    4. Informar resultados\n");
        printf("    5. Salir\n");
        printf("\nIngrese opcion: ");
        scanf("%d", &opcion);
        while ((!(opcion >= 1 && opcion<= 5)) || (isalpha(opcion)))
        {
            printf("\nLa opcion ingresada es invalida. Ingrese una opcion valida\n");
            printf("\n---Menu de Opciones---\n");
            printf("\n");
            printf("    1. Ingresar 1er operando (A=x)\n");
            printf("    2. Ingresar 2do operando (B=y)\n");
            printf("    3. Calcular todas las operaciones\n");
            printf("        a) Calcular la suma (A+B)\n");
            printf("        b) Calcular la resta (A-B)\n");
            printf("        c) Calcular la division (A/B)\n");
            printf("        d) Calcular la multiplicacion (A*B)\n");
            printf("        e) Calcular el factorial (A!)\n");
            printf("    4. Informar resultados\n");
            printf("    5. Salir\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
        *pOpcion=opcion;
        printf("\n\n\n\n");
        retorno = 1;
    }
    return retorno;
}

int menuOpciones1(int* pOpcion, float operando1)
{
    int retorno = 0;
    int opcion;

    fflush(stdin);
    if (pOpcion!=NULL)
    {
        printf("***CALCULADORA***\n");
        printf("\n---Menu de Opciones---\n");
        printf("\n");
        printf("    1. Ingresar 1er operando (A= %.2f)\n", operando1);
        printf("    2. Ingresar 2do operando (B=y)\n");
        printf("    3. Calcular todas las operaciones\n");
        printf("        a) Calcular la suma (A+B)\n");
        printf("        b) Calcular la resta (A-B)\n");
        printf("        c) Calcular la division (A/B)\n");
        printf("        d) Calcular la multiplicacion (A*B)\n");
        printf("        e) Calcular el factorial (A!)\n");
        printf("    4. Informar resultados\n");
        printf("    5. Salir\n");
        printf("\nIngrese opcion: ");
        scanf("%d", &opcion);
        while ((!(opcion >= 1 && opcion<= 5)) || (isalpha(opcion)))
        {
            printf("\nLa opcion ingresada es invalida. Ingrese una opcion valida\n");
            printf("\n---Menu de Opciones---\n");
            printf("\n");
            printf("    1. Ingresar 1er operando (A= %.2f)\n", operando1);
            printf("    2. Ingresar 2do operando (B=y)\n");
            printf("    3. Calcular todas las operaciones\n");
            printf("        a) Calcular la suma (A+B)\n");
            printf("        b) Calcular la resta (A-B)\n");
            printf("        c) Calcular la division (A/B)\n");
            printf("        d) Calcular la multiplicacion (A*B)\n");
            printf("        e) Calcular el factorial (A!) y (B!)\n");
            printf("    4. Informar resultados\n");
            printf("    5. Salir\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
        *pOpcion=opcion;
        printf("\n\n\n\n");
        retorno = 1;
    }
    return retorno;
}


int menuOpciones2(int* pOpcion, float operando1, float operando2)
{
    int retorno = 0;
    int opcion;

    fflush(stdin);
    if (pOpcion!=NULL)
    {
        printf("***CALCULADORA***\n");
        printf("\n---Menu de Opciones---\n");
        printf("\n");
        printf("    1. Ingresar 1er operando (A= %.2f)\n", operando1);
        printf("    2. Ingresar 2do operando (B= %.2f)\n", operando2);
        printf("    3. Calcular todas las operaciones\n");
        printf("        a) Calcular la suma (%.2f + %.2f)\n", operando1, operando2);
        printf("        b) Calcular la resta (%.2f - %.2f)\n",  operando1, operando2);
        printf("        c) Calcular la division (%.2f / %.2f)\n",  operando1, operando2);
        printf("        d) Calcular la multiplicacion (%.2f * %.2f)\n",  operando1, operando2);
        printf("        e) Calcular el factorial (%.2f!) y (%.2f!)\n",  operando1, operando2);
        printf("    4. Informar resultados\n");
        printf("    5. Salir\n");
        printf("\nIngrese opcion: ");
        scanf("%d", &opcion);
        while ((!(opcion >= 1 && opcion<= 5)) || (isalpha(opcion)))
        {
            printf("\nLa opcion ingresada es invalida. Ingrese una opcion valida\n");
            printf("\n---Menu de Opciones---\n");
            printf("\n");
            printf("    1. Ingresar 1er operando (A= %.2f)\n", operando1);
            printf("    2. Ingresar 2do operando (B= %.2f)\n", operando2);
            printf("    3. Calcular todas las operaciones\n");
            printf("        a) Calcular la suma (%.2f + %.2f)\n", operando1, operando2);
            printf("        b) Calcular la resta (%.2f - %.2f)\n",  operando1, operando2);
            printf("        c) Calcular la division (%.2f / %.2f)\n",  operando1, operando2);
            printf("        d) Calcular la multiplicacion (%.2f * %.2f)\n",  operando1, operando2);
            printf("        e) Calcular el factorial (%.2f!) y (%.2f!)\n",  operando1, operando2);
            printf("    4. Informar resultados\n");
            printf("    5. Salir\n");
            printf("\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }
        *pOpcion=opcion;
        printf("\n\n\n\n");
        retorno = 1;
    }
    return retorno;
}

int getPrimerOperandoFloat(float* pOperando1, int* pFlagOperando)
{
    int retorno = 0;
    float operando1;

    if (pOperando1!=NULL && pFlagOperando!=NULL)
    {
        printf("\nIngrese el primer operando: ");
        scanf("%f", &operando1);
        printf("\n");
        *pOperando1 = operando1;
        *pFlagOperando = 1;
        retorno = 1;
    }

    return retorno;
}

int getSegundoOperandoFloat(float* pOperando2, int* pFlagOperando)
{
    int retorno = 0;
    float operando2;

    if (pOperando2!=NULL && pFlagOperando != NULL)
    {
        printf("\nIngrese el segundo operando: ");
        scanf("%f", &operando2);
        printf("\n");
        *pOperando2 = operando2;
        *pFlagOperando = 2;
        retorno = 1;
    }

    return retorno;
}

int sumarDosFloat(float operando1, float operando2, float* pSuma)
{
    int retorno=0;
    if (pSuma != NULL)
    {
        (*pSuma)= operando1 + operando2;
        retorno = 1;
    }
    return retorno;
}

int restarDosFloat(float operando1, float operando2, float* pResta)
{
    int retorno=0;
    if (pResta != NULL)
    {
        (*pResta)= operando1 - operando2;
        retorno = 1;
    }
    return retorno;
}

int dividirDosFloat(float operando1, float operando2, float* pDivision)
{
    int retorno=0;
    if (pDivision != NULL && (operando2!=0))
    {
        (*pDivision)= operando1 / operando2;
        retorno = 1;
    }
    return retorno;
}

int multiplicarDosFloat(float operando1, float operando2, float* pProducto)
{
    int retorno=0;
    if (pProducto != NULL)
    {
        (*pProducto)= operando1 * operando2;
        retorno = 1;
    }
    return retorno;
}

int factorial(float operando, double* pFactorial)
{
    int retorno = 0;
    int operandoEntero;
    double factorial;

    operandoEntero = operando;

    if((((operando - operandoEntero)==0)|| (operando < 0))&&(pFactorial != NULL) )
    {
        for (int i=0 ; i<= operando; i++)
        {
            if (i==0)
            {
                factorial = 1;
                i = 1;
            }
            factorial = factorial*i;
        }
        *pFactorial = factorial;
        retorno = 1;
    }
    return retorno;
}
