#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Funciones.h"
//#include"mensajes.h"

int main()
{

    int opcion;
    char auxopcion[20];
    FILE* archivo;
    ArrayList* listaLog;
    ArrayList* listaService;

    listaLog=al_newArrayList();
    listaService=al_newArrayList();



    do{
        printf("1-Leer Log\n2-Procesar Informacion\n3-Mostrar estadistica\n4-\n5-\n6-Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            parseLogEntry(archivo,listaLog);
            parseService(archivo,listaService);
            verLogEntrys(listaLog);
            verServices(listaService);
            getche();
           /*parserReadService(archivo,listaService);
            mostrarListaLog(listaLog);
           printf("\n");
           mostrarListaService(listaService);*/

            break;
        case 2:
            procesarInfo(listaLog,listaService);
            verLogEntrys(listaLog);
            break;

        case 3:
            mostrarEstadistica(listaLog,listaService);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:
               printf("\nPrograma Finalizado\n");
            break;
        default:
            printf("ERROR:Ingrese una de las opciones indicadas!\n");
            break;
        }
        //system("pause");
        getche();
        system("cls");
    }while(opcion!=6);
    return 0;
}
