#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int persona_init(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int persona_alta(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    char auxNombre[50];
    long int auxEdad;
    long int auxDni;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nIngrese el nombre:  ","\nNombre invalido.","El maximo es 50",auxNombre,50,2))
            {
                if(!getValidInt("Ingrese edad: ", "Error al ingresar edad", &auxEdad, 0, 15000, 2))
                {
                    if(!getValidInt("Ingrese DNI (sin puntos)","Error al ingresar DNI", &auxDni,0,99999999,2))
                      //if(!getStringNumeros("Ingrese el DNI: ", auxDni))
                     {
                        retorno = 0;
                        strcpy(array[i].nombre,auxNombre);
                        array[i].dni=auxDni;
                        array[i].edad=auxEdad;
                        array[i].isEmpty = 0;
                     }
                     else
                     {
                        retorno=-3;
                     }
                }
                else
                {
                    retorno = -2;
                }

            }

            else
            {
                retorno= -1;
            }
        }

    }
    return retorno;
}

int buscarLugarLibre(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_baja(EPersona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].dni==dni)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int persona_ordenar(EPersona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    EPersona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


int persona_mostrar(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf(" Nombre: %s | Edad: %ld | DNI: %ld | \n",array[i].nombre, array[i].edad, array[i].dni);
        }
    }
    return retorno;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    clearStdin();
    scanf ("%[^\n]s", input);
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}


int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}



/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[], long int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[1024];
    long int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atol(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

void clearStdin(void)
{
    setbuf(stdin,NULL);
}


void persona_grafico(EPersona* array, int limite)
{
    int i;
    int edadMenorDe18=0;
    int edadEntre19y35=0;
    int edadMayorDe35=0;
    int edadConMasGente=0;
    for (i=0; i<limite; i++)
    {
        if(array[i].edad<18 && array[i].isEmpty==0)
        {
            edadMenorDe18++;
        }
        else if(array[i].edad>=19 && array[i].edad<=35 && array[i].isEmpty==0)
        {
            edadEntre19y35++;
        }
        else if(array[i].edad>35 && array[i].isEmpty==0)
        {
            edadMayorDe35++;
        }

        if(edadMenorDe18>=edadEntre19y35 && edadMenorDe18>=edadMayorDe35)
        {
            edadConMasGente=edadMenorDe18;
        }
        else if(edadEntre19y35>=edadMenorDe18 && edadEntre19y35>=edadMayorDe35)
        {
            edadConMasGente=edadEntre19y35;
        }
        else
        {
            edadConMasGente=edadMayorDe35;
        }
    }
    for(i=edadConMasGente; i>0; i--)
    {
        printf("\t  %02d  |",i);

        if( i<= edadMenorDe18)
        {
            printf("\t    *");
        }
        else
        {
            printf("\t    ");
        }

        if(i<= edadEntre19y35)
        {
            printf("\t\t     *");

        }
        else
        {
             printf("\t\t      ");
        }

        if(i<= edadMayorDe35)
        {
           printf("\t\t\t    *");
        }
        else
        {
            printf("\t\t\t    ");
        }
        printf("\n");


    }
        printf("\t\t  -----------------------------------------------\n");
        printf("\t\t  Menores de 18\t    Entre 19 y 35    Mayores de 35");
}



















