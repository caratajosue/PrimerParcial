/*
 * Cliente.h
 *
 *  Created on: 7 may. 2020
 *      Author: josue
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_SIZE 50
#define APELLIDO_SIZE 50
#define CUIT_SIZE 14

typedef struct
{
    int idCliente;
    int isEmpty;
    char nombre[NOMBRE_SIZE];
    char apellido[APELLIDO_SIZE];
    char cuit[CUIT_SIZE];

}Cliente;

/** \brief  muestra por pantalla el menu
* \param void no recibe ningun parametro
* \return void no devuelve ningun valor solo muestra menu
*/
void menu(void);
/** \brief  Para indicar que todas las posiciones en la matriz están vacías,
* esta función pone la bandera (isEmpty) en TRUE en todas las
* posición de la matriz.
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \return int Devuelve (-1) si Error [Limite inválida o puntero NULO] - (0) si Ok
*/
int cliente_inicializarArray(Cliente* pArray,int limite);
/** \brief Da de alta un cliente siempre que tenga lugar el array
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no se pudo realizar la alta o Error [Invalid length or NULL pointer] - (0) si Realizo la alta correcta
*/
int cliente_alta(Cliente* pArray, int limite,int* id);
/** \brief Busca el campo en un array y devuelve la posicion en que se encuentra
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*/
int cliente_buscarID(Cliente* pArray, int limite, int* indice);
/** \brief modifica cliente se le ingresa el IDcliente para poder modificar
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si Realizo la modificacion correcta
*/
int cliente_modificar(Cliente* pArray,int limite);
/** \brief imprime por pantalla los datos de cliente
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) Correcto
*/
int cliente_mostrar(Cliente* pArray,int limite);
/** \brief Busca la posicion del IDCliente
* \param recibe un array tipo fantasma
* \param int Tamaño del array
* \param int valor a buscar (idcliente)
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Devuelve (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*/
int cliente_buscarIdPosicion(Cliente* pArray, int limite, int valorBuscado, int* posicion);

int cliente_altaForzada(Cliente* pArray,int limite,int* idC,int indice,char* nombre,char* apellido,char* cuit);
#endif /* CLIENTE_H_ */
