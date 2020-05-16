#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#define TAMTIPOS 5
#define TAMCOLORES 5
#define TAMSERVICIOS 3
#define TAMMASCOTAS 50
#define TAMTRABAJOS 100
#define CANTHARDCODE 5


int main()
{
     eTipo tipos[TAMTIPOS] = {
                                                                            { 1000, "Ave"},
                                                                            { 1001, "Perro"},
                                                                            { 1002, "Gato"},
                                                                            { 1003, "Roedor"},
                                                                            { 1004, "Pez"}
                                                           } ;
    eColor colores[TAMCOLORES] = {
                                                                            { 5000, "Negro"},
                                                                            { 5001, "Blanco"},
                                                                            { 5002, "Gris"},
                                                                            { 5003, "Rojo"},
                                                                            { 5004, "Azul"}
                                                            };

    eServicio servicios[TAMSERVICIOS] = {
                                                                            { 20000, "Corte", 250},
                                                                            { 20001, "Desparasitado", 300},
                                                                            { 20002, "Castrado", 400}
                                                            };
    eMascota mascotas[TAMMASCOTAS];
    eTrabajo trabajos[TAMTRABAJOS] ;

    int proxIdMascota = 100;
    int idTrabajos = 300;
    char seguir = 's';
    char confirma;
    int ordenamiento;
    proxIdMascota += CANTHARDCODE;
    inicializarMascotas(mascotas, TAMMASCOTAS);
    inicializarTrabajos(trabajos, TAMTRABAJOS);
    hardcodearMascotas(mascotas, 5);


    do
    {
        switch(menu())
        {
        case 'a':
             if (altaMascotas(&proxIdMascota, mascotas, TAMMASCOTAS, colores,  TAMCOLORES, tipos,  TAMTIPOS))
             {
                 printf("Se ha dado de alta la mascota satisfactoriamente. \n");
             }else{
                 printf("Se produjeron errores durante el dado de alta. No fue posible realizar el alta");
             }
            break;

        case 'b':
           modificarMascota(mascotas, TAMMASCOTAS, tipos, TAMTIPOS, colores, TAMCOLORES);
            break;
        case 'c':
            bajaMascota(mascotas, colores, tipos, TAMMASCOTAS, TAMCOLORES, TAMTIPOS);
            break;
        case 'd':
            ordenamiento = elegirTipoDeOrdenamiento();
            ordenarMascotas(mascotas, TAMMASCOTAS, ordenamiento);
            mostrarMascotas(mascotas, colores, tipos, TAMMASCOTAS, TAMCOLORES, TAMTIPOS);
            break;
        case 'e':
            listarTipos(tipos, TAMTIPOS);
            break;
        case 'f':
            listarColores(colores, TAMCOLORES);
            break;
        case 'g':
            listarServicios(servicios, TAMSERVICIOS);
            break;
        case 'h':
            if(altaTrabajo(&idTrabajos, trabajos, TAMTRABAJOS, mascotas, TAMMASCOTAS, colores, TAMCOLORES, tipos, TAMTIPOS, servicios, TAMSERVICIOS))
            {
                printf("Se ha realizado con exito el alta de trabajo.");
            }else
            {
                printf("Se produjeron errores durante el alta, no se realizo el alta.");
            }
            break;
        case 'i':
            mostrarTrabajos(trabajos, TAMTRABAJOS,  servicios, TAMSERVICIOS, mascotas, TAMMASCOTAS);
            break;
        case 'j':
            printf("Confirma salida?  ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");

    }
    while ( seguir == 's');
    return 0;
}
