/*
 ============================================================================
 Name        : TP_1.c
 Author      : Gomez Iglesias, Emiliano
 Version     :
 Copyright   : Your copyright notice
 Description : TP1

 1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
2 Cómo realizar y entregar el trabajo práctico
El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP1 de la
materia.
El mismo consistirá en el proyecto de CodeBlocks con el programa funcionando y comentado,
respetando las reglas de estilo de la cátedra. La compilación no deberá arrojar mensajes de
error ni de warnings.
El proyecto deberá contar con la biblioteca descripta en la sección número dos, y se deberá
hacer uso de dichas funciones para resolver la lógica del

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Aritmeticas.h"

int main()
{
	setbuf(stdout, NULL);

    //declaro variables
    float primerOperando;
    float segundoOperando;
    int opcionMenu;
    int flagOpcion1;
    int flagOpcion2;
    int flagOpcion3;
    int flagPrimerFactorial;
    int flagSegundoFactorial;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    double factorialPrimerOperando;
    double factorialSegundoOperando;
    //inicializo variables
    flagOpcion1 = 0;
    flagOpcion2 = 0;
    flagOpcion3 = 0;
    flagPrimerFactorial =0;
    flagSegundoFactorial =0;


    //menu
    do
    {
        system("cls");
        printf(">>>CALCULADORA<<<\n");
        printf("\n-------------------------------\n");
        printf("\n---MENU DE OPCIONES---\n");
        if (flagOpcion1 == 0)
        {
            printf("\n1. Ingresar 1er operando: A = X\n");
        }
        else
        {
            printf("\n1. Ingresar 1er operando: A = %.2f\n", primerOperando);
        }
        if (flagOpcion2==0)
        {
            printf("\n2. Ingresar 2do operando. B = Y\n");
        }
        else
        {
            printf("\n2. Ingresar 2do operando. B = %.2f\n", segundoOperando);
        }
        printf("\n3. Calcular todas las operaciones.\n");
        printf("\n4. Mostrar todos los resultados.\n");
        printf("\n5. Salir.\n");
        printf("\n");
        printf("\n-----------------------------------------\n");
        printf("\nIngrese el numero de la opcion deseada: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);
        switch (opcionMenu)
        {
            case 1:
                printf("\nIngrese el primer operando:  ");
                fflush(stdin);
                scanf("%f",&primerOperando);
                flagOpcion1=1;
            break;
            case 2:
                if (flagOpcion1==1)
                {
                    printf("\nIngrese el segundo operando: ");
                    fflush(stdin);
                    scanf("%f",&segundoOperando);
                    flagOpcion2=1;
                    break;
                }
                else
                {
                    printf("\n>>>DEBE INGRESAR EL PRIMER OPERANDO<<<\n");
                    system("pause");
                    break;
                }
            case 3:
                if (flagOpcion2==1)
                {
                    flagOpcion3=1;
                    suma = SumarNumeros(primerOperando, segundoOperando);
                    resta = RestarNumeros(primerOperando, segundoOperando);
                    if (ValidarNumeroCero(segundoOperando)==0)
                    {
                        division = DividirNumeros(primerOperando, segundoOperando);
                    }
                    multiplicacion = MultiplicarNumeros(primerOperando, segundoOperando);
                    if (ValidarNumeroEnteroPositivo(primerOperando)==1)
                    {
                        factorialPrimerOperando = FactorialNumero(primerOperando);
                        flagPrimerFactorial=1;
                    }
                    if (ValidarNumeroEnteroPositivo(segundoOperando)==1)
                    {
                        factorialSegundoOperando = FactorialNumero(segundoOperando);
                        flagSegundoFactorial =1;
                    }
                    printf("Se estan calculando las operaciones...\n");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\n>>>PRIMERO DEBE INGRESAR TODOS LOS OPERANDOS.<<<\n");
                    system("pause");
                    break;
                }

            case 4:
                if (flagOpcion3==1)
                {
                    printf("\n4. Se muestran todos los resultados.\n");
                    printf("    a) El resultado de %.2f + %.2f es: %.2f\n",primerOperando, segundoOperando, suma);
                    printf("    b) El resultado de %.2f - %.2f es: %.2f\n",primerOperando, segundoOperando, resta);
                    if (ValidarNumeroCero(segundoOperando))
                    {
                        printf("    c) No se puede dividir por cero.\n");
                    }
                    else
                    {
                        printf("    c) El resultado de %.2f / %.2f es: %.2f\n",primerOperando, segundoOperando, division);
                        division = DividirNumeros(primerOperando, segundoOperando);
                    }

                    printf("    d) El resultado de %.2f * %.2f es: %.2f\n",primerOperando, segundoOperando, multiplicacion);
                    printf("    e) Resultado de los factoriales: \n");
                    if (flagPrimerFactorial==1)
                    {
                        printf("        El resultado de %.0f! es: %.0f\n",primerOperando, factorialPrimerOperando);
                    }
                    else
                    {
                        printf("        No se calculo (%.2f)! ya que solo esta definido para numeros enteros positivos.\n", primerOperando);
                    }
                    if (flagSegundoFactorial==1)
                    {
                        printf("        El resultado de %.0f! es: %.0f \n",segundoOperando, factorialSegundoOperando);
                    }
                    else
                    {
                        printf("        No se calculo (%.2f)! ya que solo esta definido para numeros enteros positivos.\n", segundoOperando);
                    }
                    system("pause");
                    break;
                }
                else
                {
					if (flagOpcion2 == 0)
					{
						printf("\n>>>DEBE INGRESAR TODOS LOS OPERANDOS ANTES.<<<\n");
						system("pause");
						break;
					}
					else
					{
						printf("\n>>>DEBE CALCULAR LAS OPERACIONES ANTES<<<.\n");
						system("pause");
						break;
					}
                }
            case 5:
                system("cls");
                printf("\n -----------------------------\n");
                printf("\n  Ha salido de la calculadora.\n");
                printf("\n------------------------------\n");
            break;
            default:
                printf("\n---HA INGRESADO UNA OPCION INVALIDA---\n");
                system("pause");
            break;
        }
    }while(opcionMenu != 5);
}
