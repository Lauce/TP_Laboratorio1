#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "Get.h"
#include "Xfiles.h"
#define QTY 5


/** \brief Inicializa el vector con determinado valor pasado por parametro
 *
 * \param eMovie movie. Estructura
 * \param int length. Tamaño de la estructura
 * \param int value. Valor con el que se inicializa el array
 * \return -1 si da error, 0 si fue exitosa.
 *
 */

int initStatus(eMovie* movie,int length,int value)
{
    int i;
    int retorno=-1;
    if(movie!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            movie[i].status=value;
            retorno = 0;
        }
    }
    return retorno;


}

/** \brief Muestra por pantalla titulo, nacionalidad y agno de la pelicula.

 *
 * \param eMovie movie. Estructura de datos
 * \param
 * \return void
 *
 */

void mostrarPelicula(eMovie* movie)
{
    printf("\nTitulo: %s\n", movie->title);
	printf("Nacionalidad: %s\n", movie->description);
    printf("A#o: %d\n", movie->rating);
}

/** \brief Busca lugar libre en el array
 *
 * \param eMovie movie. Estructura de datos
 * \param int length. Tamaño de la estructura
 * \return int retorna -1 si no encuentra lugar libre y i, el indice libre.
 *
 */

int searchFreePlace(eMovie* movie,int length)
{
    int i;
    int retorno=-1;

    if(movie!=NULL && length >0)
    {
        for(i=0; i < length; i++)
        {
            if(movie[i].status == 0)
            {
                return i;

            }
        }
        return retorno;
    }
    return retorno;
}

//int searchFreePlace(eMovie *movie,int length)
//{   int i;
//    int retorno=-1;
//    if(movie!=NULL && length>0)
//    {
//
//
//        for(i=0; i<length; i++)
//        {
//            if(movie[i].status==-1);
//            {
//                return i;
//            }
//
//        }
//        return -1;
//    }
//    return retorno;
//}
//

/** \brief Busca codigo en el array
 *
 * \param eMovie movie. Estructura de datos
 * \param int length. Tamaño de la estructura
 * \param int codeAux. Dato a buscar
 * \return 0 si no lo encontro, 1, si lo encuentra, -1 si no pudo buscarlo
 *
 */


int searchCode(eMovie *movie,int length,int codeAux)//borrar
{
    int retorno=-1;
    if (movie!=NULL && length>0)
    {
        int i;
        for(i=0; i<length; i++)
        {
            if(movie[i].code==codeAux && movie[i].status==0)
            {
                return i;
                retorno=1;

            }

        }
        retorno=0;
    }
    return retorno;//retorna -1 en caso de haber sido NULL o el largo del array no ser correcto
}

/** \brief Busca dato int en el array
 *
 * \param eMovie movie. Estructura de datos
 * \param int length. Tamaño de la estructura
 * \param int searchInt. Dato a buscar
 * \return 0 si no lo encontro, 1, si lo encuentra, -1 si no pudo buscarlo
 *
 */

int searchInt(eMovie* movie,int length,int searchInt)
{
    int i;
    int retorno=-1;
    if (movie!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if(movie[i].code == searchInt && movie[i].status==1)//1 ya esta cargado valor
                return i;//retorna el lugar donde esta ese codigo
        }
        return -1;
    }
    return retorno;
}

/** \brief Solicita ingreso de datos de la estructura
 *
 * \param eMovie movie. Estructura de datos
 * \param int length. Tamaño de la estructura
 * \return int. retorna -1 si no se pudo cargar o 0 si se cargaron los datos
 *
 */

int addMovie(eMovie* movie,int length)
{
    int retorno = -1;
    int codeAux;
    char titleAux[50];
    char descriptionAux[1000];
    char genreAux[30];
    int ratingAux;
    int durationAux;
    char linkAux[300];
    int freeIndex;

    if(movie!=NULL && length>0)
    {

        freeIndex = searchFreePlace(movie,QTY);//si status==0 retorna el indice, sino 1.
        //printf("%d",freeIndex);
        if(freeIndex==-1)
        {
            printf("No hay mas espacio\n");
            //break; //cdo estaba en el case del main
        }

        codeAux=getValidInt("Ingrese codigo de pelicula: \n","Ingrese codigo numerico\n",1,1000);
        if(searchInt(movie,QTY,codeAux)!=-1)
        {
            printf("El codigo ya existe\n");
            // break;
        }
        else
        {
        getValidString("Ingrese titulo de la pelicula: \n","El titulo tiene que ser alfabetico",titleAux);

        fflush(stdin);

        getValidString("Ingrese descripcion de la pelicula: \n","La descripcion tiene que ser alfabetica",descriptionAux);
        fflush(stdin);
        getValidString("Ingrese genero de la pelicula: \n","El genero tiene que ser alfabetico",genreAux);
        fflush(stdin);
        durationAux=getValidInt("Ingrese duracion total en minutos :\n","Ingrese datos numericos",30, 500);
        fflush(stdin);
        ratingAux = getValidInt("Ingrese puntuacion :\n","Ingrese datos numericos",1, 100);
        fflush(stdin);
        //printf("LINK : %s",linkAux);
        system("pause");
        getStringL("Ingrese link de la pelicula: \n",linkAux);
        printf("link : %s\n",linkAux);
        fflush(stdin);
        setMovie(movie,freeIndex,codeAux,titleAux,descriptionAux,genreAux,durationAux,ratingAux,linkAux);
        printf("\nTitulo %s\nDuracion %d\n%s\n%s\n %d\n", movie[freeIndex].title,movie[freeIndex].duration,movie[freeIndex].description,movie[freeIndex].genre,movie[freeIndex].status);
        retorno=0;

        }



    }
    return retorno;


}

/** \brief Carga datos ingresados por el usuario en la estructura
 *
 * \param eMovie movie. Estructura de datos
 * \param int FreeIndex. Indice de la estructura donde guarda el dato
 * \param int codeAux. Codigo de la pelicula.
 * \param char titleAux. Titulo de la pelicula.
 * \param char descriptionAux. Descripcion de la pelicula
 * \param char genreAux. Genero de la pelicula
 * \param int durationAux. Duracion de la pelicula
 * \param int ratingAux. Valoracion de la pelicula
 * \param char linkAux. Link a la pelicula
 * \return 0 si no lo encontro, 1, si lo encuentra, -1 si no pudo buscarlo
 *
 */

void setMovie(eMovie* movie,int freeIndex,int codeAux,char* titleAux,char* descriptionAux, char* genreAux, int durationAux,int ratingAux,char* linkAux)
{
//    int retorno=-1;
//    if(movie!= NULL && freeIndex!=-1)
//    {

    movie[freeIndex].code = codeAux;
    strcpy(movie[freeIndex].title,titleAux);
    strcpy(movie[freeIndex].description,descriptionAux);
    strcpy(movie[freeIndex].genre,genreAux);
    movie[freeIndex].duration = durationAux;
    movie[freeIndex].rating= ratingAux;
    strcpy(movie[freeIndex].link,linkAux);
    movie[freeIndex].status = 1;
    // retorno = 0;
    // }
    //return retorno;


    // printf("%d %s %s ", movie[freeIndex].code,movie[freeIndex].title,movie[freeIndex].description);
}

/** \brief Baja logica en determinado campo
 *
 * \param eMovie movie. Array a recorrer
 * \param int length. Tamaño del array
 * \return int -1 si no se pudo borrar o 0 si se borro.
 *
 */

int deleteData(eMovie* movie,int length)
{
    int retorno=-1;
    int dato;
    if(movie!=NULL && length>0)
    {
        if(campolleno(movie,QTY)==1)//1 nada cargado, -1 null y 0 cargaprevia
        {
            int datoEncontrado;
            dato = getValidInt("Ingrese el codigo de la pelicula a borrar","Ingrese codigo numerico\n",1,1000);
            datoEncontrado = searchInt(movie,length,dato);
            if(datoEncontrado==-1)//searchInt devuelve menos 1 cuando no esta cargado.????
            {
                printf("Codigo no encontrado");

            }
            movie[datoEncontrado].status = -1;
            printf("Los datos han sido borrados");//-1
            retorno = 0;
        }
        else
        {
            printf("No hay datos cargados\n");
        }
    }
    return retorno;

}
/** \brief Modifica datos en determinados campo
 *
 * \param eMovie movie. Array a recorrer
 * \param int length. Tamaño del array
 * \return void
 *
 */



void modify(eMovie *movie,int length)
{
    int codeAux;
    int option,ratingAux,durationAux;
    char titleAux[30],genreAux[50],linkAux [30],descriptionAux[30];

    if(campolleno(movie,QTY)==1)//0 nada cargado, -1 null y 1 cargaprevia
    {
        codeAux = getInt("Ingrese codigo de la pelicula a modificar\n");

        int i;
        for(i=0; i<length; i++)
        {
            if(movie[i].code==codeAux)
            {

                while(option!=7)
                {
                    option= getInt("\n 1- Titulo \n 2- Genero \n 3- Duracion \n 4- Descripcion\n 5- Puntaje\n 6- Link de imagen\n 7- Salir\n\n Ingrese una opcion: \n");
                    switch(option)
                    {
                    case 1: //titulo


                        getValidString("Ingrese titulo de la pelicula: \n","El titulo tiene que ser alfabetico",titleAux);
                        //fflush(stdin);
                        strcpy(movie->title,titleAux);
                        printf("Se cargo nuevo titulo %s\n", movie->title);
                        break;

                    case 2: //genero

                        //printf("%s\n", movie[i].genre);
                        getValidString("Ingrese genero de la pelicula: \n","El genero tiene que ser alfabetico",genreAux);
                        strcpy(movie[i].genre,genreAux);

                        break;

                    case 3://duracion

                       // printf("%d\n", movie[i].duration);
                        durationAux=getValidInt("Ingrese duracion total en minutos :\n","Ingrese datos numericos",30, 500);
                        movie[i].duration = durationAux;


                        break;

                    case 4:// descripcion


                        printf("la descripcion de la pelicula es: %s,\n", movie[i].description);
                        getString("Ingrese nueva descripcion: \n",descriptionAux);
                        strcpy(movie[i].description,descriptionAux);
                        break;


                    case 5://puntaje


                      //  printf("%d\n", movie[i].rating);
                        ratingAux = getValidInt("Ingrese nueva puntuacion :\n","Ingrese datos numericos",1, 100);
                        movie[i].rating= ratingAux;

                        break;
                    case 6://link

                        printf("El link de la pelicula es: %s,\n", movie[i].link);
                        getString("Ingrese nuevo link: \n",linkAux);
                        strcpy(movie[i].link, linkAux);
                        break;

                    case 7:
                        break;
                    default:
                        printf("Ingrese opcion de menu valida\n");

                    }//endSwitch

                }//cierre while

            } //cierre del if


        }

    }else
        {
          printf("No hay datos cargados para poder modificar\n");
        }
}

/** \brief Determina si hay datos cargados en el array.
 *
 * \param eMovie movie. Array a recorrer
 * \param int length. Tamaño del array
 * \return int -1 si no hay datos cargados o 1 si hay datos cargados.
 *
 */

int campolleno(eMovie *movie,int length)
{
    int retorno=-1;
    int i;
    if(movie!=NULL && length>0)
    {

        for(i=0; i<length; i++)
        {
            if(movie[i].status==1)
            {
                retorno = 1;//hay peliculas cargadas
                break;
            }
            retorno = 0;//si no hay nada cargado retorna 0.
        }
    }
    return retorno;
}




/** \brief Escribe datos cargados en un archivo binario
 *
 * \param eMovie Movie. La estructura de datos
 * \return int. Retorna -1 si no se pudo crear el archivo y 0 si se escribieron los datos.
 *
 */

int guardarEnArchivo(eMovie *movie)
{

    FILE *archFilm;

    archFilm=fopen("bin.dat","wb");
    if(archFilm == NULL)
    {
        printf("No se pudo escribir en el archivo\n");
        return -1;
    }

    fwrite(movie,sizeof(eMovie),QTY,archFilm);

    fclose(archFilm);
    printf("Se cargaron los archivos\n");
    return 0;
}

/** \brief Imprime archivo de texto
 *
 * \param eMovie movie. Estructura de datos
 * \return void
 *
 */

void crearTxt(eMovie *x)
{
    int i;
    FILE *f;
    f=fopen("Lista de Peliculas.txt", "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(f,"Listado de peliculas\n\n\n");
        fprintf(f,"Codigo   |   Titulo     |   Genero  |    Duracion  |  Descripcion |   Puntaje   | Poster\n");

        for(i=0; i<QTY; i++)
        {
            if(x[i].status == 1)
            {
                fprintf(f,"%6d   -   %-15s  -  %-40s  -  %5d  - %5s  - %5d  -  %s\n", x[i].code, x[i].title, x[i].genre, x[i].duration,x[i].description, x[i].rating,x[i].link);

            } //acomodar prolijo
        }
    }

    fclose(f);

    printf("Listado creado con exito\n");
    system("pause");
}

/** \brief Carga datos desde archivo
 *
 * \param eMovie x. estructura de datos
 * \return 1 si no se pudo crear el archivo y 0 si se pudo crear
 *
 */



int cargarDesdeArchivo(eMovie *x)
{
    int flag = 0;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            printf("NO SE PUDO CREAR EL ARCHIVO.");
            system("pause");
        }
        flag=1;
    }

    if(flag ==0)
    {
        fread(x,sizeof(eMovie),QTY,f);
    }

    fclose(f);
    return flag;
}

/** \brief Guarda datos de la estructura en el archivo
 *
 * \param eMovie movie. Estructura de datos
 * \return  int 1 si hubo error abriendo archivo y 0 si se pudo escribir
 *
 */

int saveMovie(eMovie *movie)
{
    FILE* fp;
    fp=fopen("bin.dat","ab+"); // append bin lo crea si no existe
    if(fp==NULL)
    {
        printf("Error abriendo el archivo");
        return 1;
    }
    fwrite(movie,sizeof(eMovie),1,fp); // escribo una struct al final

    fclose(fp);
    return 0;
}


/** \brief Genera html

 * \param eMovie movie. Estructura de datos
 * \param char title. titulo de la pelicula
 * \return
 *
 */


void generarHtml(eMovie *movie, char *title)
{

     int i;
     FILE *f;
     f=fopen(title, "w");

     if(f == NULL)
     {
          printf("Error. No se pudo abrir el archivo\n");
     }
     else
     {
        fprintf(f, "<!DOCTYPE html>\n");
        fprintf(f,"<html lang='en'>\n");
        fprintf(f,"<head>\n");
        fprintf(f,"\t<meta charset='utf-8'>\n");
        fprintf(f,"\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(f,"\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(f,"\t<title>Lista peliculas</title>\n");
        fprintf(f,"\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(f,"\t<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(f,"</head>\n");
        fprintf(f,"<body>\n");
        fprintf(f,"\t<div class='container'>\n");
        fprintf(f,"\t\t<div class='row'>\n");

            for(i=0; i<QTY; i++)
        {
            if(movie[i].status == 1)
            {
               //  fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Género:%s</li><li>Puntaje:%d</li><li>Duración:%d:%d</li></ul><p>%s</p></article><br><br><HR>",movie[i]"</article>\n");
                   fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje: %d</li><li>Duracion:%d min</li></ul><p>%s</p></article>\n",movie[i].link,movie[i].title,movie[i].genre,movie[i].rating,movie[i].duration,movie[i].description );

            }
        }
        fprintf(f,"\t\t</div>\n");
        fprintf(f,"\t</div>\n");
        fprintf(f,"\t<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(f,"\t<script src='js/bootstrap.min.js'></script>\n");
        fprintf(f,"\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(f,"\t<script src='js/holder.min.js'></script>\n");
        fprintf(f,"</body>\n");
        fprintf(f,"</html>\n");
        }

      fclose(f);

      printf("Listado creado con exito\n");

}


