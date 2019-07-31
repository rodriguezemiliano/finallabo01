#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "ePelicula.h"
ePelicula* newPelicula(int id, char nombre[], int ano, char genero[])
{
    ePelicula* retorno = (ePelicula*) malloc(sizeof(ePelicula));

    if(retorno != NULL)
    {
        retorno->id = id;
        strcpy(retorno->nombre,nombre);
        retorno->ano = ano;
        strcpy(retorno->genero,genero);
    }


    return retorno;
}
eGenero* newGenero(int genero)
{
    eGenero* retorno = (eGenero*) malloc(sizeof(eGenero));
    strcpy(retorno->nombre, genero);
    return retorno;

}
auxPelicula* nAuxPelicula(int id, char nombre[], int ano, char genero[])
{
    auxPelicula* retorno = (ePelicula*) malloc(sizeof(ePelicula));

    if(retorno != NULL)
    {
        retorno->id = id;
        strcpy(retorno->nombre,nombre);
        retorno->ano = ano;
        strcpy(retorno->genero,genero);
        retorno->listaGenero = al_newArrayList();
    }


    return retorno;
}

int parseePeliculas(ArrayList* lista, char path[])
{
    char id[10];
    char nombre[30];
    int ano[10];
    char genero[30];
    int i = 0;
    int count;
    int largo = lista->len(lista);
    FILE* _archivo  = fopen(path,"r");

    if(_archivo != NULL)
    {
        do
        {
            count = fscanf(_archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,ano,genero);
            ePelicula* auxPelicula = newPelicula(atoi(id),nombre,atoi(ano),genero);
            lista->add(lista,auxPelicula);
            //mostrarPelicula(auxPelicula);
            i++;
        }while(i < 29);
    }
    fclose(_archivo);
    return i;
}
void mostrarePeliculas(ArrayList* lista)
{
    int largo = lista->len(lista);
    for(int i = 0 ; i < largo ; i++)
    {
        mostrarPelicula(getPeliculaPorIndice(lista,i));
    }
}
void mostrareAuxPeliculas(ArrayList* lista)
{
    int largo = lista->len(lista);
    auxPelicula* auxpelicua;
    for(int i = 0 ; i < largo ; i++)
    {
        auxPelicula* auxpelicua = getPeliculaPorIndice(lista,i);
        mostrarPelicula(getPeliculaPorIndice(lista,i));
        printf("%d ",auxpelicua->id);
        printf("%s ",auxpelicua->nombre);
        printf("%d ",auxpelicua->listaGenero->get(auxpelicua->listaGenero,i));
    }
}
void mostrarPelicula(ePelicula* ePelicula)
{
    printf("%d ",ePelicula->id);
    printf("%s ",ePelicula->nombre);
    printf("%d ",ePelicula->ano);
    printf("%s \n",ePelicula->genero);
}
ePelicula* getPeliculaPorIndice(ArrayList* lista, int indice)
{
    return (ePelicula*)lista->get(lista,indice);
}
void ordenarPeliculaPorId(ArrayList* lista)
{
    ePelicula* auxPelicula;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = i+1 ; j < largo ; j++)
        {

            if(getPeliculaPorIndice(lista,i)->id > getPeliculaPorIndice(lista,j)->id )
            {
                auxPelicula = (ePelicula*)(lista->get(lista,i));
                lista->set(lista,i,(ePelicula*)(lista->get(lista,j)));
                lista->set(lista,j,auxPelicula);
            }
        }
    }
}
ArrayList* depurarPeliculas(ArrayList* lista)
{
    int largo = lista->len(lista);
    int cont = 0;
    ArrayList* retorno = al_newArrayList();
    ArrayList* listaDepurada;
    auxPelicula* auxpelicula = nAuxPelicula(1," ", 1," ");


    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = 1+i ; j < largo ; j++)
        {

            if(strcmp(((ePelicula*)(lista->get(lista,i)))->nombre , ((ePelicula*)(lista->get(lista,j)))->nombre)==0)
            {
                ePelicula* p = getPeliculaPorIndice(lista,i);
                auxpelicula->id = p->id;
                strcpy(auxpelicula->nombre,p->nombre);
                auxpelicula->ano = p->ano;
                eGenero* genero = newGenero(p->genero);
                auxpelicula->listaGenero->add(auxpelicula->listaGenero,genero);
                listaDepurada->add(listaDepurada,auxpelicula);
                cont++;
            }
        }
    }


    return listaDepurada;
}
int guardarPeliculas(ArrayList* lista,  char path[])
{
    int i;
    int largo = lista->len(lista);
    FILE* _archivo = fopen(path,"w");

    for(i = 0 ; i < largo ; i++)
    {
        auxPelicula* pelicula;
        pelicula = (auxPelicula*) lista->get(lista,i);
        fprintf(_archivo,"%d,%s,%d \n",pelicula->id,pelicula->nombre,pelicula->ano);
    }
    fclose(_archivo);
    return i;
}

ArrayList* filtrarPorGenero(ArrayList* lista, char genero[])
{
    int largo = lista->len(lista);
    ArrayList* retorno = al_newArrayList();
    for(int i = 0 ; i < largo ; i++)
    {

        if(strcpy(getPeliculaPorIndice(lista,i)->genero, genero) == 0 )
        {
            retorno->add(getPeliculaPorIndice(lista,i));
        }
    }
    return retorno;
}

