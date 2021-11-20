/*
 * Input.c
 *
 *  Created on: 1 sep. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include <ctype.h>
#include <string.h>
#include <limits.h>

//1.
int CargarFlotante(float* pFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
 	float bufferFloat;

	if(pFlotante != NULL && mensaje!= NULL && mensajeError!= NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("\n%s",mensaje);
			if((scanf("%f", &bufferFloat)==1)&&(bufferFloat>=minimo && bufferFloat <= maximo))
			{
				*pFlotante = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				fflush(stdin);
				printf("\n%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
//2.
int CargarEntero(int* pEntero, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
 	int bufferInt;

	if(pEntero != NULL && mensaje!= NULL && mensajeError!= NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("\n%s",mensaje);
			if((scanf("%d", &bufferInt)==1)&&(bufferInt>=minimo && bufferInt <= maximo))
			{
				*pEntero = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				fflush(stdin);
				printf("\n%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
//3.
int CargarChar(char* pCaracter, char mensaje[], char mensajeError[], int capital, int reintentos)
{
	char bufferChar;
	int retorno = -1;
	if(pCaracter!= NULL && mensaje != NULL && mensajeError != NULL && capital>=0 && capital<=1 && reintentos >=0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if(isalpha(bufferChar)==0)
			{
				printf("%s", mensajeError);
				reintentos--;
			}
			else
			{
				if(capital == 0)
				{
					bufferChar = tolower(bufferChar);
				}
				else
				{
					bufferChar = toupper(bufferChar);
				}
				*pCaracter = bufferChar;
				retorno = 0;
				break;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
//4.
int CargarEnteroValidadoDistintoDeValor(int* pEntero, char mensaje[], char mensajeError[], int valor, int reintentos)
{
	int auxEntero;
	int retorno = -1;
	if(pEntero!=NULL && mensaje != NULL && mensajeError!=NULL && reintentos >=0)
	{
		do
		{
			printf("\n%s",mensaje);

			if(auxEntero == valor || scanf("%d", &auxEntero)!=1)
			{
				fflush(stdin);
				printf("\n%s", mensajeError);
				reintentos--;
			}
			else
			{
				*pEntero = auxEntero;
				retorno = 0;
				break;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
//5
int CargarVectorEnterosValidados (int vector[], int tam, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int auxEntero;
	if(vector!=NULL && tam>0 && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		for(int i=0; i<tam; i++)
		{
			CargarEntero(&auxEntero, mensaje, mensajeError, minimo, maximo, reintentos);
			vector[i] = auxEntero;
		}
		retorno = 0;
	}
	return retorno;
}
//6.
int CargarVectorFlotantesValidados (float vector[], int tam, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float auxFlotante;
	if(vector != NULL && tam>0 && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		for(int i=0; i<tam; i++)
		{
			CargarFlotante(&auxFlotante, mensaje, mensajeError, minimo, maximo, reintentos);
			vector[i] = auxFlotante;
		}
		retorno = 0;
	}
	return retorno;
}
//7.
int CargarAleatoriamenteVectorEnterosValidadosDistintosDeValor (int vector[], int tam, char mensaje[], char mensajeError[], int valor, int reintentos)
{
	int retorno = 0;
	int auxEntero;
	int i;
	char respuesta = 'n';
	if(vector != NULL && tam>0 && mensaje!=NULL && mensajeError != NULL && reintentos >=0)
	{
		do
		{
			CargarEnteroValidadoDistintoDeValor(&auxEntero, mensaje, mensajeError, valor, reintentos);
			printf("Indique la ubicacion donde guardar el valor: ");
			scanf("%d", &i);
			while(((i-1)>=tam) || ((i-1)<0))
			{
				printf("La posicion ingresada es invalida. Reingrese la posicion: ");
				scanf("%d", &i);
			}
			vector[i-1] = auxEntero;
			CargarChar(&respuesta, "Desea ingresar otro numero? (s/n) ", "Error. Debe ingresar una letra. Desea ingresar otro numero? (s/n)", 0, reintentos);
		}while(respuesta =='s');
		retorno = i;
	}
	return retorno;
}
//8.
int VerificarSignoEntero(int valor)
{
	int signo;
	if(valor>0)
	{
		signo = 1;
	}
	else
	{
		if(valor<0)
		{
			signo = -1;
		}
		else
		{
			signo = 0;
		}
	}
	return signo;
}
//9.
int VerificarSignoFlotante(float valor)
{
	int signo;
	if(valor>0)
	{
		signo = 1;
	}
	else
	{
		if(valor<0)
		{
			signo = -1;
		}
		else
		{
			signo = 0;
		}
	}
	return signo;
}
//10.
int VerificarParidad(int valor)
{
	int paridad = 1;
	if(valor%2==0)
	{
		paridad = 0;
	}
	return paridad;
}

//11.
int CargarString(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char auxCadena[1000];

	if(cadena != NULL && tam>0 && mensaje !=NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("\n%s", mensaje);
			fflush(stdin);
			gets(auxCadena);

			if(strlen(auxCadena)<=tam-1)
			{
				strcpy(cadena, auxCadena);
				retorno = 0;
				break;
			}
			else
			{
				printf("\n%s", mensajeError);
				fflush(stdin);
				reintentos--;
			}
		}while(reintentos >=0);

	}
	return retorno;
}

//12.
int NormalizarString(char cadena[], int tam, int capital)
{
	int retorno = -1;
	char auxCadena[tam];
	if(cadena!=NULL && tam>0 && (capital==-1 || capital==0 || capital==1))
	{
		strcpy(auxCadena, cadena);
		switch(capital)
		{
			case -1:
				strlwr(auxCadena);
			break;
			case 0:
				strlwr(auxCadena);
				for(int i=0; i<tam; i++)
				{
					if(i==0)
					{
						auxCadena[i]=toupper(auxCadena[i]);
					}
					else
					{
						if(isspace(auxCadena[i])!=0)
						{
							auxCadena[i+1]=toupper(auxCadena[i+1]);
						}
					}
				}
			break;
			case 1:
				strupr(auxCadena);
			break;
		}
		strcpy(cadena, auxCadena);
		retorno = 0;
	}
	return retorno;
}

//13.
int EsAlfabetica(char cadena[], int tam)
{
	int retorno=-1;
	if(cadena != NULL && tam>0)
	{
		for(int i=0; cadena[i]!='\0'; i++)
		{
			if(isalpha(cadena[i])!=0 || isspace(cadena[i])!=0)
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

//14.
int EsNumerica(char cadena[], int tam)
{
	int retorno=-1;
	if(cadena != NULL && tam>0)
	{
		for(int i=0; cadena[i]!='\0'; i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

//15.
int CargarStringLetras(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char auxCadena[1000];

	if(cadena != NULL && tam>0 && mensaje !=NULL && mensajeError != NULL && reintentos>=0)
	{
		do
		{
			printf("\n%s", mensaje);
			fflush(stdin);
			gets(auxCadena);
			if((strlen(auxCadena)<=tam-1) && (EsAlfabetica(auxCadena, tam)==0))
			{
				strcpy(cadena, auxCadena);
				retorno = 0;
				break;
			}
			else
			{
				printf("\n%s", mensajeError);
				fflush(stdin);
				reintentos--;
			}
		}while(reintentos >=0);

	}
	return retorno;
}

//16.
int CargarStringNormalizado(char cadena[], int tam, char mensaje[], char mensajeError[], int capital, int reintentos)
{
	int retorno = -1;
	char auxCadena[1000];
	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && (capital>=-1 && capital<=1) && reintentos>=0)
	{
		if(CargarStringLetras(auxCadena, tam, mensaje, mensajeError, reintentos)==0)
		{
			if(NormalizarString(auxCadena, tam, capital)==0)
			{
				strcpy(cadena, auxCadena);
				retorno = 0;
			}
		}
	}
	return retorno;
}

//17.
int CargarCuit(char cuit[], int tam, int reintentos)
{
	int retorno = -1;
	int j=0;
	char auxCadena[500];
	char auxCuit[14];

	if(cuit != NULL && tam>0 && reintentos>=0)
	{
		do
		{
			printf("\nIngrese CUIT (11 digitos, solo numeros): ");
			fflush(stdin);
			gets(auxCadena);
			if((strlen(auxCadena)==11) && (EsNumerica(auxCadena, 500)==0) && (
					((auxCadena[0]=='2') && (auxCadena[1]=='0'))||
				//condiciones para los dos primeros numeros del cuit:
					((auxCadena[0]=='2') && (auxCadena[1]=='3'))||
					((auxCadena[0]=='2') && (auxCadena[1]=='4'))||
					((auxCadena[0]=='2') && (auxCadena[1]=='5'))||
					((auxCadena[0]=='2') && (auxCadena[1]=='6'))||
					((auxCadena[0]=='2') && (auxCadena[1]=='7'))||
					((auxCadena[0]=='3') && (auxCadena[1]=='0'))||
					((auxCadena[0]=='3') && (auxCadena[1]=='3'))||
					((auxCadena[0]=='3') && (auxCadena[1]=='4')))
					)
			{
				for(int i=0; i<=14; i++)
				{
					//condicion para colocar los '-'
					if(i==2||i==11)
					{
						auxCuit[i]='-';
						i++;
					}
					else
					{
						if(i==14)
						{
							auxCuit[i]='\0';
						}
					}
					auxCuit[i]=auxCadena[j];
					j++;
				}
				strcpy(cuit,auxCuit);
				retorno = 0;
				break;
			}
			else
			{
				printf("\nEl CUIT ingresado es invalido.");
				fflush(stdin);
				reintentos--;
			}
		}while(reintentos >=0);
	}
	return retorno;
}

