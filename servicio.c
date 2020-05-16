#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"

void listarServicios(eServicio servicios[], int tamServicios)
{
    system("cls");
    printf("\n***** Listado de servicios *****\n\n");
    printf("     Id       Descripcion         Precio\n");
    for (int i=0; i< tamServicios; i++)
    {
       printf("    %d    %10s            %.2f\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }
    printf("\n\n");
}


void cargarNombreServicio(char descripcion[20], int idServicio, eServicio servicios[], int tamServicios)
{
     int todoOk=0;
    for (int i =0; i< tamServicios; i++)
    {
        if (servicios[i].id == idServicio)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;

}
