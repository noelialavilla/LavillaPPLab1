#include "tipo.h"
#include "color.h"
#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;

} eMascota;



#endif // MASCOTA_H_INCLUDED

void inicializarMascotas (eMascota mascotas[], int tam);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void hardcodearMascotas(eMascota mascotas[], int tam);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

  void mostrarMascota(eMascota mascota, eColor colores[], eTipo tipos[], int tamColor, int tamTipos);
  /** \brief
   *
   * \param
   * \param
   * \return
   *
   */

   void mostrarMascotas(eMascota mascotas[], eColor colores[], eTipo tipos[],int tamMascotas, int tamColores, int tamTipos);
   /** \brief
    *
    * \param
    * \param
    * \return
    *
    */

int altaMascotas(int* proxId, eMascota mascotas[], int tamMascotas, eColor colores[], int tamColores, eTipo tipos[], int tamTipos);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarIndiceLibreMascotas(eMascota mascotas[], int tam);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

char menu();
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

void modificarMascota(eMascota mascotas[], int tamMascotas, eTipo tipos[], int tamTipos, eColor colores[], int tamColores);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int buscarMascota(int id, eMascota mascotas[], int tamMascotas);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

  int submenuModif();
  /** \brief
   *
   * \param
   * \param
   * \return
   *
   */

void bajaMascota(eMascota mascotas[], eColor colores[], eTipo tipos[],int tamMascotas, int tamColor, int tamTipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void cargarNombreMascota(char descripcion[20], int idMascota, eMascota mascotas[], int tamMascotas);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

void ordenarMascotas(eMascota mascotas[], int tam, int orden);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int elegirTipoDeOrdenamiento();
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */


