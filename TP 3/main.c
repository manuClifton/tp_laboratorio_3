#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menu(void);
int orderMenu(void);

int main()
{

//    Employee* employee= (Employee*) malloc(sizeof(Employee*));
/*
    //harcode empleados
    Employee* emp1= employee_newParametros("1234","juan","2340","25000");
    Employee* emp2= employee_newParametros("2222","jualia","150","15000");
    Employee* emp3= employee_newParametros("1111","juana","200","35000");
    Employee* emp4= employee_newParametros("555","sofia","350","40000");
    //mostrar cantidad de elementos del linked list
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp1)==0)
    {
    printf("Se agrego bien\n");
    }
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp2)==0)
    {
    printf("Se agrego bien\n");
    }
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

    if(ll_add(listaEmpleados, emp3)==0)
    {
    printf("Se agrego bien\n");
    }
    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));


   // mostrarEmpleado((Employee*) ll_get(listaEmpleados,1));
   // mostrarEmpleado((Employee*) ll_pop(listaEmpleados,1));

    //printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));

   if(ll_push(listaEmpleados,1,emp4)==0)
    {
    printf("Se agrego bien\n");
    }

    printf("Cantidad elementos: %d\n", ll_len(listaEmpleados));


    for(int i=0;i<ll_len(listaEmpleados);i++)
    {
        mostrarEmpleado((Employee*) ll_get(listaEmpleados,i));
    }

    printf("Ordeno la lista por sueldo\n\n");
    ll_sort(listaEmpleados,ordenarXsueldo,1);
     for(int i=0;i<ll_len(listaEmpleados);i++)
    {
        mostrarEmpleado((Employee*) ll_get(listaEmpleados,i));
    }

    printf("Ordeno la lista por horas\n\n");
    ll_sort(listaEmpleados,ordenarXHoras,1);
     for(int i=0;i<ll_len(listaEmpleados);i++)
    {
        mostrarEmpleado((Employee*) ll_get(listaEmpleados,i));
    }*/


    int devolution;
    int exit = 0;

    int flagLoadLinkedList=0;
    int flagBuffer=0;
    LinkedList* EmployeeList = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                if(flagLoadLinkedList == 0){
                    devolution=controller_loadFromText("data.csv",EmployeeList);
                    if(devolution==1)
                    {
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");
                        flagLoadLinkedList=1;
                    }
                    else if (devolution==0)
                    {
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
                }else{
                    printf("\n   *********************\n");
                    printf("   * Ya estan cargados *\n");
                    printf("   *********************\n\n");
                }

                system("pause");
                    break;

            case 2:
                if(flagLoadLinkedList == 0){
                    devolution=controller_loadFromBinary("data.bin",EmployeeList);
                    if(devolution==1)
                    {
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");

                        flagLoadLinkedList=1;
                    }
                    else if (devolution==0)
                    {
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
                }else{
                    printf("\n   *********************\n");
                    printf("   * Ya estan cargados *\n");
                    printf("   *********************\n\n");
                }

                system("pause");
                    break;

            case 3:
                devolution=controller_addEmployee(EmployeeList);
                    if(devolution==1)
                    {
                        printf("\n   *************************************\n");
                        printf("   * Cargo nuevo empleado Exitosamente *\n");
                        printf("   *************************************\n\n");

                        flagBuffer=1;
                    }
                    else if(devolution==0)
                    {
                        printf("\n   ***********************\n");
                        printf("   * Se cancelo la carga *\n");
                        printf("   ***********************\n\n");
                    }
                    else
                    {
                        printf("\n   ******************************\n");
                        printf("   * Error al cargar el nuevo empleado *\n");
                        printf("   ******************************\n\n");
                    }
                system("pause");
                    break;

            case 4:
                system("cls");
                devolution=controller_editEmployee(EmployeeList);
                    if(devolution==2){
                        printf("\n   *****************************\n");
                        printf("   * No se encontro ninguna ID *\n");
                        printf("   *****************************\n\n");
                    }
                    else if(devolution==1){
                        printf("\n   *******************************\n");
                        printf("   * Se edito de manera correcta *\n");
                        printf("   *******************************\n\n");
                    }
                    else if(devolution==-1){
                        printf("\n   ***************************************\n");
                        printf("   * No se pudo realizar por algun error *\n");
                        printf("   ***************************************\n\n");
                    }

                system("pause");
                    break;

            case 5:
                devolution=controller_removeEmployee(EmployeeList);
                    if(devolution==-1){
                        printf("\n   *********************\n");
                        printf("   * Error al eliminar *\n");
                        printf("   *********************\n\n");
                    }
                    else if(devolution==0){
                        printf("\n   **********************\n");
                        printf("   * La baja se cancelo *\n");
                        printf("   **********************\n\n");
                    }
                    else if(devolution==1){
                        printf("\n   ************************************\n");
                        printf("   * La baja se realizo correctamente *\n");
                        printf("   ************************************\n\n");
                    }
                    else if(devolution==2){
                        printf("\n   ********************************************\n");
                        printf("   * No se encontro ningun usuario con esa ID *\n");
                        printf("   ********************************************\n\n");
                    }

                system("pause");
                    break;

            case 6:
                if(!flagBuffer &&  !flagLoadLinkedList  ){
                    printf("\n   ******************************\n");
                    printf("   * No hay ningun dato cargado *\n");
                    printf("   ******************************\n\n");
                }
                else
                {
                    system("cls");
                    showEmployees(EmployeeList);
                    printf("\n\n");
                }
                system("pause");
                break;
            case 7:
                if(!flagBuffer && !flagLoadLinkedList){
                        printf("\n   ******************************\n");
                        printf("   * No hay ningun dato cargado *\n");
                        printf("   ******************************\n\n");
                }else{
                    controller_sortEmployee(EmployeeList);
                }

                system("pause");
                break;
            case 8:
                       devolution = controller_saveAsText("./data.csv",EmployeeList);
                       if(devolution == 1){
                            printf("\n   ********************************\n");
                            printf("   * Se Guardo de manera correcta *\n");
                            printf("   ********************************\n\n");
                            flagLoadLinkedList=0;
                            flagBuffer=0;
                            ll_deleteLinkedList(EmployeeList);
                            EmployeeList=ll_newLinkedList();
                       }else{
                            printf("\n   *******************************\n");
                            printf("   * Ocurrio un Error al Guardar *\n");
                            printf("   *******************************\n\n");
                       }
                       system("pause");
                        break;
            case 9:
                       devolution = controller_saveAsBinary("./data.bin",EmployeeList);
                       if(devolution == 1){
                            printf("\n   ********************************\n");
                            printf("   * Se Guardo de manera correcta *\n");
                            printf("   ********************************\n\n");
                            flagLoadLinkedList=0;
                            flagBuffer=0;
                            ll_deleteLinkedList(EmployeeList);
                            EmployeeList=ll_newLinkedList();
                       }else{
                            printf("\n   *******************************\n");
                            printf("   * Ocurrio un Error al Guardar *\n");
                            printf("   *******************************\n\n");
                       }
                       system("pause");
                        break;
            case 10:
                exit=1;
                break;
            default:

                printf("\n   ******************************\n");
                printf("   * Opcion invalida. Reingrese *\n");
                printf("   ******************************\n\n");

                system("pause");
                break;
        }
    }while(exit== 0);

    return 0;
}




