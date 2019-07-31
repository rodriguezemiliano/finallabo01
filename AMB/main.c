#include <stdio.h>
#include <stdlib.h>
#include "LibreriaRodriguez.h"
#include "ArrayList.h"


int main()
{

    char on_off = 'Y';
    Persona personas[5];
    Persona* listaPersonas = (Persona*) malloc(sizeof(Persona)*5);

    FILE* _archivo;
    ArrayList* _lista = al_newArrayList();
    ArrayList* _listaRecuperada = al_newArrayList();

    Persona* p1 = newPersona("32022","emiliano","rodriguez");
    Persona* p2 = newPersona("32661","estefania","ramirez");
    Persona* p3 = newPersona("13455","anibal","pachano");
    Persona* p4 = newPersona("32022","raquel","manchini");
    Persona* p5 = newPersona("32001","manuel","rosas");
    Persona* p6 = newPersona("13235","eugenio","pomodoro");

    _lista->add(_lista,p1);
    _lista->add(_lista,p2);
    _lista->add(_lista,p3);
    _lista->add(_lista,p4);
    _lista->add(_lista,p5);
    _lista->add(_lista,p6);
    _lista->add(_lista,p2);
    _lista->add(_lista,p4);
    _lista->add(_lista,p6);

    ///////////////////////////////////////////////////////////////
    /*printf("Muestro la lista de personas\n");
    getche();
    verPersonas(_lista);
    getche();
    /////////////////////////////////////////////////////////////////
    printf("Guardo la lista de personas en datosFuncion.csv\n");
    getche();
    if(guardarPersonas(_lista,_archivo,"datosFuncion.csv")>0)
    {
        printf("La lista se guardo correctamente\n");
    }
    else
    {
        printf("ERROR!!! la lista no se pudo guardar\n");
    }
    ///////////////////////////////////////////////////////////////////////////////
    printf("Leo la lista de personas de datosFuncion.csv y lo cargo en un array distinto\n");
    getche();
    if(leerPersonas(_listaRecuperada,_archivo,"datosFuncion.csv")>0)
    {
        printf("La lista se cargo correctamente\n");
    }
    else
    {
        printf("ERROR!!! la lista no se pudo cargar\n");
    }
    //////////////////////////////////////////////////////////////////////////////////////////
    printf("Muestro la lista Recuperada de personas\n");
    verPersonas(_listaRecuperada);
    getche();*/
    /////////////////////////////////////////////////////////////////

    /*for(int i = 0 ; i < 3 ; i++)
    {
        (listaPersonas+i)->id = i;
        (listaPersonas+i)->id = i;
        strcpy((listaPersonas+i)->nombre,"Sin nomre");
        strcpy((listaPersonas+i)->apellido,"Sin apellido");
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d \n",(listaPersonas+i)->id );
        printf("%s \n",(listaPersonas+i)->nombre );
        printf("%d \n",(listaPersonas+i)->apellido );
    }*/





/*    printf("%d \n",p1->id);
    verPersona(p1);
    getche();*/




    inicializarPersonas(personas,5);
    inicializarPersonasConDatos(personas,5);
    do
    {
        switch(menu())
        {
            case 1: altaPersona(_lista);
                break;
            case 2: bajaPersona(_lista);
                break;
            case 3: modificarPersona(_lista);
                break;
            case 4: verPersonas(_lista);
                break;
            case 5: ordenarApellido(_lista);
                break;
            case 6: _lista = depurarRepetidos(_lista);
                break;
            case 9: on_off =  'N';
                break;
            default:
                break;
        }
    getche();
    }while(on_off != 'N' );




    return 0;
}
