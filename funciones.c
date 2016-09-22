#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 20

/** \brief inicializa con un numero ilogico el vector
* \param asigna valor ilogico al campo estado (bandera) recorriendo el vector con un for
* \return no retorna datos
*/


void inicializarVec(ePersona vector[], int length)
{
    int i;

    for(i=0; i<length; i++)
    {
        vector[i].estado=-1;
    }

}


/** \brief revisa el valor en cada posicion del vector buscando aquella posicion que sea -1
* \param se asigna al espacio utilizable al indice del vector para poder utilizarlo en la carga de datos.
* \return retorna 1 si hay espacio
*/
int revisarEstado(ePersona vector[],int length, int *indice)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(vector[i].estado==-1)
        {
            *indice=i;
            return 1;
        }
    }
    return 0;


}


/** \brief Revisa si el dato cargado en el campo dni ya ha sido cargado
* \param recorre con un for buscando la igualdad del dato ingresado
* \return retorna 1 si el dni se repite, y 0 si no.
*/

int revisarDni(ePersona vector[],int length, int parametro, int *indice)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(vector[i].dni==parametro&&vector[i].estado==1)
        {
            *indice=i;
            printf("Error!!! Ese DNI ya ha sido registrado\n");
            return 1;
        }
    }
    return 0;

}

/** \brief carga los datos en todos los campos del vector estructura,
* \param se pide el ingreso de los datos por instancias mediante banderas, si uno de los datos es erroneo, se vuelve a pedir cargarlos correctamente.
* \return no retorna datos
*/


void cargarAlta(ePersona* vector, int length, int indiceLibre)
{
    system("pause");
    //int i;
    int indice;
    char aux [15];
    int flagDni = 0;
    int flagEdad = 0;
    int flagNombre = 0;
    int edad;
    int dni;
    char nombre[20];

    fflush(stdin);
    printf("Ingrese DNI: \n");
    gets(aux);
    fflush(stdin);

    if(!esUnNumero(aux))
    {
        printf("Ingrese dni numerico\n");
    }
    if(esUnNumero(aux) == 1 && revisarDni(vector,length,atoi(aux),&indice)== 0)
    {
        flagDni = 1;
        dni = atoi(aux);
        if(flagDni == 1)
        {
            fflush(stdin);
            printf("Ingrese NOMBRE: \n");
            fflush(stdin);
            gets(aux);

            if(soloLetras(aux))
            {
                flagNombre=1;
                strcpy(nombre,aux);
            }
            else
            {
                printf("Ingrese NOMBRE valido: \n");
            }
        }
        else
        {
            printf("Ingrese DNI valido: \n");
        }

        if(flagDni == 1&&flagNombre == 1)
        {
            printf("Ingrese EDAD: \n");
            gets(aux);
            if(esUnNumero(aux))
            {
                flagEdad = 1;
                edad = atoi(aux);
            }
            else
            {
                printf("Ingrese EDAD valida: \n\n");
            }
        }

        if(flagDni == 1 && flagEdad == 1 && flagNombre == 1)
        {
            vector[indiceLibre].dni = dni;
            vector[indiceLibre].edad = edad;
            strcpy(vector[indiceLibre].nombre,nombre);
            vector[indiceLibre].estado = 0;
        }

    }

}

/** \brief Borra datos asignado valor ilogico a la variable estado, sin borrar todos los datos cargados.
* \param recorre con un for buscando la igualdad del dato ingresado, al encontrarlo le asigna valor -1
* \return no retorna datos.
*/


void borrarDatos(ePersona vector[],int length)
{
    int i;
    char aux[255];
    printf("Ingrese DNI a borrar\n");
    gets(aux);

    if(soloLetras(aux))
    {
        for(i=0; i<length; i++)
        {
            if(vector[i].estado==0)
            {
                if(vector[i].dni==atoi(aux))
                {
                    vector[i].dni=-1;
                    printf("Los datos del DNI %s han sido borrados\n",aux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("El numero de DNI %s es incorrecto o no se encuentra registrado\n",aux);
    }
}

/** \brief valida que se hayan ingresado solo letras.
* \param recorre la cadena de caracteres recibida comparando que cada caracter corresponda a una letra.
* \return retorna 0 si se ingreso un caracter invalido y 1 si solo fueron letras.
*/


int soloLetras (char string[])
{
    int i;
    int totalChar;


    totalChar=strlen(string);
    for(i=0; i<totalChar; i++)
    {
        if(!(isalpha(string[i])))
        {
            return 0;
        }
    }
    return 1;
}


/** \brief valida que se hayan ingresado solo numeros
* \param mientras no encuentre un \0 - ultima posicion de la cadena- compara si los datos ingresados estan dentro del rango validado.
* \param avanza cada posicion del vector mediante un contador.
* \return retorna 0 si se ingreso un caracter invalido y 1 si solo fueron letras.
*/

int esUnNumero(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/** \brief ordena el array de estructura por nombre.
* \param recorre el vector comparando y ordenando alfabeticamente el campo nombre.
* \return no retorna datos, imprime los campos ordenados segun el criterio mediante la funcion printf.
*/

void ordenarNombre(ePersona vector[], int length)
{
    ePersona aux;
    int i;
    int j;

    for(i=0; i<length-1; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(vector[j].estado!=1)
            {
                if(strcmp(vector[i].nombre,vector[j].nombre)>0)
                {
                    aux=vector[i];
                    vector[i]=vector[j];
                    vector[j]=aux;
                }//cierre if comp
            }//cierre if estado

        }//cierre for j
    }//cierre for i


    for(i=0; i<length; i++)
    {
        if(vector[i].estado==0)
            printf("%d-------%s-------%d\n",vector[i].dni, vector[i].nombre,vector[i].edad);
    }

}//cierre void ordenar


/** \brief imprime en un grafico vertical un asterisco segun el grupo de edad-
 *
 * \param recorre el vector, establece cual es el valor maximo y clasifica en distintos grupos segun rango de edad
 *
 * \return no retorna datos, imprime el grafico.
 *
 */
 void graficoEdad(ePersona vector[],int length)
{
    int i;
    int grupo;
    int grupo1=0;
    int grupo2=0;
    int grupo3=0;
    int auxEdad;
    int maximo = 0;
    int flag;

    for(i=0;i<length;i++)
    {
        if(vector[i].estado==0)
        {
           auxEdad=vector[i].edad;
           if(auxEdad<19)
           {
               grupo1++;
           }
           else if(auxEdad>19 && auxEdad <=35)
           {
               grupo2++;
           }
           else
            {

                grupo3++;
            }

        }
    }

    for(i=0;i<3;i++)
    {
        if(grupo1 > maximo || i==0)
        {
            maximo = grupo1;
        }


        if(grupo2 > maximo)
        {
            maximo = grupo2;
        }
        if(grupo3 > maximo)
        {
            maximo = grupo3;
        }
    }

    for(i = maximo; i>0; i--)
    {
        int flagUno = 0;
        int flagDos = 0;
        int flagTres = 0;
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);
        if(i<= grupo1)
        {
            printf("*");
        }
        else
        {
            printf("\t");
        }
        if(i<= grupo2)
        {
            printf("\t*");
        }
        else
        {
            printf("\t");
        }
        if(i<= grupo3)
        {
            printf("\t*");
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }
        printf("-------------------\n");
        printf("\n|<18\t19-35\t>35");
        printf("\n   %d\t%d\t%d\n", grupo1, grupo2, grupo3);

        return 0;


}
