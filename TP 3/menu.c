#include "menu.h"


/** \brief Menu principal del programa.
 * \return Retorna entero seleccionado por el usuario.
 */
int menu(void)
{
    int option;

        system("cls");
        printf("***MENU***\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("10. Salir\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&option);

    return option;
}

/** \brief SubMenu de la opcion de ordenamiento.
 * \return Retorna entero seleccionado por el usuario.
 */
int orderMenu(void){
    int option;

    system("cls");

        printf("***ORDENAR***\n\n");
        printf("1. Por ID \n");
        printf("2. Alfabeticamente por nombre \n");
        printf("3. Por cantidad de horas trabajadas \n");
        printf("4. Por Sueldo \n");

        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&option);

    return option;
}
