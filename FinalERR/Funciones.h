#include "S_LogEntry.h"
#include "S_Service.h"
void procesarInfo(ArrayList* listaLog, ArrayList* listaService);
Service* getService(ArrayList* lista, int i);
LogEntry* getLog(ArrayList* lista, int i);
void listarLog(ArrayList* listaLog, ArrayList* listaService, char path[]);
void mostrarEstadistica(ArrayList* listaA, ArrayList* listaB);
