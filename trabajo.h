#include "fecha.h"
#include "mascota.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{

   int id;
   int idMascota;
   int idServicio;
   eFecha fecha;
   int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED

void inicializarTrabajos (eTrabajo trabajos[], int tam);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarIndiceLibreTrabajo(eTrabajo trabajos[], int tam);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServicio, eMascota mascotas[], int tamMascotas);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

void mostrarTrabajos(eTrabajo trabajos[],int tamTrabajo, eServicio servicios[], int tamServicio, eMascota mascotas[], int tamMascotas);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int altaTrabajo(int* proxId,eTrabajo trabajos[],  int tamTrabajos, eMascota mascotas[], int tamMascotas, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eServicio servicios[], int tamServicios);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

