#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED

int cargarDescripcionColor(char descripcion[], int idColor, eColor colores[], int tamColores);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 void listarColores(eColor colores[], int tamColor);
 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */
