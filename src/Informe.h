/*
 * Informe.h
 *
 *  Created on: 12 may. 2020
 *      Author: josue
 */

#ifndef INFORME_H_
#define INFORME_H_
/** \brief Muestro por pantalla clientes mas activo
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int clienteConMasAvisosActivos(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion);
/** \brief Muestro por pantalla clientes mas pausado
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int clienteConMasAvisosPausado(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion);
/** \brief Muestro por pantalla clientes con mas avisos
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int clienteConMasAvisos(Cliente* pArray,int limite,Publicacion* pArrayPublicacion,int limitePublicacion);
/** \brief Muestro por pantalla cantidad de un rubro seleccionado
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int cantidadRubro(Publicacion* pArrayPublicacion,int limitePublicacion);
/** \brief Muestro por pantalla el rubro mas seleccionado
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int rubroMasActivo(Publicacion* pArray,int limite);
/** \brief Muestro por pantalla el rubro menos seleccionado
* \param recibe un array tipo Publicacion
* \param int Tamaño del array
* \param recibe un array tipo Cliente
* \param int Tamaño del array
* \return int Devuelve (-1) Error [Invalid length or NULL pointer] - (0) si salio bien
*/
int rubroMenosActivo(Publicacion* pArray,int limite);

#endif /* INFORME_H_ */
