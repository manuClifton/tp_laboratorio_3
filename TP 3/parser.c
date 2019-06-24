#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][30];
    int cant;
    int result = 0;
    Employee* emp;
    if(pFile != NULL && pArrayListEmployee != NULL){
        while(!feof(pFile)){
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            emp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(emp != NULL){
                ll_add(pArrayListEmployee,emp );
                result = 1;
            }
            if(cant < 4){
                if(feof(pFile)){
                    break;
                }else{
                    result = 0;
                    break;
                }
            }
        }
    }

    return result;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int result = 0;
    int cant;

    if(pFile != NULL && pArrayListEmployee != NULL){

        while(!feof(pFile)){

            Employee* emp = employee_new();
            if(emp != NULL){
                cant = fread(emp,sizeof(Employee),1,pFile);

                if(cant == 1){

                    ll_add(pArrayListEmployee,emp);
                    result = 1;
                }
                if(cant < 1){
                    if(feof(pFile)){
                    break;
                }else{

                    result = 0;
                    break;
                    }
                }
            }

        }
    }

    return result;
}
