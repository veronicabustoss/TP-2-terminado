#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#include "ArrayEmployees.h"
#include "utn.h"


int main()
{
    char seguir= 's';

    eEmployee empleados[MAX];

    initEmployees( empleados, MAX );



    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int lugarLibre;
    int flag=0;
    //int mostrar;

    do
    {

        switch(menuDeOpciones())//creo la funcion menu, donde me figura las opciones
        {
            case 0:
                flag=1;
                
                addEmployee(empleados, MAX, 0, "Pedro", "Soarez", 12000, 23);
                addEmployee(empleados, MAX, 1, "Monica", "Barriento", 20000, 25);
                addEmployee(empleados, MAX, 2, "Mabel", "Bustos", 14000.35, 28);
                addEmployee(empleados, MAX, 3, "Jose", "Martinez", 12000, 22);
                addEmployee(empleados, MAX, 4, "Carmen", "Rodriguez", 12000, 83);
                addEmployee(empleados, MAX, 5, "Oscar", "Rodriguez", 50000, 1);
                addEmployee(empleados, MAX, 6, "Mirta", "Rodriguez", 50000, 10);
                addEmployee(empleados, MAX, 7, "Facundo", "Rodriguez", 50000, 1);
                addEmployee(empleados, MAX, 8, "Pancho", "Rodriguez", 12000, 15);
                printf("Hardcodeo con exito!\n");
                system("pause");
                system("cls");
                break;
                
        case 1:
            flag=1;
            lugarLibre=buscarLugarLibre(empleados, MAX);
            if(lugarLibre!= -1)
            {
                printf("Lugar libre = %d\n",lugarLibre);
                getValidString("Ingrese nombre:", "Error, ingrese nuevamente:", name);
                getValidString("Ingrese apellido:", "Error, ingrese nuevamente:", lastName);
                salary=getValidFloat("Ingrese salario:\n","Error, no valido\n", 0, 1000000);
                sector=getValidInt("Ingrese sector:\n","Error, no valido\n", 0, 200);
                addEmployee(empleados, MAX, lugarLibre,  name, lastName, salary, sector);

            }
            else
            {
                printf("No hay lugar libre.\n");
                system("pause");
                system("cls");
            }

            break;
        case 2:
            if(flag==0)
            {

                printf("No hay datos que mostrar\n");
            }
            else
            {
                modifyEmployee(empleados,MAX, lugarLibre);

            }

            system("pause");
            system("cls");
            break;
        case 3:
            if(flag == 0)
            {
                printf("No hay datos que mostrar\n");
            }
            else
            {
               removeEmployee( empleados, MAX, empleados[MAX].id);
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flag == 0)
            {
                printf("No hay datos que mostrar\n");
            }
            else
            {
                sortEmployees(empleados, MAX);
            }

            system("pause");
            system("cls");
            break;
        case 5:
            seguir='n';
            break;
        default :
            printf("Ingresaste mal el dato\n");
            system("pause");
            system("cls");
        }


    }while(seguir == 's');

    return 0;
}
