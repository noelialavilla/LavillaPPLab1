#include <stdio.h>
#include <stdlib.h>
#include "trabajo.h"
#include "validaciones.h"

void inicializarTrabajos (eTrabajo trabajos[], int tam)
{
    for (int i =0; i < tam; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int buscarIndiceLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tam; i++)
    {
        if (trabajos[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamServicio, eMascota mascotas[], int tamMascotas)
{
    char nombreMascota [20];
    char nombreServicio [20];

    cargarNombreMascota(nombreMascota, trabajo.idMascota, mascotas, tamMascotas);
    cargarNombreServicio(nombreServicio, trabajo.idServicio, servicios, tamServicio);

    printf("\n%d    %d    %10s      %d     %10s    %d/%d/%d   \n", trabajo.id, trabajo.idMascota, nombreMascota, trabajo.idServicio,  nombreServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);

}

void mostrarTrabajos(eTrabajo trabajos[],int tamTrabajo, eServicio servicios[], int tamServicio, eMascota mascotas[], int tamMascotas)
{
    system("cls");
    int hayTrabajos = 0;
    printf("\n***** Listado Trabajos *****\n\n");
    printf("  Id       IdMascota NombreMascota  IdServicio   NombreServicio  Fecha\n");

    for (int i=0; i< tamTrabajo; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamServicio, mascotas, tamMascotas);
            hayTrabajos = 1;
        }
    }

    if ( hayTrabajos == 0)
    {
        printf("\nNo hay trabajos que listar \n");
    }


}

int altaTrabajo(int* proxId,eTrabajo trabajos[],  int tamTrabajos, eMascota mascotas[], int tamMascotas, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eServicio servicios[], int tamServicios)
{
    int idMascota;
    int fechaOk;
    int todoOk = -1;
    int servicioOk;
    int indiceMascota;
    int id;
    int indiceLibre;
    eTrabajo auxTrabajo;

    indiceLibre = buscarIndiceLibreTrabajo(trabajos, tamTrabajos);
    if (indiceLibre == -1)
    {
        printf("No hay lugar para nuevos trabajos. \n");

    }
    else
    {
        id = *proxId;
        auxTrabajo.id = id;
        mostrarMascotas(mascotas, colores, tipos, tamMascotas, tamColores, tamTipos);
        printf("Ingrese el id de la mascota a la que quiere asignarle un trabajo. \n");
        scanf("%d",&idMascota);
        indiceMascota = buscarMascota(idMascota, mascotas, tamMascotas);
        if (indiceMascota == -1)
        {
            printf("No existe mascota con el id ingresado. \n");

        }
        else
        {
            auxTrabajo.idMascota  = idMascota;
            printf("Usted esta a punto de contratar un servicio para la siguiente mascota: ");
            printf("  Id       IdMascota Nombre Mascota  Id Servicio   Nombre Servicio  Fecha\n");
            mostrarMascota(mascotas[indiceMascota], colores, tipos, tamColores, tamTipos);
            listarServicios(servicios, tamServicios);

            servicioOk =utn_getNumero(&auxTrabajo.idServicio, "Ingrese el servicio que desea solicitar: ", "Error, debe elegir uno de los servicios listados anteriormente. \n", 20000, 20002, 3);
            if (servicioOk)
            {
                fechaOk = obtenerFecha(&auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
                while(fechaOk != 1)
                {
                    system("cls");
                    printf("Fecha invalida. \n");
                    fechaOk = obtenerFecha(&auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
                }
                todoOk = 1;
                auxTrabajo.isEmpty = 0;
                trabajos[indiceLibre] = auxTrabajo;
                system("cls");
                printf("  Id       IdMascota NombreMascota  IdServicio   NombreServicio  Fecha\n");
                mostrarTrabajo(trabajos[indiceLibre], servicios, tamServicios, mascotas, tamMascotas);
            }

        }

    }
    return todoOk;

}
