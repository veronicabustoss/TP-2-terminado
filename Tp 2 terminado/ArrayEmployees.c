#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TRUE 0
#define FALSE -1


static int generarNextId() //Genero un unico id por cada empleado que se ingresa
{
    static int id = -1;

    id ++;

    return id;
}

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

int initEmployees(eEmployee* lista, int len)
{
    int i;
    int retorno=FALSE;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = TRUE;
    }

    return retorno;

}

/** \brief Indica que posicion del array esta vacia
 * \param lista* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */

int buscarLugarLibre(eEmployee* lista, int len)
{
    int i;
    int retorno=FALSE;

    if(lista!=NULL)
    {
        for(i=0; i<len ; i ++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;

}

/** \brief Muestra el menu de opciones
 * \return int Return, retorna la opcion que se elige
 */

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones-----\n\n");
    printf("1. Alta\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

/** \brief Muestra un unico empleado
 * \param lista* eEmployee Puntero del array de empleados
 * \param indice int posicion del array a ser mostrada
 */

int mostrarUnEmpleado(eEmployee* lista, int indice)
{
    int retorno=FALSE;
    if(lista!=NULL)
    {
        if(lista[indice].isEmpty == 0)
        {
            printf("%d\t    %s\t    %s\t    %f\t    %d \n",lista[indice].id, lista[indice].name, lista[indice].lastName, lista[indice].salary, lista[indice].sector);
            retorno=TRUE;
        }

    }
    return retorno;
}

/** \brief Muestra una lista de empleados
 * \param eEmployee* lista Puntero del array de empleados
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */

int printEmployees(eEmployee* lista, int len)
{
    int retorno=FALSE;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnEmpleado(lista, i);
                retorno=TRUE;
            }
        }
    }
    return retorno;
}

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer
*posición libre.
 * \param lista* eEmployee Puntero del array de empleados
 * \param len int tamaño del array
 * \param id int Id generado
 * \param name[] char Nombre generado
 * \param lastName[] char Apellido generado
 * \param salary float Salario generado
 * \param sector int  Sector generado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 **/


int addEmployee(eEmployee* lista, int len, int id, char name[],char lastName[],float salary,int sector)
{
    eEmployee auxEmpleado;
    int lugarLibre=buscarLugarLibre(lista, len);
    int retorno=FALSE;

    if(lista!=NULL)
    {
        if(lugarLibre!= FALSE)
        {
            if(name!=NULL && lastName!=NULL  && salary >0 )
            {
                strcpy(auxEmpleado.name, name);
                strcpy(auxEmpleado.lastName, lastName);
                auxEmpleado.salary=salary;
                auxEmpleado.sector=sector;
                auxEmpleado.id=generarNextId();
                auxEmpleado.isEmpty = 0;//ocupado
                lista[lugarLibre]=auxEmpleado; //preguntar luego

                retorno=TRUE;
            }
            else
            {
                printf("nombre apellido o salario esta mal");
            }

        }
        else
        {
            printf("No hay lugar libre\n");
            system("pause");
        }

    }
    system("cls");
    return retorno;

}

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id
 *
 * \param list Employee* Puntero del array de empleados
 * \param len int tamaño del array
 * \param id int Id a ser registrado
 * \return Return Devuelva la posicion que coincide con el Id ingresado, de lo contrario, devuelve -1 como error
 *
 */

int findEmployeeById(eEmployee* lista, int len, int id)
{
    int retorno=FALSE;
    int i;

    if(lista!=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)// Es igual a verdadero
            {
                retorno=i; //me devuelve el lugar que coincide
                break;//Para romper el if y que no siga buscando en el array
            }
        }
    }

    return retorno;
}

/** \brief Da de baja al empleado que se encuentra por Id
 *
 * \param lista eEmployee* Puntero del array de empleados
 * \param len int largo del array
 * \param id int Id a ser registrado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */


int removeEmployee(eEmployee* lista, int len, int id)
{
    int index;
    int i;
    int retorno=FALSE;

    if(lista!=NULL)
    {
        printf("\n Ingrese el id que desea eliminar: ");
        scanf("%d",&id);
        index=findEmployeeById(lista, len, id);

        if(lista[index].isEmpty==0)
        {
            printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");

            mostrarUnEmpleado(lista, index);
        }
        for( i=0; i<len; i++)
        {
            if(index >= 0)
            {
                printf("\n El usuario fue eliminado.\n");
                lista[index].isEmpty = 1;
                break;
            }

            else
            {
                printf("\n No existe ese id.\n");
                break;
            }

            retorno=TRUE;
        }

    }

    return retorno;
}
/** \brief Modifica el empleado que por Id ingresado
 *
 * \param lista* eEmployee Puntero de array de empleados
 * \param len int Largo del array
 * \param id int Id a ser modificado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */

int modifyEmployee(eEmployee*lista,int len,  int id)
{
    int index;
    int cambiar;
    char newName[31];
    char newLastName[31];
    float newSalary;
    int newSector;
    int retorno=FALSE;
    char continuar='n';

    printf("Ingrese el Id. que desea modificar:\n");
    scanf("%d", &id);
    index=findEmployeeById(lista, len, id);

    if(lista!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
                mostrarUnEmpleado(lista, index);
                //llamar funcion que me muesstra los datos de esa posicion
                printf("\n\nSeleccione la opcion que desea modificar:");
                printf("\n1. Nombre\n");
                printf("2. Apellido\n");
                printf("3. Salario\n");
                printf("4. Sector\n");
                scanf("%d", &cambiar);
                switch(cambiar)
                {
                case 1:

                    getValidString("Ingrese nombre:", "Error, ingrese nuevamente:", newName);
                    strcpy(lista[index].name, newName);
                    break;

                case 2:
                    getValidString("Ingrese apellido:", "Error, ingrese nuevamente:", newLastName);
                    strcpy(lista[index].lastName, newLastName);
                    break;
                case 3:
                    newSalary=getValidFloat("Ingrese salario:\n","Error, no valido\n", 0, 1000000);
                    lista[index].salary=newSalary;
                    break;
                case 4:
                    newSector=getValidInt("Ingrese sector:\n","Error, no valido\n", 0, 200);
                    lista[index].sector=newSector;
                    break;
                default :
                    printf("Dato no valido\n");
                }

                printf("Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&continuar);
                system("pause");
                system("cls");
            }while(continuar=='s' || continuar=='S');
        }
        else if(index < 0)
        {
            printf("No existe ese Id. \n");
        }

        retorno=TRUE;     // }

    }

    return retorno;
}

/** \brief Calcula el promedio de los salarios, la suma de los salarios y los empleados que superan el salario promedio
 *
 * \param lista* eEmployee Puntero de array de empleados
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */

int promedioSalary(eEmployee* lista, int len)
{
    float suma=0;
    float promedio;
    int i;
    int retorno=FALSE;
    int contadorEmpleados=0;
    int contadorSuperanElpromedio=0;

    if(lista!=NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                suma = suma + lista[i].salary;
                contadorEmpleados ++;
                promedio= suma / contadorEmpleados;
            }
        }


        for( i=0; i<len ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].salary> promedio)
                {
                    contadorSuperanElpromedio ++;
                }
            }

        }
        printf("La suma es %.3f --- El promedio es %f --- los que superan el salario promedio son %d\n", suma, promedio, contadorSuperanElpromedio);
        retorno=TRUE;
    }

    return retorno;
}

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente ,
 * y muestra promedio y suma de los salarios, y empleados que superan el salario promedio
 * \param lista eEmployee* Puntero del array de empleados
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 *
 */


int sortEmployees(eEmployee* lista, int len)
{
    int retorno=FALSE;
    eEmployee auxiliarEmployees;
    int i, j ;
    int elegir;
    printEmployees(lista, len);
    //int flag=0;
    if(lista!= NULL)
    {
        //flag=1;
        printf("\n1.Ordenar alfabeticamente  de manera ascendente");
        printf("\n2.Ordenar alfabeticamente  de manera descendente");
        printf("\n3.Total y promedio de los salarios, y cuantos empleados superan el salario promedio. ");
        printf("\nElija la opcion :\n");
        fflush(stdin);
        scanf("%d", &elegir);

        switch(elegir)
        {

        case 1://Ascendente
            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {

                    if(strcmp(lista[j].lastName,lista[i].lastName)<0)
                    {
                        auxiliarEmployees = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarEmployees;
                    }
                    else if(strcmp(lista[j].lastName,lista[i].lastName)==0 && lista[j].sector<lista[i].sector)
                    {
                        auxiliarEmployees = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarEmployees;
                    }
                }
            }
            printf("\nOpcion completada con exito.\n");
            break;

        case 2://Descendente

            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName)<0)
                    {
                        auxiliarEmployees = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarEmployees;
                    }
                    else if(strcmp(lista[i].lastName,lista[j].lastName)==0 && lista[j].sector>lista[i].sector)
                    {
                        auxiliarEmployees = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarEmployees;
                    }
                }
            }
            printf("\nOpcion completada con exito.\n");
            break;
        case 3:
            promedioSalary(lista, len);
            printf("\nOpcion completada con exito.\n");
            break;
        default:
            printf("\nIngresaste mal los datos\n");
            break;
        }

        retorno=TRUE;
    }

    return retorno;

}

