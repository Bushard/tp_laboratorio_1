#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    int auxDni;
    EPersona personas[20];
    persona_init(personas,20);
    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(personas,20);
                break;
            case 2:
                persona_mostrar(personas,20);
                getValidInt("Ingrese el DNI que quiere borrar.","Error al ingresar el DNI.",&auxDni,0,99999999,2);
                persona_baja(personas,20,auxDni);
                break;
            case 3:
                persona_ordenar(personas,20,1);
                persona_mostrar(personas,20);
                break;
            case 4:
                persona_grafico(personas,20);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
