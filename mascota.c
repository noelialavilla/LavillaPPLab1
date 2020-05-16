#include <stdio.h>
#include <stdlib.h>
#include "mascota.h"
#include "validaciones.h"
#include "datawarehouse.h"
#include "string.h"
#include <ctype.h>
#define NOTOK -1
#define OK 1

void inicializarMascotas (eMascota mascotas[], int tam)
{
    for (int i =0; i < tam; i++)
    {
        mascotas[i].isEmpty = 1;
    }
}

void hardcodearMascotas(eMascota mascotas[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        mascotas[i].id = idsMascotas[i];
        strcpy(mascotas[i].nombre, nombres[i]);
        mascotas[i].idTipo = idsTipos[i];
        mascotas[i].idColor = idsColores[i];
        mascotas[i].edad = edades[i];
        mascotas[i].isEmpty = 0;

    }
}

void mostrarMascota(eMascota mascota, eColor colores[], eTipo tipos[], int tamColor, int tamTipos)
{

    char descripcionColor [20];
    char descripcionTipo[20];

    cargarDescripcionColor(descripcionColor, mascota.idColor, colores,  tamColor);
    cargarDescripcionTipo(descripcionTipo, mascota.idTipo, tipos, tamTipos);

    printf("%d    %10s    %d  %10s   %d %10s       %d \n", mascota.id, mascota.nombre, mascota.idTipo, descripcionTipo, mascota.idColor, descripcionColor, mascota.edad);

}

void mostrarMascotas(eMascota mascotas[], eColor colores[], eTipo tipos[],int tamMascotas, int tamColores, int tamTipos)
{
    system("cls");
    int hayMascotas = 0;
    printf("\n***** Listado Mascotas *****\n\n");
    printf("  Id       Nombre    Id Tipo Desc. Tipo  Id Color  Color     Edad\n");

    for (int i=0; i< tamMascotas; i++)
    {
        if (mascotas[i].isEmpty == 0)
        {
            mostrarMascota(mascotas[i], colores, tipos,  tamColores, tamTipos);
            hayMascotas = 1;
        }
    }

    if ( hayMascotas == 0)
    {
        printf("\nNo hay mascotas que listar \n");
    }

}

int altaMascotas(int* proxId, eMascota mascotas[], int tamMascotas, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int indice = buscarIndiceLibreMascotas(mascotas, tamMascotas);
    eMascota auxMascota;
    int todoOk =-1;
    int nombreOk;
    int tipoOk;
    int edadOk;
    int colorOk;
    int id;

    system("cls");

    printf("***** Alta Mascota ***** \n \n");

    if( indice == -1 )
    {
        printf("Sistema completo. No hay lugar para nuevos ingresos. \n\n");

    }
    else
    {

        id = *proxId;
        auxMascota.id = id;

        nombreOk = utn_getNombre(auxMascota.nombre, 20, "Ingrese nombre de la mascota: ", "\nError, el nombre debe contener de 1 a 20 letras.\n", 3);

        listarTipos(tipos, tamTipos);
        tipoOk = utn_getNumero(&auxMascota.idTipo, "Ingrese tipo de mascota: ", "\nError, debe estar comprendido entre 1000 y 1004. \n", 1000, 1004, 3);

        listarColores(colores, tamColores);
        colorOk = utn_getNumero(&auxMascota.idColor, "Ingrese color de mascota: ", "\n Error, el id de color debe estar comprendido entre 5000 y 5004\n", 5000, 5004, 3);

        edadOk = utn_getNumero(&auxMascota.edad, "Ingrese edad de mascota: ", "\n Error, la edad debe estar comprendida entre 1 y 100.\n ", 1, 100, 3);

        auxMascota.isEmpty = 0;

        if (nombreOk && tipoOk && colorOk && edadOk)
        {
            mascotas[indice] = auxMascota;
            system("cls");
            printf("  Id       Nombre    Id Tipo Desc. Tipo  Id Color  Color     Edad\n");
            mostrarMascota(mascotas[indice], colores, tipos, tamColores, tamTipos);
            (*proxId)++;
            todoOk =1;
        }else
        {
            printf("Surgieron problemas durante el alta de la mascota. Por favor intentelo de nuevo.\n");
        }


    }
    return todoOk;

}

int buscarIndiceLibreMascotas(eMascota mascotas[], int tam)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tam; i++)
    {
        if (mascotas[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}

char menu()
{
    char opcion;

    system("cls");
    printf("**** Gestion de Mascotas **** \n\n");
    printf("A.  Alta mascota. \n");
    printf("B.  Modificar mascota. \n");
    printf("C.  Baja mascota.\n");
    printf("D.  Listar mascotas.\n");
    printf("E.  Listar tipos.\n");
    printf("F.  Listar colores.\n");
    printf("G.  Listar servicios.\n");
    printf("H.  Alta trabajo\n");
    printf("I.  Listar trabajos\n");
    printf("J.  Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return tolower(opcion);

}

void modificarMascota(eMascota mascotas[], int tamMascotas, eTipo tipos[], int tamTipos, eColor colores[], int tamColores)
{
    int id;
    int indice;
    int obtenerTipoOk;
    int obtenerEdadOk;
    eMascota auxMascota;

    system("cls");

    mostrarMascotas(mascotas, colores, tipos, tamMascotas, tamColores, tamTipos);
    printf("Ingrese id de la mascota  de la cual desea realizar una modificacion: ");
    scanf("%d",&id);

    indice = buscarMascota(id, mascotas, tamMascotas);
    if (indice == -1)
    {
        printf("No hay registro de una mascota con el Id: %d. \n", id);
    }
    else
    {
        printf("Usted está a punto de modificar la siguiente mascota: \n");
        printf("  Id       Nombre    Id Tipo Desc. Tipo  Id Color  Color     Edad\n");
        mostrarMascota(mascotas[indice], colores, tipos, tamColores, tamTipos);
        switch(submenuModif())
        {
        case 1:
            listarTipos(tipos, tamTipos);
            printf("\nIngrese id del tipo elegido:");
            obtenerTipoOk = utn_getNumero(&auxMascota.idTipo, "Ingrese id del tipo elegido: [RANGO: 1000 - 1004]", "Error. El tipo debe ser uno de los mostrados anteriormente.", 1000, 1004, 3);
            if (obtenerTipoOk)
            {
                mascotas[indice].idTipo = auxMascota.idTipo;
                printf("Se ha modificado el tipo de mascota con éxito.");
            }
            else
            {
                printf("No se ingreso un tipo de mascota correcto. Vuelva a intentarlo. \n");
            }

            break;
        case 2:
            printf("\nIngrese la nueva edad de la mascota: ");
            obtenerEdadOk = utn_getNumero(&auxMascota.edad, "Ingrese edad de la mascota: [RANGO: 1 - 100]", "Error. La edad debe estar entre 1 y 100 años.", 1, 100, 3);
            if (obtenerEdadOk)
            {
                mascotas[indice].edad = auxMascota.edad;
                printf("Se ha modificado la edad de la mascota con éxito.");
            }
            else
            {
                printf("No se ingreso una edad  de mascota valida. Vuelva a intentarlo. \n");
            }

            break;

        }
    }
}

int buscarMascota(int id, eMascota mascotas[], int tamMascotas)
{
    int indiceBuscado = -1;
    for (int i =0; i< tamMascotas; i++)
    {
        if (mascotas[i].id == id && mascotas[i].isEmpty ==0)
        {
            indiceBuscado = i;
            break;
        }
    }
    return indiceBuscado;
}

int submenuModif()
{
    int opcion;
    printf("***** Modificar Mascota ***** \n \n");
    printf("1. Modificar tipo.\n");
    printf("2. Modificar edad.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

void bajaMascota(eMascota mascotas[], eColor colores[], eTipo tipos[],int tamMascotas, int tamColor, int tamTipo)
{
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Mascota ***** \n \n");

    printf("Ingrese id de la mascota que desea dar de baja: ");
    scanf("%d",&id);

    indice = buscarMascota(id, mascotas, tamMascotas);
    if (indice == -1)
    {
        printf("No hay registro de una mascota con el Id: %d. \n", id);
    }
    else
    {
        mostrarMascota(mascotas[indice], colores, tipos, tamColor, tamTipo);
        printf("Confirma la baja de la mascota mostrada?  ");
        fflush(stdin);
        scanf("%c", &confirma);
        if (tolower(confirma)== 's')
        {
            mascotas[indice].isEmpty = 1;
            printf("Se realizo la baja de la mascota solicitada. \n");
        }
        else
        {
            printf("Se ha cancelado la operacion. \n");
        }

    }

}

void cargarNombreMascota(char descripcion[20], int idMascota, eMascota mascotas[], int tamMascotas)
{

    for (int i =0; i< tamMascotas; i++)
    {
        if (mascotas[i].id == idMascota)
        {
            strcpy(descripcion, mascotas[i].nombre);
        }
    }

}

void ordenarMascotas(eMascota mascotas[], int tam, int orden)
{
    eMascota auxMascota;

    if (orden ==1 )
    {
        for (int i = 0; i< tam-1; i++)
        {
            for (int j= i+1;  j< tam;  j++)
            {
                if (mascotas[i].idTipo > mascotas[j].idTipo)

                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if (mascotas[i].idTipo == mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre) > 0 )
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
    }
    else if(orden == 2)
    {
        for (int i = 0; i< tam-1; i++)
        {
            for (int j= i+1;  j< tam;  j++)
            {
                if (mascotas[i].idTipo < mascotas[j].idTipo)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
                else if (mascotas[i].idTipo == mascotas[j].idTipo && strcmp(mascotas[i].nombre, mascotas[j].nombre) < 0 )
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }

            }
        }
    }
}

int elegirTipoDeOrdenamiento()
{
    int opcion;
    system("cls");
    printf("*****Ordenamiento ******\n");
    printf("En que orden le gustaria ordenar las mascotas? \n");
    printf("1.  Ascendente.\n");
    printf("2.  Descendente.\n");
    utn_getNumero(&opcion, "Ingrese orden: ","El orden solo puede ser 1 o 2", 1, 2, 3);

    return opcion;
}
