/*
 * Cliente.c
 *
 *  Created on: 7 may. 2020
 *      Author: josue
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include "Cliente.h"
#include "Publicacion.h"
#include "Informe.h"

#define MENU "\n1.Alta de cliente\
\n2.Modificar datos de cliente\
\n3.Baja de cliente\
\n4.Publicar\
\n5.Pausar publicacion\
\n6.Reanudar Publicacion\
\n7.Imprimir Clientes\
\n8.Imprimir Publicaciones\
\n9.Informes Clientes\
\n10.Informar publicaciones\
\n11.Salir: \n "
#define CLIENTES "\n   INFORMES CLIENTES:  \
\n\n  a)-Cliente con más avisos activos\
\n  b)-Cliente con más avisos pausados\
\n  c)-Cliente con más avisos\n "
#define PUBLICACIONES "\n   INFORMES PUBLICACIONES:\
\n\n  a)-Cantidad de publicaciones de un rubro\
\n  b)-Rubro con más publicaciones activas\
\n  c)-Rubro con menos publicaciones activas\n  "
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PUBLICACION 1000
/** \brief  Busca la primer posicion donde se encuentra vacio el array
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \return int Devuelve (-1) si Error [Limite inválida o puntero NULO] - (0) si Ok
*/
static int buscarLugarLibre(Cliente* pArray,int limite,int *indice);

void menu(void)//muestra menu por consola
{
    int opcion;
    char informeClientes;
    char informePublicaciones;
    char seguir;
    int idCliente=0;
    int idPublicacion=0;

    Cliente clientes[CANTIDAD_CLIENTES];
    Publicacion publicaciones[CANTIDAD_PUBLICACION];
    publicacion_inicializarArray(publicaciones,CANTIDAD_PUBLICACION);
    cliente_inicializarArray(clientes,CANTIDAD_CLIENTES);


  /*  Cliente clientes[CANTIDAD_CLIENTES]={
	{0,0,"Josue","Carata","30-11223344-5"},//{idCli,isEmpty,nombre,apellido,cuit}
	{1,0,"Abel","Colque","23-44556677-3"},
	{2,0,"Beto","Sanchez","10-18880767-5"},
	{3,0,"Alberto","Gomez","20-93504129-3"},
	{4,0,"Gustavo","Colque","19-17889878-7"},
	{5,0,"Matias","Gonzales","21-35778876-8"}
	};*/
    cliente_altaForzada(clientes,CANTIDAD_CLIENTES,&idCliente,0,"Josue","Carata","30-11223344-5");
    cliente_altaForzada(clientes,CANTIDAD_CLIENTES,&idCliente,1,"Abel","Colque","20-322433354-7");
    cliente_altaForzada(clientes,CANTIDAD_CLIENTES,&idCliente,2,"Beto","Sanchez","33-932433354-4");
    cliente_altaForzada(clientes,CANTIDAD_CLIENTES,&idCliente,3,"Alberto","Gomez","30-23245434-3");
    /*Publicacion publicaciones[CANTIDAD_PUBLICACION]={
			{0,0,10,"auto",1,0},//{idPu,isEmpty,rubro,aviso,estado,idCli}
			{1,0,5,"moto",1,0},
			{2,0,4,"casa",0,1},
			{3,0,3,"tele",1,2},
			{4,0,10,"auto",1,3},
			{5,0,10,"auto",1,4},
			{6,0,10,"auto",1,2},
			{7,0,3,"tele",0,2}
    };*/
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,0,10,"auto",1,0);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,1,5,"moto",0,1);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,2,2,"tele",1,0);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,3,3,"casa",0,3);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,4,10,"auto",1,2);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,5,10,"auto",1,3);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,6,5,"moto",1,2);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,7,10,"auto",1,2);
    publicacion_altaForzada(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion,8,2,"tele",1,0);
    do
    {
		if(utn_getNumero(&opcion,MENU,"\nError de opcion!",1,11,2)==0)
		{
			switch(opcion)
			{
				case 1:
					if(!cliente_alta(clientes,CANTIDAD_CLIENTES,&idCliente))
					{
						printf("\n\tAlta es correcta");
					}
					break;
				case 2:
					if(cliente_modificar(clientes,CANTIDAD_CLIENTES)!=-1)
					{
						printf("\n Se modifico cliente \n");
					}
					else
					{
						printf("\n No hay cliente cargado \n");
					}
				break;
				case 3:

					if(cliente_Baja(clientes,CANTIDAD_CLIENTES,publicaciones,CANTIDAD_PUBLICACION)!=-1)
					{
						printf("\n Se dio de baja cliente correcto\n");
					}
					else
					{
						printf("\n No Se dio de baja cliente\n");
					}
				break;
				case 4:
					cliente_mostrar(clientes,CANTIDAD_CLIENTES);
					if(!publicacion_alta(publicaciones,CANTIDAD_PUBLICACION,&idPublicacion))
					{
						printf("\n\tPublicacion es correcta\n");
					}
					publicacion_mostrar(publicaciones,CANTIDAD_PUBLICACION);
				break;
				case 5:
					if(!publicacion_pausada(publicaciones,CANTIDAD_PUBLICACION,clientes,CANTIDAD_CLIENTES))
					{
						printf("\nSe pauso publicacion\n");
					}
				break;
				case 6:
					if(!publicacion_activa(publicaciones,CANTIDAD_PUBLICACION,clientes,CANTIDAD_CLIENTES))
					{
						printf("\nSe Activo publicacion\n");
					}
					else
					{
						printf("\nNo hay cliente con publicacion activa\n");
					}
				break;
				case 7:
					cliente_mostrarActivo(publicaciones,CANTIDAD_PUBLICACION,clientes,CANTIDAD_CLIENTES);
				break;
				case 8:
					publicacion_imprimir(publicaciones,CANTIDAD_PUBLICACION,clientes,CANTIDAD_CLIENTES);
				break;
				case 9:
					do
					{
						if(!utn_getChar(&informeClientes,CLIENTES,"Error",'a','c',2))
						{
							switch(informeClientes)
							{
							case 'a':
								 clienteConMasAvisosActivos(clientes,CANTIDAD_CLIENTES,publicaciones,CANTIDAD_PUBLICACION);
								break;
							case 'b':
								clienteConMasAvisosPausado(clientes,CANTIDAD_CLIENTES,publicaciones,CANTIDAD_PUBLICACION);
								break;
							case 'c':
								clienteConMasAvisos(clientes,CANTIDAD_CLIENTES,publicaciones,CANTIDAD_PUBLICACION);
								break;
							}
						}
						utn_getChar(&seguir,"\nDesea continuar en informes clientes s/n","Error",'n','s',2);
					}while(seguir=='s');
					break;
				case 10:
					do
					{
						if(!utn_getChar(&informePublicaciones,PUBLICACIONES,"Error",'a','c',2))
						{
							switch(informePublicaciones)
							{
							case 'a':
								 	 cantidadRubro(publicaciones,CANTIDAD_PUBLICACION);
								break;
							case 'b':
									rubroMasActivo(publicaciones,CANTIDAD_PUBLICACION);
								break;
							case 'c':
									rubroMenosActivo(publicaciones,CANTIDAD_PUBLICACION);
								break;
							}
						}
						utn_getChar(&seguir,"\nDesea continuar en informes clientes s/n","Error",'n','s',2);
					}while(seguir=='s');
					break;
				case 11:
					printf("Saliste de aplicacion");
				break;
		   }
	    }
    }while(opcion!=11);
}
int cliente_inicializarArray(Cliente* pArray,int limite)
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
static int buscarLugarLibre(Cliente* pArray,int limite,int *indice)
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
int cliente_alta(Cliente* pArray, int limite,int* id)
{
    int retorno=-1;
    int indice;
    Cliente bufferCliente;
    if(pArray!=NULL && limite>=0 && id != NULL && id != NULL)
    {
        if(buscarLugarLibre(pArray,limite,&indice)==-1)
        {
            printf("\n\tNo hay lugares vacios\n");
        }
        else if( !utn_getString(bufferCliente.nombre,"\nIngrese nombre de cliente: ","\nERROR-NOMBRE\n",2)&&
        	!utn_getString(bufferCliente.apellido,"\nIngrese apellido de cliente: ","\nERROR-APELLIDO\n",2)&&
			!utn_getCuit(bufferCliente.cuit,"\nIngrese Cuit: ","\nERROR-CUIT\n","00-00000000-0","90-99999999-9",2))
        {
			bufferCliente.idCliente = *id;
			bufferCliente.isEmpty = 0;
			pArray[indice] = bufferCliente;
			(*id)++;
            retorno=0;
        }
    }
    return retorno;
}
int cliente_buscarID(Cliente* pArray, int limite, int* indice)
{
    int retorno=-1;
    int i;
    int auxId;
    if(pArray!= NULL && limite>0 && indice !=NULL)
    {
    	if(!utn_getNumero(&auxId,"\nIngrese ID: ","\nError ID",0,limite,2))
    	{
    		for(i=0;i<limite;i++)
    		{
				if(pArray[i].isEmpty==0 && pArray[i].idCliente==auxId)
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
int cliente_modificar(Cliente* pArray,int limite)
{
    int retorno=-1;
    int indice;
    Cliente bufferCliente;
    if(pArray!=NULL && limite>0)
    {
    	if(cliente_buscarID(pArray,limite,&indice)!=-1)
    	{
			if(pArray[indice].isEmpty==0)
			{
				if( !utn_getString(bufferCliente.nombre,"\nIngrese nombre de cliente: ","\nERROR-NOMBRE\n",2)&&
					!utn_getString(bufferCliente.apellido,"\nIngrese apellido de cliente: ","\nERROR-APELLIDO\n",2)&&
					!utn_getCuit(bufferCliente.cuit,"\nIngrese Cuit: ","\nERROR-CUIT\n","00-00000000-0","90-99999999-9",2))
					{
						pArray[indice] = bufferCliente;
						retorno=0;
					}
			}
    	}
    }
    return retorno;
}
int cliente_mostrar(Cliente* pArray,int limite)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==0)
            {
                printf("\nNombre %s\napellido: %s\nCuit: %s\nID Cliente: %d\n"
                		,pArray[i].nombre,pArray[i].apellido,pArray[i].cuit,pArray[i].idCliente);
            }
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_buscarIdPosicion(Cliente* pArray, int limite, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(pArray!= NULL && limite>0)
    {
        for(i=0;i<limite;i++)
        {
            if(pArray[i].isEmpty==0 && pArray[i].idCliente==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
int cliente_altaForzada(Cliente* pArray,int limite,int* idC,int indice,char* nombre,char* apellido,char* cuit)
{
	int retorno = -1;
	Cliente auxiliar;
	if(pArray != NULL && limite >= 0 && indice <= limite)
	{

			strncpy(auxiliar.nombre,nombre,NOMBRE_SIZE);
			strncpy(auxiliar.apellido,apellido,APELLIDO_SIZE);
			strncpy(auxiliar.cuit,cuit,CUIT_SIZE);

			retorno = 0;
			pArray[indice] = auxiliar;
			pArray[indice].isEmpty = 0;
			pArray[indice].idCliente = *idC;
			*idC = *idC + 1;

	}
	return retorno;
}
