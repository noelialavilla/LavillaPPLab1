#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "string.h"

int cargarDescripcionColor(char descripcion[], int idColor, eColor colores[], int tamColores)
{
    int todoOk=0;
    for (int i =0; i< tamColores; i++)
    {
        if (colores[i].id == idColor)
        {
            strcpy(descripcion, colores[i].nombreColor);
            todoOk =1;
        }
    }
    return todoOk;

}

void listarColores(eColor colores[], int tamColor)
{
    system("cls");
    printf("\n***** Listado de colores *****\n\n");
    printf("   Id         Nombre Color\n");
    for (int i=0; i< tamColor; i++)
    {
       printf("    %d    %10s\n",colores[i].id, colores[i].nombreColor);
    }
    printf("\n\n");
}
