#include "ArrayList.h"
typedef struct
{
    int id;
    char nombre[50];
    char email[50];
    char sexo[50];
    char pais[50];
    char password[50];
    char ip_address[100];
}Usuario;

Usuario* newUsuario(int id, char nombre[], char email[], char sexo[], char pais[], char password[], char ip_address[]);
int parseUsuarios(ArrayList* lista, char path[]);
void mostrarUsuario(Usuario* usuario);
void mostrarUsuarios(ArrayList* lista);
Usuario* getUsuarioPorIndice(ArrayList* lista, int indice);
void ordenarNombre(ArrayList* lista);
void ordenarNacionalidadNombre(ArrayList* lista);
