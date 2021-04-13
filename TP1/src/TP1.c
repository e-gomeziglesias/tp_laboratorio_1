/*
Nombre: Emiliano Gomez Iglesias
Curso: 1A

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
hacer uso de dichas funciones para resolver la lógica del programa.*/

#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
int main()
{
	setbuf(stdout, NULL);

    int opcion;
    float operando1;
    float operando2;
    float suma;
    float resta;
    float division;
    float producto;
    double factorial1;
    double factorial2;
    int flagOperando = 0;
    int retornoSuma;
    int retornoResta;
    int retornoDivision;
    int retornoProducto;
    int retornoFactorial1;
    int retornoFactorial2;
    char salir = 'n';


    menuOpciones0(&opcion);
    do
    {
        switch (opcion)
        {
            case 1:
                getPrimerOperandoFloat(&operando1, &flagOperando);
                printf("\n");
                menuOpciones1(&opcion, operando1);
            break;
            case 2:
                if (flagOperando >= 1)
                {
                    getSegundoOperandoFloat(&operando2, &flagOperando);
                    printf("\n");
                    menuOpciones2(&opcion, operando1, operando2);
                }
                else
                {
                    printf("\n\n---Debe ingresar el primer operando para comenzar.---\n\n");
                    menuOpciones0(&opcion);
                }
            break;
            case 3:
                if(flagOperando >= 2)
                {
                    retornoSuma = sumarDosFloat(operando1,operando2,&suma);
                    retornoResta = restarDosFloat(operando1,operando2, &resta);
                    retornoDivision = dividirDosFloat(operando1, operando2, &division);
                    retornoProducto = multiplicarDosFloat(operando1, operando2, &producto);
                    retornoFactorial1 = factorial(operando1,&factorial1);
                    retornoFactorial2 = factorial(operando2, &factorial2);

                    printf("\nSe realizaron las siguientes operaciones:\n\n");
                    if(retornoSuma)
                    {
                        printf("    a.   Se realizo con exito la suma.\n");
                    }
                    else
                    {
                        printf("    a.   La suma no se pudo realizar\n");
                    }

                    if(retornoResta)
                    {
                        printf("    b.   Se realizo con exito la resta.\n");
                    }
                    else
                    {
                        printf("    b.   La resta no se pudo realizar\n");
                    }
                    if(retornoDivision)
                    {
                        printf("    c.   Se realizo con exito la division.\n");
                    }
                    else
                    {
                        printf("    c.   La division no se pudo realizar. Recuerde que la division por 0 no esta definida.\n");
                    }
                    if (retornoProducto)
                    {
                        printf("    d.   Se realizo con exito el producto.\n");
                    }
                    else
                    {
                        printf("    d.   El producto no se pudo realizar\n");
                    }
                    if(retornoFactorial1)
                    {
                        printf("    e.1. Se realizo con exito el factorial del primer operando.\n");
                    }
                    else
                    {
                        printf("    e.1. El factorial del primer operando no se pudo realizar\n");
                    }
                    if(retornoFactorial2)
                    {
                        printf("    e.2. Se realizo con exito el factorial del segundo operando.\n");
                    }
                    else
                    {
                        printf("    e.2. El factorial del segundo operando no se pudo realizar\n");
                    }
                    printf("\n\n\n");
                    menuOpciones2(&opcion, operando1, operando2);
                    flagOperando = 3;
                }
                else
                {
                    switch (flagOperando)
                    {
                        case 1:
                            printf("\n---Primero debe ingresar el segundo operando.---\n\n");
                            menuOpciones1(&opcion, operando1);
                        break;
                        case 0:
                            printf("\n---Primero debe ingresar el primer operando.---\n\n");
                            menuOpciones0(&opcion);
                        break;
                    }
                }
            break;
            case 4:
                switch (flagOperando)
                {
                    case 3:
                        printf("\nRESULTADOS DE LOS CALCULOS:\n\n");
                        if(retornoSuma)
                        {
                            printf("    a.   El resultado de %.2f + %.2f es: %.2f .\n", operando1, operando2, suma);
                        }
                        else
                        {
                            printf("    a.   SUMA: No se pudo realizar\n");
                        }

                        if(retornoResta)
                        {
                            printf("    b.   El resultado de %.2f - %.2f es: %.2f .\n", operando1, operando2, resta);
                        }
                        else
                        {
                            printf("    b.   RESTA: No se pudo realizar\n");
                        }
                        if(retornoDivision)
                        {
                            printf("    c.   El resultado de %.2f / %.2f es: %.2f\n", operando1, operando2, division);
                        }
                        else
                        {
                            printf("    c.   DIVISION: No se puede dividir por cero.\n");
                        }
                        if (retornoProducto)
                        {
                            printf("    d.   El resultado de %.2f * %.2f es: %.2f.\n", operando1, operando2, producto);
                        }
                        else
                        {
                            printf("    d.   PRODUCTO: No se pudo realizar\n");
                        }
                        if(retornoFactorial1)
                        {
                            printf("    e.1. El factorial de %.0f! es: %.0f .\n", operando1, factorial1);
                        }
                        else
                        {
                            printf("    e.1. El factorial de %.2f! no se pudo realizar. Solo numeros enteros.\n", operando1);
                        }
                        if(retornoFactorial2)
                        {
                            printf("    e.2. El factorial de %.0f! es: %.0f .\n", operando2, factorial2);
                        }
                        else
                        {
                            printf("    e.2. El factorial de %.2f! no se pudo realizar. Solo numeros enteros.\n", operando2);
                        }
                        printf("\n\n\n");
                        menuOpciones2(&opcion, operando1, operando2);
                    break;
                    case 2:
                        printf("\n---Primero debe realizar los calculos.---\n\n");
                        menuOpciones2(&opcion, operando1, operando2);
                    break;
                    case 1:
                        printf("\n---Primero debe ingresar el segundo operando.---\n\n");
                        menuOpciones1(&opcion, operando1);
                    break;
                    case 0:
                        printf("\n---Primero debe ingresar el primer operando.---\n\n");
                        menuOpciones0(&opcion);
                    break;
                }
            break;
            case 5:
                printf("\n\n---HA SALIDO DE LA CALCULADORA---\n\n");
                salir = 's';
        }
    } while (salir != 's');
}
