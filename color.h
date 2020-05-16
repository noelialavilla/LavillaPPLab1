#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED

int cargarDescripcionColor(char descripcion[], int idColor, eColor colores[], int tamColores);
/** \brief recibe una cadena a la que le asigna la descripcion dependiendo del idColor recibido
 *
 * \param cadena de caracteres descripcion
 * \param int idColor
 * \param vector de eColor
 * \param tamaño de vector de eColor
 * \return devuelve 1 si pudo realizar la carga, -1 si no
 *
 */

 void listarColores(eColor colores[], int tamColor);
 /** \brief recibe una lsita de colores y la muestra por pantalla
  *
  * \param vector de eColor
  * \param int tamaño de vector de colores
  * \return devuelve 1 si pudo realizar la carga, -1 si no
  *
  */
