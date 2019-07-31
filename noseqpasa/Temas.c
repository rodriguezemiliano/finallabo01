#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Temas.h"

Tema* newTema(int id, char nombre_tema[], char artista[])
{
    Tema* retorno = (Tema*) malloc(sizeof(Tema));

    retorno->id = id;
    strcpy(retorno->nombre_tema,nombre_tema);
    strcpy(retorno->artista,artista);
    return retorno;
}

int parseTemas(ArrayList* lista, char path[])
{
    char id[10];
    char nombre_tema[30];
    char artista[33];

    int i = 0;
    int count;
    int largo = lista->len(lista);
    FILE* _archivo  = fopen(path,"r");

    if(_archivo != NULL)
    {
        do
        {
            count = fscanf(_archivo,"%[^,],%[^,],%[^\n]\n",id,nombre_tema,artista);
            Tema* auxTema = newTema(atoi(id),nombre_tema,artista);
            lista->add(lista,auxTema);
            //mostrarTema(auxTema);
            i++;
        }while(!feof(_archivo));
    }
    fclose(_archivo);
    return i;
}
void mostrarTemas(ArrayList* lista)
{
    int largo = lista->len(lista);
    for(int i = 0 ; i < largo ; i++)
    {
        mostrarTema(getTemaPorIndice(lista,i));
    }
}
void mostrarTema(Tema* Tema)
{
    printf("%d\t",Tema->id);
    printf("%s\t\t",Tema->nombre_tema);
    printf("%s\n",Tema->artista);
}
Tema* getTemaPorIndice(ArrayList* lista, int indice)
{
    return ((Tema*) lista->get(lista,indice));
}
void ordenarArtista(ArrayList* lista)
{
    Tema* auxTema;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = 0 ; j < largo ; j++)
        {
            if(strcmp(((Tema*)(lista->get(lista,i)))->artista,((Tema*)(lista->get(lista,j)))->artista)>0)
            {
                auxTema = getTemaPorIndice(lista,i);
                lista->set(lista,i,getTemaPorIndice(lista,j));
                lista->set(lista,j,auxTema);
            }
        }
    }
}
void ordenarArtistaNombre(ArrayList* lista)
{
    Tema* auxTema;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = 0 ; j < largo ; j++)
        {
            if(strcmp(((Tema*)(lista->get(lista,i)))->artista,((Tema*)(lista->get(lista,j)))->artista)< 0)
            {
                if(strcmp(((Tema*)(lista->get(lista,i)))->nombre_tema,strcmp(((Tema*)(lista->get(lista,i)))->nombre_tema)))
                {
                    auxTema = (Tema*)(lista->get(lista,i));
                    lista->set(lista,i,(Tema*)(lista->get(lista,j)));
                    lista->set(lista,j,auxTema);
                }
            }
        }
    }
    ordenarNombre(lista);

}
