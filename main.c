#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define REINTENTOS 3

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno=0.00;
    float numeroDos=0.00;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoProducto;
    int resultadoFactorial;
    while(seguir=='s')
    {
        printf("\n El valor de A: %.2f\n",numeroUno);
        printf("\n El valor de B: %.2f\n",numeroDos);
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);
        system("CLS");

        switch(opcion)
        {
            case 1:
                getFloat("Ingrese el valor A: ", "\nError. Valor fuera de rango.\n",REINTENTOS,MAX_INT,MIN_INT,&numeroUno);
                system("CLS");
                break;
            case 2:
                getFloat("Ingrese el valor B: ", "\nError. Valor fuera de rango.\n",REINTENTOS,MAX_INT,MIN_INT,&numeroDos);
                system("CLS");
                break;
            case 3:

                resultadoSuma=sumaDosFloat(numeroUno, numeroDos);
                printf("\n El resultado de A+B es: %.2f\n\n", resultadoSuma);
                system("   pause");
                system("CLS");
                break;
            case 4:
                resultadoResta=restaDosFloat(numeroUno, numeroDos);
                printf("\n El resultado de A-B es: %.2f\n\n", resultadoResta);
                system("   pause");
                system("CLS");
                break;
            case 5:
                if(divisionDosFloat(numeroUno,numeroDos,&resultadoDivision)==0)
                {
                    printf("\n El resultado de A/B es: %.2f\n\n", resultadoDivision);
                    system("   pause");
                    system("CLS");
                }
                else
                {
                    printf("\nNo se puede dividir por cero.\n");
                    system("   pause");
                    system("CLS");
                }
                break;
            case 6:
                resultadoProducto=productoDosFloat(numeroUno, numeroDos);
                printf("\nEl resultado de A*B es: %.2f\n", resultadoProducto);
                system("   pause");
                system("CLS");
                break;
            case 7:
                resultadoFactorial=factorial(numeroUno);
                if (resultadoFactorial!= 0)
                {
                    printf("\nEl resultado del factorial de A es: %d", resultadoFactorial);
                }
                else
                {
                    printf("\n No se puede realizar el factorial de numeros negativos");
                }

                break;
            case 8:
                   realizarTodasLasOperaciones(numeroUno, numeroDos);

                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion invalida, Reingrese.\n ");
                break;
        }



 }
 return 0;
}
