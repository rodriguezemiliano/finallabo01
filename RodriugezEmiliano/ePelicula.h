#include "ArrayList.h"
typedef struct
{
    int id;
    char nombre[30];
    int ano;
    char genero[30];

}ePelicula;
typedef struct
{
    int id;
    char nombre[30];
    int ano;
    char genero[30];
    ArrayList* listaGenero;
}auxPelicula;
typedef struct
{
    char nombre[30];

}eGenero;
ePelicula* newPelicula(int id, char nombre[], int ano, char genero[]);
int parseUsuarios(ArrayList* lista, char path[]);
ePelicula* getPeliculaPorIndice(ArrayList* lista, int indice);
ArrayList* depurarPeliculas(ArrayList* lista);
