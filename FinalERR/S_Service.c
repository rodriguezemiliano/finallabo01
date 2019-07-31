#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibreriaRodriguez.h"
#include "S_Service.h"

Service* newService(int id, char name[33], char eMail[65])
{
    Service* retorno = malloc(sizeof(Service));

    retorno->id = id;
    strcpy( retorno->name,name);
    strcpy( retorno->eMail,eMail);

    return retorno;
}
Service* getServicePorIndice(ArrayList* lista, int i)
{
    return (Service*) lista->get(lista,i);
}
Service* getServicePorId(ArrayList* lista, int id)
{
    int largo = lista->len(lista);
    Service* retorno;
    for(int i = 0 ; i < largo ; i++)
    {
        retorno = (Service*)lista->get(lista,i);
        if(retorno->id == id)
        {
            break;
        }
    }
    return retorno;
}

int parseService(FILE* file, ArrayList* lista)
{
    int retorno = 0;
    char id[10];
    char name[33];
    char eMail[65];
    file = fopen("C:/Users/chino/eclipse-workspace/Test/FinalERR/Service.txt","r");

    if(file  != NULL)
    {
        do
        {
            fscanf(file,"%[^;];%[^;];%[^\n]\n",id ,name ,eMail);
            Service* auxService = newService(getInt(id),name,eMail);
            lista->add(lista,auxService);

            retorno++;
        }while(!feof(file));
    }
    fclose(file);
    return retorno;
}
void verService(Service* service)
{
    printf("ID: %d \t",service->id);
    printf("Name: %s \t",service->name);
    printf("eMail: %s \n",service->eMail);
}
void verServices(ArrayList* lista)
{
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        verService(((Service*) lista->get(lista,i)));
    }
}

