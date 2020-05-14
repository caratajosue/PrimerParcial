/*
 * Publicacion.c
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
/** \brief  Busca la primer posicion donde se encuentra vacio el array
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \return int Devuelve (-1) si Error [Limite inválida o puntero NULO] - (0) si Ok
*/
static int buscarLugarLibre(Publicacion* pArray,int limite,int *indice);
int publicacion_inicializarArray(Publicacion* pArray,int limite)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno = 0;
	}
	return retorno;
}
static int buscarLugarLibre(Publicacion* pArray,int limite,int *indice)
{
    int retorno = -1;
    int i;
    if( pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==1)
            {
                retorno = 0;
                *indice=i;
                break;
            }
        }
    }
    return retorno;
}
int publicacion_alta(Publicacion* pArray, int limite,int* id)
{
    int retorno=-1;
    int indice;
    Publicacion bufferPublicacion;
    if(pArray!=NULL && limite>=0 && id != NULL && id != NULL)
    {
        if(buscarLugarLibre(pArray,limite,&indice)==-1)
        {
            printf("\n\tNo hay lugares vacios\n");
        }
        else if( !utn_getString(bufferPublicacion.aviso,"\nIngrese aviso ","\nERROR\n",2)&&
        	!utn_getNumero(&bufferPublicacion.idCliente,"\nIngrese Id de cliente: ","\nERROR-ID\n",0,limite,2)&&
			!utn_getNumero(&bufferPublicacion.rubro,"\nIngrese Numero de rubro: ","\nERROR-ID\n",0,100,2)
			)
        {
			bufferPublicacion.idPublicacion = *id;
			bufferPublicacion.isEmpty = 0;
			pArray[indice] = bufferPublicacion;
			(*id)++;
            retorno=0;
        }
    }
    return retorno;
}
int publicacion_mostrar(Publicacion* pArray,int limite)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==0)
            {
                printf("\nAviso: %s\nRubro: %d\nID de cliente: %d\nID de publicacion: %d"
                		,pArray[i].aviso,pArray[i].rubro,pArray[i].idCliente,pArray[i].idPublicacion);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int publicacion_buscarID(Publicacion* pArray, int limite, int* indice)
{
    int retorno=-1;
    int i;
    int auxId;
    if(pArray!= NULL && limite>=0 && indice !=NULL)
    {
    	if(!utn_getNumero(&auxId,"\nIngrese Id Publicacion: ","\nError ID",0,limite,2))
    	{
			for(i=0;i<limite;i++)
			{

				if(pArray[i].isEmpty==0 && pArray[i].idPublicacion==auxId)
				{
					retorno=0;
					*indice=i;
					break;
				}
			}
    	}
    }
    return retorno;
}
int publicacion_pausada(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes)
{
    int retorno=-1;
    int indice;
    int posicion;
    int auxId;
    char seguir;
    if(pArray!=NULL && limite>=0 && pClientes!=NULL && limiteClientes>=0)
    {
		if(publicacion_buscarID(pArray,limite,&indice)!=-1)
		{
			auxId=pArray[indice].idCliente;
			cliente_buscarIdPosicion(pClientes,limiteClientes,auxId,&posicion);
			printf("\nNombre %s\napellido: %s\nCuit: %s\nID: %d\n"
					,pClientes[posicion].nombre
					,pClientes[posicion].apellido
					,pClientes[posicion].cuit
					,pClientes[posicion].idCliente);
			if(pArray[indice].isEmpty==0)
			{
				if(!utn_getChar(&seguir,"\nDesea Pausar publicacion s/n","Error",'n','s',2))
				{
					if(seguir=='s')
					{
						pArray[indice].estado=0;
						retorno=0;
					}
				}
			}
		}
    }
    return retorno;
}
int publicacion_activa(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes)
{
    int retorno=-1;
    int indice;
    int posicion;
    int auxId;
    char seguir;
    if(pArray!=NULL && limite>=0 && pClientes!=NULL && limiteClientes>=0)
    {
		if(publicacion_buscarID(pArray,limite,&indice)!=-1)
		{
			auxId=pArray[indice].idCliente;
			cliente_buscarIdPosicion(pClientes,limiteClientes,auxId,&posicion);
			printf("\nNombre %s\napellido: %s\nCuit: %s\nID: %d\n"
					,pClientes[posicion].nombre
					,pClientes[posicion].apellido
					,pClientes[posicion].cuit
					,pClientes[posicion].idCliente);
			if(pArray[indice].isEmpty==0)
			{
				if(!utn_getChar(&seguir,"\nDesea Activar publicacion s/n","Error",'n','s',2))
				{
					if(seguir=='s')
					{
						pArray[indice].estado=1;
						retorno=0;
					}
				}
			}
		}
    }
    return retorno;
}
int publicacion_posicionId(Publicacion* pArray, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pArray!= NULL && limite>=0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==0 && pArray[i].idPublicacion==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int cliente_mostrarActivo(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes)
{
    int retorno=-1;
    int i;
    int j;
    int contadorActiva;
    int auxId;
    int posicion;
    if(pArray != NULL && limite>0 && pClientes!=NULL && limiteClientes>0)
    {
		for(i=0;i<limiteClientes;i++)
		{
			contadorActiva=0;
			auxId=pClientes[i].idCliente;
			for(j=0;j<limite;j++)
			{
				if(auxId==pArray[j].idCliente && pArray[j].estado==1 && pArray[j].isEmpty==0)
				{
					contadorActiva=contadorActiva+1;
					posicion=j;
				}
			}
			if(pArray[posicion].estado==1 && pClientes[i].isEmpty==0)
			{
                printf("\nNombre %s--apellido: %s--Cuit: %s--ID Cliente: %d"
                		,pClientes[i].nombre,pClientes[i].apellido,pClientes[i].cuit,pClientes[i].idCliente);
                if(contadorActiva>=0)
                {
                	printf("\nCantidad de aviso: %d",contadorActiva);
                }

			}
		}
        retorno = 0;
    }
    return retorno;
}
int publicacion_imprimir(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes)
{
    int retorno=-1;
    int i,j;
    char auxCuit[CUIT_SIZE];
    if(pArray != NULL && limite>0 && pClientes!=NULL && limiteClientes>0)
    {
		for(i=0;i<limite;i++)
		{
            if(pArray[i].isEmpty==0)
            {
            	for(j=0;j<limiteClientes;j++)
            	{
            		if(pClientes[j].isEmpty == 0 && pClientes[j].idCliente ==pArray[i].idCliente)
            		{
            			strncpy(auxCuit,pClientes[j].cuit,CUIT_SIZE);
            			printf("--Aviso: %s--Rubro: %d--ID de cliente: %d--ID de publicacion: %d--Cuit: %s"
            			                		,pArray[i].aviso,pArray[i].rubro,pArray[i].idCliente,pArray[i].idPublicacion,auxCuit);
                        if(pArray[i].estado==0)//si estado 0 muestro por pantalla PAUSADA
                          {
                          	printf("--PAUSADA\n");
                          }
                          if(pArray[i].estado==1)//si estado 0 muestro por pantalla ACTIVA
                          {
                          	printf("--ACTIVA\n");
                          }
                          retorno=0;
            		}
            	}
            }
		}
    }
	return retorno;
}
int cliente_Baja(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion)
{
    int retorno=-1;
    int indice;
    int posicion;
    int auxId;
    char seguir;
    int i;
    if(pArray!=NULL && limite>0 && pArrayPublicacion != NULL && limitePublicacion>0)
    {
		cliente_buscarID(pArray,limite,&indice);
		auxId=pArray[indice].idCliente;
		if(pArray[indice].isEmpty==0)
		{
			publicacion_posicionId(pArrayPublicacion,limitePublicacion,auxId,&posicion);
			for(i=0;i<limitePublicacion;i++)
			{
				if(pArrayPublicacion[i].idCliente==auxId && pArrayPublicacion[i].isEmpty==0 )
				{
					printf("\nAviso: %s\nRubro: %d"
					,pArrayPublicacion[i].aviso,pArrayPublicacion[i].rubro);
				}
			}
			if(pArrayPublicacion[posicion].isEmpty==0)
			{
				utn_getChar(&seguir,"\nDesea dar de baja s/n","Error",'n','s',2);
				if(seguir=='n'|| seguir=='s')
				{
					pArrayPublicacion[posicion].isEmpty=1;
					pArray[indice].isEmpty=1;
					retorno=0;
				}
			}

		}
    }
    return retorno;
}
int publicacion_altaForzada(Publicacion* pArray,int limite,int* idP,int indice,int rubro,char* aviso,int estado,int idC)
{
	int retorno = -1;
	Publicacion auxiliar;
	if(pArray != NULL && limite >= 0 && indice <= limite)
	{

			strncpy(auxiliar.aviso,aviso,AVISO_SIZE);
			auxiliar.rubro=rubro;
			auxiliar.estado=estado;
			auxiliar.idCliente=idC;
			retorno = 0;
			pArray[indice] = auxiliar;
			pArray[indice].isEmpty = 0;
			pArray[indice].idPublicacion = *idP;
			*idP = *idP + 1;

	}
	return retorno;
}
