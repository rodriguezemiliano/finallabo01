struct S_Service
{
    int id;
    char name[33];
    char eMail[65];
};
typedef struct S_Service Service;

Service* getServicePorIndice(ArrayList* lista, int i);
int parseService(FILE* file, ArrayList* lista);
void verService(Service* service);
void verServices(ArrayList* lista);
