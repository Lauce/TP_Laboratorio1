
typedef struct
{
    int code;
    char title[50];
    char description[1000];
    char genre[50];
    char link[300];
    int status;
    int duration;
    int rating;

}eMovie;


int initStatus(eMovie* movie,int length,int value);
int searchFreePlace(eMovie *movie,int length);
int searchCode(eMovie *movie,int length,int codeAux);

int addMovie(eMovie *movie,int length);
void setMovie(eMovie *movie,int freeIndex, int codeAux,char* titleAux,char *descriptioAux, char* genreAux, int durationAux,int ratingAux,char* linkAux);
void modify (eMovie *movie,int length);


int searchInt(eMovie *movie,int length,int searchInt);
int deleteData(eMovie *movie,int length);
int campolleno(eMovie *movie,int length);


int guardarEnArchivo(eMovie *movie);

void crearTxt(eMovie *x);
int cargarDesdeArchivo(eMovie *x);

void generarHtml(eMovie *movie, char *title);
int saveMovie(eMovie *movie);
