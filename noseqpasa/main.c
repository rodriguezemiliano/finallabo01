#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#include "Temas.h"
#include "ArrayList.h"

int main()
{
    ArrayList* listaUsuarios = al_newArrayList();
    ArrayList* listaTemas = al_newArrayList();
    ArrayList* listaEscuchados = al_newArrayList();

    parseUsuarios(listaUsuarios,"usuarios.dat");
    ordenarNombre(listaUsuarios);
    ordenarNacionalidadNombre(listaUsuarios);
    mostrarUsuarios(listaUsuarios);
    parseTemas(listaTemas,"C:/Users/chino/eclipse-workspace/Test/noseqpasa/temas");
    ordenarArtista(listaTemas);
    mostrarTemas(listaTemas);
    printf("Hello world!\n");
    return 0;
}
