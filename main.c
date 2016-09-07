#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir = 's';
    int opcion;
    float numero1;
    float numero2;
    float resultado;
    float flag1 = 0;
    float flag2 = 0;

    do
    {
        system("cls");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n\n        1   Ingresar 1er operando (%.2f)\n",numero1);
        printf("        2   Ingresar 2do operando (%.2f)\n",numero2);
        printf("        3   Sumar (A+B)\n");
        printf("        4   Restar (A-B)\n");
        printf("        5   Division (A/B)\n");
        printf("        6   Multiplicacion (A*B)\n");
        printf("        7   Factorial (%0.f)\n",numero1);
        printf("        8   Calcular todas las operaciones\n");
        printf("        9   Salir\n\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        printf("\n Elija una opcion: \n");
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            printf("Ingrese un numero: \n");
            scanf("%f",&numero1);

            flag1 = 1;


            break;
        case 2:
            printf("Ingrese otro numero: \n");

            scanf("%f",&numero2);

            flag2 = 1;

            break;

        case 3:
            if(flag1==1 && flag2==1)
            {
                resultado = sumarNumeros(numero1, numero2);
                printf("la suma es %.2f\n",resultado);

            }
            else
            {
                printf("Error, debe ingresar otro numero para operar\n");
            }

            break;

        case 4:
            if(flag1==1 && flag2==1)
            {
                resultado = restarNumeros(numero1, numero2);
                printf("La resta es %.2f\n",resultado);
            }
            else
            {
                printf("Error, debe ingresar numeros para operar\n");
            }

            break;

        case 5:



            if(flag1==1 && flag2==1)
            {
                resultado = dividirNumeros(numero1,numero2);
                printf("La division es %.2f\n",resultado);
            }
            else
            {
                printf("Error, ingrese otro numero para realizar la operacion\n");
            }

            break;


        case 6:
            if(flag1==1 && flag2==1)
            {
                resultado = multiplicarNumeros(numero1, numero2);
                printf("El producto es %.2f\n",resultado);
            }
            else
            {
                printf("ingrese el numero en la opcion 1\n");
            }
            break;

        case 7:
            if(flag1==1)
            {
                resultado = factorial(numero1);
                printf("El factorial de la parte entera del primer operando (%.2f) es %.0f\n", numero1, resultado);
            }
            else
            {
                printf("Ingrese el numero en la opcion 1 del menu\n");
            }
            break;


        case 8:
            if(flag1==1 && flag2==1)
            {
                resultado = sumarNumeros(numero1, numero2);
                printf("la suma es %.2f\n",resultado);

                resultado= restarNumeros(numero1, numero2);
                printf("La resta es %.2f\n",resultado);

                resultado = dividirNumeros(numero1,numero2);


                if (numero2 == 0)
                {
                    printf("Error, no se puede dividir por cero\n");

                }
                else
                {
                    printf("La division es %.2f\n",resultado);
                }


                resultado = multiplicarNumeros(numero1, numero2);
                printf("El producto es %.2f\n",resultado);

                resultado = factorial(numero1);
                printf("El factorial de la parte entera del primer operando (%.2f) es %.0f\n",numero1, resultado);


            }
            else
            {
                printf("Ingrese el segundo numero para realizar todas las operaraciones\n");
            }
            break;


        case 9:
            printf("desear continuar? Ingrese S o N\n");
            fflush(stdin);

            scanf("%c",&seguir);

            break;


        default: //si se ingresa cualguier letra o numero diferente al menu, imprime el sigte texto.
            printf("Ingrese una de las opciones del menu \n");


        }

        fflush( stdin );
        system("pause");

    }
    while (seguir =='s');





    return 0;


}









