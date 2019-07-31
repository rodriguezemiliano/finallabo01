#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre_tema[50];
    char artista[50];
}Tema;

Tema* newTema(int id, char nombre_tema[], char artista[]);
Tema* getTemaPorIndice(ArrayList* lista, int indice);
void ordenarArtista(ArrayList* lista);
void ordenarArtistaNombre(ArrayList* lista);
