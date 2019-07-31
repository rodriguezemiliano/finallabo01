#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LibreriaRodriguez.h"
#include "ArrayList.h"

int main()
{
    char str[100];
    //printf("Ingrese nombre de archivo para cargar...\n");
    //scanf("%s",str);
    ArrayList* listaPeliculas = al_newArrayList();
    int cont = parseePeliculas(listaPeliculas,"D:/RodriugezEmiliano/datosMF1.csv");
    if( cont > 0)
    {
        printf("se cargaron %d\n",cont);
    }
    else
    {
        printf("No se pudo cargar la lista");
    }

    getche();
    mostrarePeliculas(listaPeliculas);

    ordenarPeliculaPorId(listaPeliculas);
    getche();
    mostrarePeliculas(listaPeliculas);
    /////mostrareAuxPeliculas(listaPeliculas,);
    ArrayList* listaPeliculasDepurada = depurarPeliculas(listaPeliculas);
    ArrayList* listaFiltradaPorGenero = filtrarPorGenero(listaPeliculas,"Accion");

    printf("escribo depurados.csv");
    guardarPeliculas(listaPeliculasDepurada,"D:/RodriugezEmiliano/depurados.csv");
    getche();
    printf("escribo filtrados.csv");
    guardarPeliculas(listaPeliculasDepurada,"D:/RodriugezEmiliano/filtrados.csv");





    getche();
    return 0;
}
