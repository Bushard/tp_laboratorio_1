#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "lib.h"

/** \brief Toma un valor de tipo float ingresado por el usuario y lo devuelve
 *
 * \param mensaje char* indica al usuario que está ingresando
 * \param mensajeError char* en caso de haber un error posible, con este parametro se notifica
 * \param reintentos int la cantidad de veces que se puede intentar poner un numero valido
 * \param maximo int rango maximo aceptado
 * \param minimo int rango minimo aceptado
 * \param float*dato devolucion del resultado
 * \return int -1 si algo salio mal 0 si esta todo bien
 *
 */
int getFloat(char* mensaje,char* mensajeError,int reintentos,int maximo,int minimo,float*dato)
{
    int retorno =-1;
    float auxiliarLong;
    do
    {
        reintentos--;
        printf("%s ",mensaje);
        scanf("%f", &auxiliarLong);
        if (auxiliarLong <= maximo && auxiliarLong >=minimo)
        {
            *dato = auxiliarLong;
            retorno = 0;
            break;
        }
        else
        {
            printf("\n Numero Fuera de rango.");
        }

    }while(reintentos>=0);

    return retorno;
}



/** \brief Toma dos numeros tipo Float y los suma
 *
 * \param numeroUno float primer valor a sumar
 * \param numeroDos float segundo valor a sumar
 * \return float devuelve el resultado de la suma
 *
 */
float sumaDosFloat(float numeroUno, float numeroDos)
{
    float suma;
    suma= numeroUno+numeroDos;
    return suma;
}

/** \brief Toma el primer numero ingresado y le resta el segundo
 *
 * \param numeroUno float primer valor ingresado
 * \param numeroDos float valor que se resta
 * \return float resultado de la operacion
 *
 */
float restaDosFloat(float numeroUno, float numeroDos)
{
    float resta;
    resta= numeroUno-numeroDos;
    return resta;
}


/** \brief Divide a el primer numero por el segundo
 *
 * \param numeroUno float dividendo
 * \param numeroDos float divisor
 * \param resultado float* devuelve el resultado
 * \return int devuelve un 0 si todo salio bien o -1 si hubo un error
 *
 */
int divisionDosFloat(float numeroUno, float numeroDos, float* resultado)
{
    int retorno =-1;
    if (numeroDos!=0)
    {
        *resultado=numeroUno/numeroDos;
        retorno=0;
    }

    return retorno;
}

/** \brief Multiplica dos numeros tipo float
 *
 * \param numeroUno float primer valor
 * \param numeroDos float segundo valor
 * \return float regresa el resultado
 *
 */
float productoDosFloat(float numeroUno, float numeroDos)
{
    float producto;
    producto=numeroUno*numeroDos;

    return producto;
}

/** \brief realiza el factorial de el valor ingresado
 *
 * \param numeroUno float numero tipo entero
 * \return int devuelve el resultado.
 *
 */
int factorial(float numeroUno)
{
    int resultado=1;
    float factorial;
    if(numeroUno>0)
    {
        for (factorial=numeroUno;factorial>1;factorial--)
        {
            resultado=resultado*((int)factorial);

        }
        return resultado;
    }
    else
    {
        return 0;
    }
}

/** \brief Llama a todas las funciones que realiza la calculadora y las ejecuta al mismo tiempo
 *
 * \param numeroUno float primer valor
 * \param numeroDos float segundo valor
 * \return void
 *
 */
void realizarTodasLasOperaciones(float numeroUno, float numeroDos)
{
    float resultadoSuma;
    float resultadoResta;
    float resultadoProducto;
    float resultadoDivision;
    int resultadoFactorial;
    resultadoSuma=sumaDosFloat(numeroUno, numeroDos);
    printf("\n El resultado de A+B es: %.2f\n\n", resultadoSuma);
    resultadoResta=restaDosFloat(numeroUno, numeroDos);
    printf("\n El resultado de A-B es: %.2f\n\n", resultadoResta);
    if(divisionDosFloat(numeroUno,numeroDos,&resultadoDivision)==0)
    {
        printf("\n El resultado de A/B es: %.2f\n\n", resultadoDivision);

     }
     else
     {
        printf("\nNo se puede dividir por cero.\n");
     }
     resultadoProducto=productoDosFloat(numeroUno, numeroDos);
     printf("\nEl resultado de A*B es: %.2f\n", resultadoProducto);


     resultadoFactorial= factorial(numeroUno);
     if (resultadoFactorial!= 0)
     {
         printf("\nEl resultado del factorial de A es: %d\n\n", resultadoFactorial);

     }
     else
     {
         printf("\n No se puede realizar el factorial de numeros negativos\\n");
     }
        system("   pause");
        system("CLS");

}
