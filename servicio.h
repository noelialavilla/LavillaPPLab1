#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{

   int id;
   char descripcion[20];
   float precio;

}eServicio;


#endif // SERVICIO_H_INCLUDED

void listarServicios(eServicio servicios[], int tamServicios);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void cargarNombreServicio(char descripcion[20], int idServicio, eServicio servicios[], int tamServicios);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
