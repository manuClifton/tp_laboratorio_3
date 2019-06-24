#include "Employee.h"
#include "stdlib.h"
#include <string.h>

/** \brief Valida el valor de la ID y lo carga en estructura.
 *
 * \param recibe puntero de estructura Employee.
 * \param Toma el valor ID ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_setId(Employee* this,int id)
{
    int result=0;
    if(this!=NULL && id >0)
    {
        this->id=id;
        result=1;
    }

    return result;
}


/** \brief Toma valor de ID de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param puntero a entero y que guardara el valor del ID.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_getId(Employee* this,int* id)
{
    int result=0;

    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        result = 1;
    }


    return result;
}

/** \brief Valida la cadena y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Recibe cadena de caracteres.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int result=0;
        if(this!=NULL && strlen(nombre)>2 && nombre!=NULL)
        {
            strcpy(this->nombre,nombre);
            result=1;
        }

    return result;
}

/** \brief Toma la cadena de una estructura Employee.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Puntero a char donde guardara la cadena de la estructura.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int result=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        result=1;
    }

    return result;
}

/** \brief Valida el valor de las horas y lo carga en estructura.
 *
 * \param Recibe puntero de estructura Employee.
 * \param Toma el valor Horas ingresado por el usuario.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int result=0;

        if(this!=NULL && horasTrabajadas>=0)
        {
            this->horasTrabajadas=horasTrabajadas;
            result = 1;
        }

    return result;
}

/** \brief Toma valor de Horas de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor de variable HorasTrabajadas.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int result=0;

    if(this!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas=this->horasTrabajadas;
        result = 1;
    }


    return result;
}

/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_setSueldo(Employee* this,int sueldo)
{
   int result=0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        result = 1;
    }

    return result;
}

/** \brief Toma valor de Sueldo de una estructura Employee.
 *
 * \param recibe puntero de estructura Employee.
 * \param Puntero a entero y que guardara el valor del sueldo.
 * \return Retorna 0 (cero) o 1 (uno).
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
   int result=0;

    if(this!=NULL && sueldo>0)
    {
        *sueldo=this->sueldo;
        result = 1;
    }


    return result;
}

/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */
Employee* employee_new()
{
    Employee* this= (Employee*) malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->nombre,"");
        this->horasTrabajadas=0;
        this->sueldo=0;
    }

    return this;
}


/** \brief Crea una nueva estructura de tipo Employee* y se cargan los campos con los parametros recibidos
 *
 * \param  Recibe cadena con los datos de la Id
 * \param  Recibe cadena de caracteres con los datos de Nombre
 * \param  Recibe cadena con el valor de las Horas trabajadas
 * \param  Recibe cadena con el valor del Sueldo
 *
 * \return Retorna la estructura Employee* con los datos cargados en sus campos
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
//Viene en char para poder utilizar desde el buffer, o sea, la lectura desde el archivo
{

    Employee* this;
        if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
        {
            this= employee_new();
            if(this!=NULL)
            {
                if(!employee_setId(this,atoi(idStr)) || !employee_setNombre(this,nombreStr) || !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) || !employee_setSueldo(this,atoi(sueldoStr)))
                {
                    free(this);
                    this=NULL;
                }
            }
        }

    return this;
}


/** \brief Muestra en pantalla, los datos de la linkedList
 *
 * \param Recibe LinkedList*
 */
void showEmployees(LinkedList* pArrayLinkedList)
{
    printf(" ID     Nombre     Horas    Sueldo\n");
    printf("------------------------------------\n");
        for(int i=0;i<ll_len(pArrayLinkedList);i++)
        {
            showEmployee((Employee*) ll_get(pArrayLinkedList,i));
        }
        printf("\n\n");
}

/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */
void showEmployee(Employee* emp)
{
    if(emp!=NULL)
    printf("%4d  %10s  %5d      %5d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}



/** \brief Ordena por Id
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderID(void* emp1, void* emp2)
{
    int result=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->id > p2->id)
            result = 1;
        else if(p1->id < p2->id)
            result=-1;
        else
            result=0;
    }
    return result;
}

/** \brief Ordena por Sueldo
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderSalary(void* emp1 , void* emp2)
{
    int result=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
        {
            result = 1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            result=-1;
        }
        else
        {
            result=0;
        }
    }
    return result;
}

/** \brief Ordena por Horas trabajadas
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderHours(void* emp1 , void* emp2)
{
    int result=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas)
        {
            result = 1;
        }
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
        {
            result=-1;
        }
        else
        {
            result=0;
        }
    }
    return result;
}

/** \brief Ordena por Nombre.
 *
 * \param Recibe primera estructura Employee.
 * \param Recibe segunda estructura Employee.
 * \return devuelve el tipo de ordenamiento.
 */
int orderName(void* emp1, void* emp2)
{
    int result=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(strcmp(p1->nombre,p2->nombre)>0)
            result = 1;
        else if(strcmp(p1->nombre,p2->nombre)<0)
            result=-1;
        else
            result=0;
    }
    return result;
}
