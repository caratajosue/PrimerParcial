/*
 * Informe.c
 *
 *  Created on: 12 may. 2020
 *      Author: josue
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include "Cliente.h"
#include "Publicacion.h"

int clienteConMasAvisosActivos(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion)
{
	int retorno=-1;
	int i,j;
	int mayorActivo=0;
	int indice;
	int contador;
	int auxId;
	if(pArray!=NULL && limite>0 && pArrayPublicacion!=NULL && limitePublicacion>0)
	{
		for(i=0;i<limite;i++)
		{
			contador=0;
			auxId=pArray[i].idCliente;
			for(j=0;j<limitePublicacion;j++)
			{
				if((auxId==pArrayPublicacion[j].idCliente) && (pArrayPublicacion[j].estado==1) && pArrayPublicacion[j].isEmpty==0)
				{
					contador=contador+1;
				}
			}
			if(mayorActivo<contador)
			{
				mayorActivo=contador;
				indice=i;
			}
		}
		printf("\nCliente con mas publicaciones Activa : %s",pArray[indice].nombre);
		retorno = 0;
	}
	return retorno;
}
int clienteConMasAvisosPausado(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion)
{
	int retorno=-1;
	int i,j;
	int mayorPausado=0;
	int indice;
	int contador;
	int auxId;
	if(pArray!=NULL && limite>0 && pArrayPublicacion!=NULL && limitePublicacion>0)
	{
		for(i=0;i<limite;i++)
		{
			contador=0;
			auxId=pArray[i].idCliente;
			for(j=0;j<limitePublicacion;j++)
			{
				if((auxId==pArrayPublicacion[j].idCliente )&& (pArrayPublicacion[j].estado==0)&& pArrayPublicacion[j].isEmpty==0)
				{
					contador=contador+1;
				}
			}
			if(mayorPausado<contador)
			{
				mayorPausado=contador;
				indice=i;
			}
		}
		printf("\nCliente con mas publicaciones pausadas : %s",pArray[indice].nombre);
		retorno = 0;
	}
	return retorno;
}
int clienteConMasAvisos(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion)
{
	int retorno=-1;
	int i,j;
	int masAvisos=0;
	int indice;
	int contador;
	int auxId;
	if(pArray!=NULL && limite>0 && pArrayPublicacion!=NULL && limitePublicacion>0)
	{
		for(i=0;i<limite;i++)
		{
			contador=0;
			auxId=pArray[i].idCliente;
			for(j=0;j<limitePublicacion;j++)
			{
				if((auxId==pArrayPublicacion[j].idCliente )&& (pArrayPublicacion[j].estado==0||pArrayPublicacion[j].estado==1) && pArrayPublicacion[j].isEmpty==0)
				{
					contador=contador+1;
				}
			}
			if(masAvisos<contador)
			{
				masAvisos=contador;
				indice=i;
			}
		}
		printf("\nCliente con mas avisos : %s",pArray[indice].nombre);
		retorno = 0;
	}
	return retorno;
}
int cantidadRubro(Publicacion* pArrayPublicacion,int limitePublicacion)
{
	int retorno=-1;
	int j;
	int rubroM=0;
	int contador;
	int auxRubro;
	if( pArrayPublicacion!=NULL && limitePublicacion>0)
	{
		contador=0;
		if(!utn_getNumero(&auxRubro,"\nIngrese Numero de rubro: ","\nERROR-NO DE RUBRO\n",0,20,2))
		{
			for(j=0;j<limitePublicacion;j++)
			{
				if(auxRubro==pArrayPublicacion[j].rubro &&	pArrayPublicacion[j].estado==1)
				{
					contador=contador+1;
				}
			}
		}
		else
		{
			printf("\n NO EXISTE RUBRO \n");
		}
		if(contador>rubroM)
		{
			rubroM=contador;
			printf("\nCantidad de publicaciones activas de dicho rubro : %d",rubroM);
		}
	retorno = 0;
	}
	return retorno;
}
int rubroMasActivo(Publicacion* pArray,int limite)
{
	int retorno=-1;
	int i,j;
	int mayorActivo=0;
	int indice;
	int auxId;
	int contador;
	if(pArray!=NULL && limite>0 && pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			contador=0;
			auxId=pArray[i].rubro;
			for(j=0;j<limite;j++)
			{
				if(pArray[j].isEmpty == 0 && pArray[j].estado ==1 && auxId==pArray[j].rubro)
				{
					contador++;
				}
			}
			if(contador>mayorActivo)
			{
				mayorActivo=contador;
				indice=i;
			}
		}
		retorno=0;
		printf("\nEl rubro mas publicaciones activas: %d ",pArray[indice].rubro);
	}
	return retorno;
}
int rubroMenosActivo(Publicacion* pArray,int limite)
{
	int retorno=-1;
	int i,j;
	int menorActivo=0;
	int indice;
	int auxId;
	int contador;
	if(pArray!=NULL && limite>0 && pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			contador=0;
			auxId=pArray[i].rubro;
			for(j=0;j<limite;j++)
			{
				if(pArray[j].isEmpty == 0 && pArray[j].estado == 0 && auxId==pArray[j].rubro)
				{
					contador++;
				}
			}
			if(contador>menorActivo)
			{
				menorActivo=contador;
				indice=i;
			}
		}
		retorno=0;
		printf("\nEl rubro menos publicaciones activas: %d ",pArray[indice].rubro);
	}
	return retorno;
}
