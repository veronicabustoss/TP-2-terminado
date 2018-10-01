#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define TRUE 0
#define FALSE -1
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployee;

int initEmployees(eEmployee* lista, int len);

int buscarLugarLibre(eEmployee* lista, int len);

int addEmployee(eEmployee* lista, int len, int id, char name[],char lastName[],float salary,int sector);

int menuDeOpciones();

int findEmployeeById(eEmployee* lista, int len , int id);

int mostrarUnEmpleado(eEmployee* lista, int indice);

int removeEmployee(eEmployee* lista, int len, int id);

int modifyEmployee(eEmployee*lista,int len,  int id);

int printEmployees(eEmployee* lista, int len);

int sortEmployees(eEmployee* lista, int len);

int promedioSalary(eEmployee* lista, int len);

#endif
