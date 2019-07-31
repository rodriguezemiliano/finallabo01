#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LibreriaRodriguez.h"
#include "ArrayList.h"

#define maxSTRING 10
#define maxID 5

int menu ()
{
    system("cls");
    printf("ELIJA UNA OPCION\n");
    printf("----------------\n");
    printf("1\\> ALTAS\n");
    printf("2\\> BAJAS\n");
    printf("3\\> MODIFICAR\n");
    printf("4\\> MOSTRAR\n");
    printf("5\\> ORDENAR\n");
    printf("6\\> DEPURAR\n");

    printf("----------------\n");
    printf("9\\> SALIR");
    /*printf("\n\n [ ");
    printf(" ]");*/

    /////////////////////////////
    char seleccion[5];
    fflush(stdin);
    scanf("%s",&seleccion);
    return getId(seleccion,1); ;
}


void opcion(int seleccion)
{
    switch(seleccion)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

int getInt(char str[])
{
    int retorno = atoi(str);

    if(retorno == 0)
    {
        printf("ERROR!!! el dato debe ser solo numeros\n");
    }
    return retorno;
}

int getId(char str[], int largo)
{
    int retorno = getInt(str);
    int auxLargo = getLargo(str,largo);

    while(retorno == 0 || auxLargo > largo)
    {

        printf("Reingrese: ");
        fflush(stdin);
        scanf("%s",str);
        retorno = getInt(str);
        auxLargo = getLargo(str,largo);
    }
    return retorno;
}
int getIdUnico (Persona personas[], int largo, int id)
{
    char auxStrig[100];

    while(getIndice(personas,largo,id)>=0)
    {
        printf("Ya existe una persona con ese\n");
        printf("Reingrese:  ");
        fflush(stdin);
        scanf("%s",&auxStrig);
        id = getId(auxStrig,5);
    }
    return id;
}
int getIndice(Persona personas[], int largo, int id)
{
    int retorno = -1;

    for(int i = 0 ; i < largo ; i++)
    {
        if(personas[i].id == id && personas[i].estado > 0
            )
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int getLargo(char str[], int largo)
{
    int retorno = 0;

    while(str[retorno] != '\0')
    {
        retorno++;
    }
    if(retorno > largo)
    {
        printf("ERROR!!! el dato es muy largo\n");
    }
    return retorno;
}
char* getString(char str[], int largo)
{
    int auxLargo = getLargo(str,largo);

    while(auxLargo > largo || isString(str) < 0)
    {
        printf("Reingrese: ");
        fflush(stdin);
        scanf("%s",str);
        auxLargo = getLargo(str,largo);

    }

    return str;
}
int isString (char str[])
{
    int retorno = 1;
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] < 96 || str[i] > 123)
        {
            retorno = -1;
        }
        i++;
    }
    if(retorno < 0)
    {

        printf("ERROR!!! caracteres incorrector \n");
    }
    return retorno;
}

void inicializarPersonas(Persona personas[], int largo)
{
    for(int i = 0 ; i < largo ; i++)
    {
        personas[i].id = i;
        strcpy(personas[i].nombre,"SIN NOBRE");
        strcpy(personas[i].apellido,"SIN APELLIDO");
        personas[i].estado = 0;
    }
}

void inicializarPersonasConDatos(Persona personas[], int largo)
{
    Persona p1 = {32022,"Emiliano","Rodriguez",1};
    Persona p2 = {78956,"Estefania","Ramirez",1};
    Persona p3 = {23145,"Anibal","Pachano",1};

    personas[0].id = p1.id;
    strcpy(personas[0].nombre,p1.nombre);
    strcpy(personas[0].apellido,p1.apellido);
    personas[0].estado = p1.estado;

    personas[1].id = p2.id;
    strcpy(personas[1].nombre,p2.nombre);
    strcpy(personas[1].apellido,p2.apellido);
    personas[1].estado = p2.estado;

    personas[2].id = p3.id;
    strcpy(personas[2].nombre,p3.nombre);
    strcpy(personas[2].apellido,p3.apellido);
    personas[2].estado = p3.estado;
}

int getIndiceLibre(Persona personas[], int largo)
{
    int retorno = -1;

    for(int i = 0 ; i < largo ; i++)
    {
        if(personas[i].estado == 0)
        {
            retorno = i;
        }
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
/*void* newPersona()
{
    Persona* persona = (Persona*) malloc(sizeof(Persona));

    if(persona)
    {
        persona->id = 100;
        strcpy(persona->nombre,"sin nombre");
        strcpy(persona->apellido,"sin apellido");
    }
    return persona;
}*/
void* newPersona(char id[], char nombre[], char apellido[])
{
    Persona* persona = (Persona*) malloc(sizeof(Persona));

    if(persona != NULL)
    {
        persona->id = getId(id,10);
        strcpy(persona->nombre,nombre);
        strcpy(persona->apellido,apellido);

        /*setId(persona,id,5);
        setNombre(persona,nombre,10);
        setApellido(persona,apellido,10);*/
    }
    return persona;
}
void setId(Persona* persona,char str[], int largo)
{
   persona->id = getId(str,largo);
}
void setNombre(Persona* persona, char str[], int largo)
{
    strcpy(persona->nombre,getString(str,largo));
}
void setApellido(Persona* persona, char str[], int largo)
{
    strcpy(persona->apellido,getString(str,largo));
}
void verPersona(Persona* persona)
{
    printf("%d \n",persona->id);
    printf("%s \n",persona->nombre);
    printf("%s \n",persona->apellido);
}
void verPersonas(ArrayList* lista)
{
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        verPersona(((Persona*)lista->get(lista,i)));
    }
}
int guardarPersonas(ArrayList* lista, FILE* _archivo, char path[])
{
    int i;
    int largo = lista->len(lista);
    _archivo = fopen(path,"w");

    for(i = 0 ; i < largo ; i++)
    {
        Persona* auxPersona;
        auxPersona = (Persona*) lista->get(lista,i);
        fprintf(_archivo,"%d,%s,%s\n",auxPersona->id,auxPersona->nombre,auxPersona->apellido);
    }
    fclose(_archivo);
    return i;
}

int leerPersonas(ArrayList* lista, FILE* _archivo, char path[])
{
    char id[10];
    char nombre[10];
    char apellido[10];
    int i = 0;
    int count;
    int largo = lista->len(lista);
    _archivo  = fopen(path,"r");

    if(_archivo  != NULL)
    {
        do
        {
            count = fscanf(_archivo,"%[^,] , %[^,] , %[^\n]",id ,nombre ,apellido );
            Persona* auxPersona = newPersona(id,nombre,apellido);
            lista->add(lista,auxPersona);
            i++;

        }while(!feof(_archivo));
    }
    fclose(_archivo);
    return i;
}
int esUnicoID(ArrayList* lista, int id)
{
    int retorno = 1;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        if(((Persona*)lista->get(lista,i))->id == id)
        {
            retorno = -1;
            break;
        }
    }
    return retorno;
}

Persona* setPersona(Persona* persona)
{
     char str[100];
     printf("Nombre: \n");
     fflush(stdin);
     scanf("%s",str);
     setNombre(persona,str,maxSTRING);
     printf("Apellido: \n");
     fflush(stdin);
     scanf("%s",str);
     setApellido(persona,str,maxSTRING);
     return persona;
}
ArrayList* depurarRepetidos(ArrayList* lista)
{
    int largo = lista->len(lista);
    int cont = 0;
    printf("---SE ELIMINARON---\n");

    for(int i = 0 ; i < lista->len(lista) ; i++)
    {
        for(int j = 1+i ; j < lista->len(lista) ; j++)
        {
            if(((Persona*)(lista->get(lista,i)))->id == ((Persona*)(lista->get(lista,j)))->id)
            {
                verPersona((Persona*)lista->pop(lista,j));
                cont++;
            }
        }
    }
    printf("--- %d ELEMENTOS---\n",cont);
    return lista;
}
void ordenarApellido(ArrayList* lista)
{
    Persona* auxPersona;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = 0 ; j < largo ; j++)
        {
            if(strcmp(((Persona*)(lista->get(lista,i)))->apellido,((Persona*)(lista->get(lista,j)))->apellido)< 0)
            {
                auxPersona = (Persona*)(lista->get(lista,i));
                lista->set(lista,i,(Persona*)(lista->get(lista,j)));
                lista->set(lista,j,auxPersona);
            }
        }
    }
}
void altaPersona(ArrayList* lista)
{
    system("cls");
    printf("ALTA DE PERSONAS\n");

    if(cargarPersona(lista,"a") > 0)
    {
        printf("La persona se dio de alta correctamente\n");
    }
    else
    {

        printf("Ya existe una persona \n");
    }
}
void bajaPersona(ArrayList* lista)
{
    system("cls");
    printf("BAJA DE PERSONAS\n");

    if(cargarPersona(lista,"b") < 0)
    {
        printf("No existe la persona\n");
    }
    else
    {

        printf("se borro correctamente\n");
    }

}
void modificarPersona(ArrayList* lista)
{
    system("cls");
    printf("MODIFICAR DE PERSONAS\n");

    if(cargarPersona(lista,"m") < 0)
    {
        printf("No existe la persona\n");
    }
    else
    {
        printf("se modifico correctamente\n");
    }

}

int cargarPersona(ArrayList* lista, char modo[])
{
    int retorno = -1;
    int id;
    char str[100];
    Persona* persona;

    printf("Ingrese:\n");
    printf("ID: \n");
    fflush(stdin);
    scanf("%s",str);
    id = getId(str,5);

    if(modo == "a")
    {
        if(esUnicoID(lista,id)>0)
        {
            persona = newPersona(str,"sin nombre","sin apellido");
            persona = setPersona(persona);

            printf("Confimar para agregar la persona? Y/N \n");
            fflush(stdin);
            scanf("%s",str);
            if(getString(str,1)!= "n")
            {
                lista->add(lista,persona);
                retorno = 1;
            }
        }
    }
    else
    {
        if(esUnicoID(lista,id)<0)
        {
            int indice = getIndicePorId(lista,id);
            verPersona((Persona*)lista->get(lista,indice));

            if(modo == "b")
            {
                printf("Confimar para borrar la persona? Y/N \n");
                fflush(stdin);
                scanf("%s",str);

                if(getString(str,1)!= "n")
                {
                    ((Persona*) lista->get(lista,indice))->estado = -1;
                    lista->pop(lista,indice);
                    retorno = 1;
                }
            }
            else
            {

                printf("Confirmar los cambios Y/N");
                scanf("%s",str);
                if(getString(str,1)!= "n")
                {
                    persona = (Persona*) lista->get(lista,indice);
                    persona = setPersona(persona);
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}
int getIndicePorId(ArrayList* lista, int id)
{
    int retorno = -1;
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {
        Persona* persona = (Persona*)lista->get(lista,i);
        if(persona->id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
Persona* getPersonaPorId(ArrayList* lista, int id)
{
    int largo = lista->len(lista);
    Persona* persona;
    for(int i = 0 ; i < largo ; i++)
    {
        persona = (Persona*) lista->get(lista,i);
        if(persona->id == id)
        {
            break;
        }
    }
    return persona;
}


/*int getIndice(Persona personas[],int largo, int id)
{
    int retorno = -1;

    for(int i = 0 ; i < 0 ; i++)
    {
        if(personas[i].id == id)
        {
            retorno = 1;
        }
    }
    return retorno;
}*/


/*void mostrarPersona(Persona personas[], int indice)
{
    printf("ID: %d \n",personas[indice].id);
    printf("Nombre: %s \n",&personas[indice].nombre);
    printf("Apellido: %s \n",&personas[indice].apellido);
}*/
/*void mostrarLista(Persona personas[], int largo)
{
    for(int i = 0 ; i < largo ; i++)
    {
        if(personas[i].estado == 1)
        {
            mostrarPersona(personas,i);
        }
    }
}*/

/*void altaPersona(Persona personas[], int largo)
{
    system("cls");
    printf("ALTA DE PERSONAS\n");

    if(cargarPersona(personas, largo, 'a') < 0)
    {
        printf("La persona no pudo ser dada de alta, o el array esta completo\n");
    }
    else
    {
        printf("La persona se dio de alta correctamente\n");
    }
}*/

/*void bajaPersona(Persona personas[], int largo)
{
    system("cls");
    printf("BAJA DE PERSONAS\n");
    if(cargarPersona(personas,largo,'b') < 0)
    {
        printf("No existe la persona\n");
    }
    else
    {

       printf("se borro correctamente\n");
    }

}*/
/*
void modificarPersona(Persona personas[], int largo)
{
    system("cls");
    printf("MODIFICAR PERSONAS\n");

    if(cargarPersona(personas,largo,'m') < 0)
    {
        printf("No existe la persona\n");
    }
    else
    {
        printf("La persona se modifico correctamente\n");

    }



}*/
/*int cargarPersona(Persona personas[], int largo, char modo)
{
    int retorno = -1;
    int indice;
    char auxString[100];

    if(modo == 'a')
    {
        indice = getIndiceLibre(personas,largo);

        if(indice >= 0)
        {
            printf("INGRESE:\n");
            printf("ID ");
            scanf("%s",&auxString);
            personas[indice].id = getIdUnico(personas,5,getId(auxString,5));
//            setPersona(personas,largo,indice);
            personas[indice].estado = 1;
            retorno = 1;
        }
    }
    else
    {
        printf("INGRESE:\n");
        printf("ID ");
        fflush(stdin);
        scanf("%s",&auxString);
        indice = getIndice(personas,largo,getId(auxString,5));

        if(indice >= 0)
        {
            mostrarPersona(personas,indice);

            if(modo == 'm')
            {
//                setPersona(personas,largo,indice);
                retorno = 1;
            }
            else
            {
                printf("Confirma para borrar? S/N: \n");
                fflush(stdin);
                scanf("%s",&auxString);

                if(getString(auxString,1)!= "n")
                {
                    personas[indice].estado = 0;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}*/

/*void setPersona(Persona personas[], int largo, int indice)
{
    char auxString[100];

    printf("\nNombre: ");
    scanf("%s",&auxString);
    strcpy(personas[indice].nombre, getString(auxString, 10));
    printf("\nApellido: ");
    scanf("%s",&auxString);
    strcpy(personas[indice].apellido, getString(auxString, 10));
}

}*/


