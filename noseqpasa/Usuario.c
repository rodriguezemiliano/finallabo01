#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Usuario.h"

Usuario* newUsuario(int id, char nombre[], char email[], char sexo[], char pais[], char password[], char ip_address[])
{
    Usuario* retorno = (Usuario*) malloc(sizeof(Usuario));

    if(retorno != NULL)
    {
        retorno->id = id;
        strcpy(retorno->nombre,nombre);
        strcpy(retorno->email,email);
        strcpy(retorno->sexo,sexo);
        strcpy(retorno->pais,pais);
        strcpy(retorno->password,password);
        strcpy(retorno->ip_address,ip_address);
    }


    return retorno;
}

int parseUsuarios(ArrayList* lista, char path[])
{
    char id[10];
    char nombre[30];
    char email[33];
    char sexo[1];
    char pais[30];
    char password[8];
    char ip_address[30];
    int i = 0;
    int count;
    int largo = lista->len(lista);
    FILE* _archivo  = fopen(path,"r");

    if(_archivo != NULL)
    {
        do
        {
            count = fscanf(_archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,email,sexo,pais,password,ip_address);
            Usuario* auxUsuario = newUsuario(atoi(id),nombre,email,sexo,pais,password,ip_address);
            lista->add(lista,auxUsuario);
            mostrarUsuario(auxUsuario);
            i++;
        }while(!feof(_archivo));
    }
    fclose(_archivo);
    return i;
}
void mostrarUsuarios(ArrayList* lista)
{
    int largo = lista->len(lista);
    for(int i = 0 ; i < largo ; i++)
    {
        mostrarUsuario(getUsuarioPorIndice(lista,i));
    }
}
void mostrarUsuario(Usuario* usuario)
{
    printf("%d\t",usuario->id);
    printf("%s\t",usuario->nombre);
    printf("%s\t\t",usuario->email);
    printf("%s\t\t",usuario->sexo);
    printf("%s\t\t",usuario->pais);
    printf("%s\t\t",usuario->password);
    printf("%s\n",usuario->ip_address);
}
Usuario* getUsuarioPorIndice(ArrayList* lista, int indice)
{
    return ((Usuario*) lista->get(lista,indice));
}
void ordenarNombre(ArrayList* lista)
{
    Usuario* auxUsuario;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = 0 ; j < largo ; j++)
        {
            if(strcmp(((Usuario*)(lista->get(lista,i)))->nombre,((Usuario*)(lista->get(lista,j)))->nombre)>0)
            {
                auxUsuario = getUsuarioPorIndice(lista,i);
                lista->set(lista,i,getUsuarioPorIndice(lista,j));
                lista->set(lista,j,auxUsuario);
            }
        }
    }
}
void ordenarNacionalidadNombre(ArrayList* lista)
{
    Usuario* auxUsuario;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = 0 ; j < largo ; j++)
        {
            if(strcmp(((Usuario*)(lista->get(lista,i)))->pais,((Usuario*)(lista->get(lista,j)))->pais)< 0)
            {
                auxUsuario = (Usuario*)(lista->get(lista,i));
                lista->set(lista,i,(Usuario*)(lista->get(lista,j)));
                lista->set(lista,j,auxUsuario);
            }
        }
    }
    ordenarNombre(lista);

}
