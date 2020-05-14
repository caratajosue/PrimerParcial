/*
 * Publicacion.h
 *
 *  Created on: 12 may. 2020
 *      Author: josue
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define AVISO_SIZE 64

typedef struct
{
    int idPublicacion;
    int isEmpty;
    int rubro;
    char aviso[AVISO_SIZE];
    int estado;
    int idCliente;

}Publicacion;
/** \brief  Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todas las
* posición de la matriz.
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \return int Devuelve (-1) si Error [Limite inválida o puntero NULO] - (0) si Ok
*/
int publicacion_inicializarArray(Publicacion* pArray,int limite);
/** \brief Da de alta una publicacion en el id seleccionado
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no se pudo realizar la alta o Error [Invalid length or NULL pointer] - (0) si Realizo la alta correcta
*/
int publicacion_alta(Publicacion* pArray, int limite,int* id);
/** \brief Muestra por pantalla los datos de publicacion
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no se pudo realizar la alta o Error [Invalid length or NULL pointer] - (0) si Realizo la alta correcta
*/
int publicacion_mostrar(Publicacion* pArray,int limite);
/** \brief Busca la posicion del id y lo retorna
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor retornado
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] -  devuelve la posicion del is buscado
*/
int publicacion_buscarID(Publicacion* pArray, int limite, int* indice);
/** \brief Busca la posicion del id y lo retorna
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param int valorBuscado en publicacion
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - devuelve la posicion del id buscado
*/
int publicacion_posicionId(Publicacion* pArray, int limite, int valorBuscado, int* posicion);
/** \brief Pausa la publicacion del IDP buscado
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \param int valorBuscado en publicacion
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si Pauso publicacion
*/
int publicacion_pausada(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes);
/** \brief Pausa la publicacion del IDP buscado
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \param int valorBuscado en publicacion
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si Activo publicacion
*/
int publicacion_activa(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes);
/** \brief Busca la cantidad de publicaciones activas y lo muestra por pantalla
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) devuelve por pantalla cantiada de publicaciones
*/
int cliente_mostrarActivo(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes);
/** \brief Muestro por pantalla una lista con los datos de publicacion y cuit de cliente y si estado esta Pausada o Activa
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int publicacion_imprimir(Publicacion* pArray,int limite,Cliente* pClientes,int limiteClientes);
/** \brief Baja cliente y sus publicaciones
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si se dio de baja correcta
*/
int cliente_Baja(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicaciones);

int publicacion_altaForzada(Publicacion* pArray,int limite,int* idP,int indice,int rubro,char* aviso,int estado,int idC);
#endif /* PUBLICACION_H_ */
