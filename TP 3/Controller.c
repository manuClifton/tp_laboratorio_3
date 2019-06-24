#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int result=0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
    }
    fclose(pFile);

    return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int result=0;

        if(path != NULL && pArrayListEmployee != NULL){

            pFile= fopen(path,"rb");

            if(pFile==NULL)
            {
                result=0;
            }
            else{
                result = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            }
        }

         fclose(pFile);

    return result;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int result=-1;
    char auxId[50];
    char auxHoras[50];
    char auxSalario[50];
    char auxNombre[130];
    char confirm;


    system("cls");
    printf("---Carga de empleado nuevo---\n\n");

    printf("Ingrese ID: ");
    fflush(stdin);
    gets(auxId);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxNombre);
    strlwr(auxNombre);
    auxNombre[0] = toupper(auxNombre[0]);


    printf("Ingrese horas trabajadas: ");
    fflush(stdin);
    gets(auxHoras);

    printf("Ingrese salario: ");
    fflush(stdin);
    gets(auxSalario);

    printf("\nConfirma la carga? s/n: ");
    fflush(stdin);
    confirm=getchar();
    confirm=tolower(confirm);
        if(confirm=='s')
        {
            Employee* empNew=employee_newParametros(auxId,auxNombre,auxHoras,auxSalario);
            ll_add(pArrayListEmployee,empNew);
            result=1;
        }
        else
        {
            result=0;
        }

    return result;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int result=-1;
    int id;
    char name[128];
    int hrs;
    int salary;

    int index=-1;
    char confirm;
    Employee* auxEmployee=employee_new();

    showEmployees(pArrayListEmployee);
    printf("Ingrese ID: ");
    scanf("%d", &id);

        if(auxEmployee==NULL)
        {
            result=-1;
        }
        else
        {
            if(ll_len(pArrayListEmployee)==0){
                result=-1;
            }
            else
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    auxEmployee= ((Employee*) ll_get(pArrayListEmployee,i));
                    if(auxEmployee->id==id)
                    {
                        printf("\nEmpleado seleccionado: \n");
                        printf(" ID     Nombre     Horas    Sueldo\n");
                        printf("------------------------------------\n");
                        index=i;
                        showEmployee(auxEmployee);
                        break;
                    }
                }
            }
        }



    if(index!=-1)
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese horas trabajadas: ");
        scanf("%d",&hrs);

        printf("Ingrese salario: ");
        scanf("%d",&salary);

        printf("\n");

        printf("\nConfirma editar el usuario? s/n: ");
        fflush(stdin);
        confirm= getchar();
        confirm=tolower(confirm);

            if(confirm=='s')
            {
                strcpy(auxEmployee->nombre,name);
                auxEmployee->horasTrabajadas=hrs;
                auxEmployee->sueldo=salary;

                ll_remove(pArrayListEmployee,index);
                ll_push(pArrayListEmployee,index,auxEmployee);
                result=1;
            }
            else{
                result=-1;
            }
    }
    else{
        result=2;
    }


    return result;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int returnOfFuntion=-1;
    int id;
    int index=-1;

    char confirm;


    Employee* auxEmployee=employee_new();

    showEmployees(pArrayListEmployee);
    printf("Ingrese id: ");
    scanf("%d",&id);

    for(int i=1;i<ll_len(pArrayListEmployee);i++)
    {
        auxEmployee= ((Employee*) ll_get(pArrayListEmployee,i));

        if(auxEmployee->id==id)
        {
            index=i;
            break;
        }

    }

    if(index!=-1)
    {
    showEmployee(auxEmployee);
    printf("\nConfirma eliminar el usuario? s/n: ");
    fflush(stdin);
    confirm= getchar();
    confirm=tolower(confirm);

        if(confirm=='s')
        {
            ll_remove(pArrayListEmployee,index);
            returnOfFuntion=1;
        }
        else
        {
            returnOfFuntion=0;
        }
    }
    else
    {
        returnOfFuntion=2;
    }
    return returnOfFuntion;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int result=0;

        if(pArrayListEmployee != NULL){
            system("cls");
            showEmployees(pArrayListEmployee);
            result=1;
        }

    return result;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int order;


    if(pArrayListEmployee != NULL){

       switch(orderMenu())
    {
    case 1:

        printf("Ingrese por orden Descendente (0), o Ascendente (1): ");
        scanf("%d", &order);
        printf("Espere un momento, esto podria tardar un poco...");
        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderID,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        else
        {
            ll_sort(pArrayListEmployee,orderID,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;


    case 2:
        printf("Ingrese por orden Descendente (0), o Ascendente (1): ");
        scanf("%d", &order);
        printf("Espere un momento, esto podria tardar un poco...");
        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderName,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        else
        {
            ll_sort(pArrayListEmployee,orderName,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;

    case 3:
        printf("Ingrese por orden Descendente (0), o Ascendente (1): ");
        scanf("%d", &order);
        printf("Espere un momento, esto podria tardar un poco...");
        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderHours,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        else
        {
            ll_sort(pArrayListEmployee,orderHours,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;

    case 4:
        printf("Ingrese por orden Descendente (0), o Ascendente (1): ");
        scanf("%d", &order);
        printf("Espere un momento, esto podria tardar un poco...");
        if(order==1)
        {
            ll_sort(pArrayListEmployee,orderSalary,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;

        }
        else
        {
            ll_sort(pArrayListEmployee,orderSalary,order);
            controller_ListEmployee(pArrayListEmployee);
            order=1;
        }
        break;
    }
    }

    return order;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    Employee* auxEmp;
    int size=ll_len(pArrayListEmployee);
    int result=-1;

    int id;
    int hours;
    int salary;

    char name[130];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmp,&id);
                    employee_getNombre(auxEmp,name);
                    employee_getHorasTrabajadas(auxEmp,&hours);
                    employee_getSueldo(auxEmp,&salary);
                    fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(pFile);
                result=1;
            }
            else{
                result=0;
            }
        }
    }

    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int size = ll_len(pArrayListEmployee);
    int result = -1;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"wb");
            if(pFile!=NULL)
            {
                for(int i=0; i<size;i++)
                {
                    auxEmp=ll_get(pArrayListEmployee,i);
                    if(auxEmp!=NULL)
                    {
                        fwrite(auxEmp,sizeof(Employee),1,pFile);
                    }
                }
            result=1;
            fclose(pFile);
            }
            else{
            result=0;
            }
        }
    }
    else{
        result=0;
    }

    return result;
}

