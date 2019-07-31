#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "S_LogEntry.h"
#include "S_Service.h"

void procesarInfo(ArrayList* listaLog, ArrayList* listaService)
{
    FILE* warning;
    FILE* error;
    ArrayList* listaWarning = al_newArrayList();
    ArrayList* listaMostrar = al_newArrayList();
    ArrayList* ListaError = al_newArrayList();

    printf("Fecha\t\t Hora\t Nombre Servicio\t Mesaje Error\t Gravedad\n");

    for(int i = 0 ; i < listaLog->len(listaLog) ; i++)
    {
        int gravedad = getLog(listaLog,i)->gravedad;
        LogEntry* auxLog = getLog(listaLog,i);

        if( gravedad < 3)
        {
            listaLog->remove(listaLog,i);
            i--;
        }
    }
     for(int i = 0 ; i < listaLog->len(listaLog) ; i++)
    {
        int gravedad = getLog(listaLog,i)->gravedad;
        LogEntry* auxLog = getLog(listaLog,i);
        if(gravedad == 3 )
        {
            if(auxLog->serviceId != 45)
            {
                listaWarning->add(listaWarning,auxLog);
            }
        }
        if(gravedad >= 4 && gravedad <= 7)
        {
            Service* s = getServicePorId(listaService,auxLog->serviceId);
            printf("%s\t %s\t %s\t\t %s\t \t%d\n",auxLog->date, auxLog->time, s->name, auxLog->msg, auxLog->gravedad);
        }

        if(gravedad > 7)
        {
            ListaError->add(ListaError,auxLog);
        }
    }
    listarLog(listaWarning,listaService,"warning.txt");
    listarLog(ListaError,listaService,"Error.txt");
}

void listarLog(ArrayList* listaLog, ArrayList* listaService, char path[])
{
    int i;
    int largo = listaLog->len(listaLog);
    FILE* _archivo = fopen(path,"w");

    if(_archivo != NULL)
    {
        for(i = 0 ; i < largo ; i++)
        {
            LogEntry* auxLog = getLog(listaLog,i);
            Service* auxService = getServicePorId(listaService,auxLog->serviceId);
            fprintf(_archivo,"%s,%s,%s,%s,%s,\n", auxLog->date, auxLog->time, auxService->name, auxLog->msg, auxService->eMail);
        }
    }

    fclose(_archivo);
    return i;

}
void mostrarEstadistica(ArrayList* listaLog, ArrayList* listaService)
{
    int max = 0;
    int count = 0;
    int flag = 1;
    int idMax = 0;
    int largo = listaLog->len(listaLog);
    LogEntry* Log_Max;
    LogEntry* Log_A;
    LogEntry* Log_B;

    for(int i = 0; i < largo ; i++)
    {
        Log_A = getLog(listaLog,i);

        for(int j = (i+1) ; j < largo ; j++)
        {
            Log_B = getLog(listaLog,j);

            if(Log_A->serviceId == Log_B->serviceId)
            {
                count++;
                if(flag > 0)
                {
                    max = count;
                    flag = -1;
                }
                if(count > max)
                {
                    max = count;
                    idMax = Log_A->serviceId;
                }
            }
        }
        count = 0;
    }
    verService(getServicePorId(listaService,idMax));
}

LogEntry* getLog(ArrayList* lista, int i)
{
    return (LogEntry*) lista->get(lista,i);
}

int grabarLog(ArrayList* lista, char path[])
{
    int i;
    int largo = lista->len(lista);
    FILE* _archivo = fopen(path,"w");

    if(_archivo != NULL)
    {
        for(i = 0 ; i < largo ; i++)
        {
            LogEntry* auxLog;
            auxLog = getLog(lista,i);
            fprintf(_archivo,"%s,%s,%d,%d,%s,\n",auxLog->date, auxLog->time, auxLog->gravedad, auxLog->serviceId, auxLog->msg);
        }
    }

    fclose(_archivo);
    return i;
}
