#include "ArrayList.h"



typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    int estado;


}Persona;




int getInt(char str[]);
int getId(char str[], int largo);
int getLargo(char str[], int largo);
char* getString(char str[], int largo);
int menu();
void saludo();
void sleep(int tiempo);
void opcion(int seleccion);
//Persona* altaPersona(Persona Persona[]);
void mostrarLista(Persona personas[],int largo);
void mostrarPersona(Persona personas[], int indice);
void inicializarPersonasConDatos(Persona personas[], int largo);
void inicializarPersonas(Persona personas[], int largo);
int getIndiceLibre(Persona personas[], int largo);
//void altaPersona(Persona personas[], int largo);
//void bajaPersona(Persona personas[], int largo);
//void modificarPersona(Persona personas[], int largo);
//int cargarPersona(Persona personas[], int indice, char modo);
//void setPersona(Persona personas[], int largo, int indice);
//int getIndice(Persona personas[], int largo, int id);
int getIdUnico (Persona personas[], int largo, int id);
////////////////////////////////////////////////////////////
//void* newPersona();
void* newPersona(char id[], char nombre[], char apellido[]);
void altaPersona(ArrayList* lista);
void bajaPersona(ArrayList* lista);
void modificarPersona(ArrayList* lista);
int cargarPersona(ArrayList* lista, char modo[]);
int esUnicoID(ArrayList* lista, int id);
Persona* setPersona(Persona* persona);
int getIndicePersona(ArrayList* lista, int id);
void setId(Persona* puntero, char str[], int largo);
void setNombre(Persona* puntero, char str[], int largo);
void setApellido(Persona* puntero, char str[], int largo);
void verPersona(Persona* this);
void verPersonas(ArrayList* lista);
ArrayList* depurarRepetidos(ArrayList* lista);
void ordenarApellido(ArrayList* lista);
int guardarPersonas(ArrayList* lista, FILE* _archivo, char path[]);
int leerPersonas(ArrayList* lista, FILE* _archivo, char path[]);
///////////////////////////////////////////////////////////
void inicializarArrayList();
