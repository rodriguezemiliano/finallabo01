struct S_LogEntry
{
    char date[11];
    char time [6];
    int serviceId;
    int gravedad;
    char msg[65];
};
typedef struct S_LogEntry LogEntry;

int parseLogEntry(FILE* file, ArrayList* lista);
LogEntry* newLog(char date[], char time[], int service, int gravedad, char msg[]);
void verLogEntrys(ArrayList* lista);
void verLogEntry(LogEntry* log);
LogEntry* getLog(ArrayList* lista, int i);
