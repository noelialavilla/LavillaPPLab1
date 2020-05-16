#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

#endif // FECHA_H_INCLUDED

int obtenerFecha(int* diaAux, int * mesAux, int* anioAux);
/** \brief recibe las referencias a memoria de dia mes y año y le pide al usuario valores validos para las mismas
 *
 * \param puntero a dia
 * \param puntero a mes
 * \param puntero a año
 * \return 1 si pudo obtener la fecha, -1 si no
 *
 */
