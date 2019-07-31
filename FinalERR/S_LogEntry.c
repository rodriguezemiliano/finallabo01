#include <stdio.h>
#include <stdlib.h>
#include "LibreriaRodriguez.h"
#include "S_LogEntry.h"

int parseLogEntry(FILE* file, ArrayList* lista)
{
    int retorno = 0;
    char date[20];
    char time [20];
    char serviceId[10];
    char gravedad[10];
    char msg[65];
//    fopen(path,"r");
    file = fopen("C:/Users/chino/eclipse-workspace/Test/FinalERR/log.txt","r");


    if(file  != NULL)
    {
        do
        {
            fscanf(file,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date ,time ,serviceId, gravedad, msg);
            LogEntry* auxLog = newLog(date,time,getInt(serviceId),getInt(gravedad),msg);
            lista->add(lista,auxLog);
            retorno++;
        }while(!feof(file));
    }
    fclose(file);
    return retorno;
}
LogEntry* newLog(char date[], char time[], int service, int gravedad, char msg[])
{
    LogEntry* retorno = (LogEntry*) malloc(sizeof(LogEntry));

    if(retorno != NULL)
    {
        strcpy(retorno->date,date);
        strcpy(retorno->time,time);
        retorno->serviceId = service;
        retorno->gravedad = gravedad;
        strcpy(retorno->msg,msg);
    }
    return retorno;
}

void verLogEntry(LogEntry* log)
{

        printf("Date: %s \t",log->date);
        printf("Time: %s \t",log->time);
        printf("Service: %d \t",log->serviceId);
        printf("Gravedad: %d \t",log->gravedad);
        printf("MSg: %s \n",log->msg);

}
void verLogEntrys(ArrayList* lista)
{
    int largo = lista->len(lista);

    for(int i = 0 ; i < largo ; i++)
    {

        verLogEntry(((LogEntry*) lista->get(lista,i)));

    }
}

