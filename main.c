#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "Xfiles.h"
#include "Get.h"
#define QTY 5




int main()
{
    eMovie movie [QTY];

    initStatus(movie,QTY,0);
    if(cargarDesdeArchivo(movie))//==1
    {
        printf("Se ha creado el archivo\n");
    }
    else
    {
        printf("Los archivos han sido cargados\n");
    }
    //system("pause");

    int option;
    char saveChange = 'S';
    char listMovie[50]={"lista de peliculas.html"};

    //0 es vacio
   // int i;


    while(option!=5)
    {
//        for(i=0; i<QTY; i++)
//        {
//            printf("%d %d status\n",i,movie[i].status);
//        }
        system("cls");
        option=getInt("\n 1- Agregar pelicula\n 2- Borrar pelicula\n 3- Modificar pelicula\n 4- Web pelicula\n 5- Salir\n" );

        switch(option)
        {
        case 1: //agregar pelicula

            addMovie(movie,QTY);
            break;

        case 2://borrar pelicula

            deleteData(movie,QTY);
            break;

        case 3://modificar pelicula
            crearTxt(movie);
            modify(movie,QTY);
            break;

        case 4://generar web

            //validar antes si hay peliculas cargadas

              generarHtml( movie,listMovie);

            break;

        case 5://salir
        printf("\nAntes de salir debera guardar los cambios: S / N ?: ");
				saveChange = tolower(getche());

				if(saveChange == 's')
				{
					if(guardarEnArchivo(movie)==-1)
					{
						printf("\nNo se pudo abrir el archivo\n");
					}
					else
					{
						printf("\nDatos guardados\n");
					}
				}

				saveChange='n';
				break;

            break;
        default:
            printf("Ingrese opcion valida\n");

        }

        fflush( stdin );
        system("pause");
    }


    return 0;
}
