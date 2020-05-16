#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{

   int id;
   char descripcion[20] ;

}eTipo;

#endif // TIPO_H_INCLUDED

int cargarDescripcionTipo(char descripcion[], int idTipo, eTipo tipos[], int tamTipos);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void listarTipos(eTipo tipos[], int tamTipos);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */
