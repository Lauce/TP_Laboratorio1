#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 20


typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;

} ePersona;




int main()
{

    ePersona unaPersona [C];
    inicializarVec(unaPersona,C);
    int opcion;
    char seguir;
    int flagCase=0;
    int i;
    int indiceLibre;

    do
    {


        printf("\n\t**************************************************************\n");
        printf("\t*                    MENU DE OPCIONES                        *\n");
        printf("\t**************************************************************\n");
        printf("\t*                                                            *\n");
        printf("\t*                                                            *\n");
        printf("\t*           1-CARGAR DATOS PERSONALES                        *\n");
        printf("\t*                                                            *\n");
        printf("\t*           2-BORRAR REGISTRO DE DATOS PERSONALES            *\n");
        printf("\t*                                                            *\n");
        printf("\t*           3-LISTAR POR NOMBRE                              *\n");
        printf("\t*                                                            *\n");
        printf("\t*           4-GRAFICO DE EDADES                              *\n");
        printf("\t*                                                            *\n");
        printf("\t*           5-SALIR                                          *\n");
        printf("\t*                                                            *\n");
        printf("\t**************************************************************\n");
        printf("\t**************************************************************\n");

       /* for(i=0;i<C;i++) //comprobar datos cargados
        {
           printf("%d",unaPersona[i].estado);
        }*/


        printf("\nIngrese una opcion: \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1: //alta

            if(revisarEstado(unaPersona,C, &indiceLibre)==1)
            {
                cargarAlta(unaPersona, C, indiceLibre);
            }
            else
            {
                printf("No hay espacio suficiente para cargar datos, contacte al administrador\n");
            }


            break;

        case 2: //borrar


            borrarDatos(unaPersona,C);


            break;

        case 3: //listar

            ordenarNombre(unaPersona,C);

            break;


        case 4://graficar

            graficoEdad(unaPersona,C);

            break;


        case 5://salir

            printf("Desea continuar?: S / N");
            fflush(stdin);
            scanf("%c",&seguir);
            break;

        default:
            printf("Ingrese una de las opciones del menu \n");
            system("pause");


        }
        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=5);



    return 0;



}
