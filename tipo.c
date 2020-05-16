#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "tipo.h"

int cargarDescripcionTipo(char descripcion[], int idTipo, eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    for (int i =0; i< tamTipos; i++)
    {
        if (tipos[i].id == idTipo)
        {
            strcpy(descripcion, tipos[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;

}

void listarTipos(eTipo tipos[], int tamTipos)
{
    system("cls");
    printf("\n***** Listado de tipos *****\n\n");
    printf("     Id       Descripcion Tipo\n");
    for (int i=0; i< tamTipos; i++)
    {
       printf("    %d    %10s\n",tipos[i].id, tipos[i].descripcion);
    }
    printf("\n\n");
}
