

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;

} ePersona;


void inicializarVec(ePersona vector[], int length);
int revisarEstado(ePersona vector[],int length, int *indice);
void cargarAlta(ePersona* vector, int length, int indiceLibre);
int revisarDni(ePersona vector[],int length, int parametro, int *indice);
void borrarDatos(ePersona[],int);
void ordenarNombre(ePersona[],int);
int esUnNumero(char str[]);
int soloLetras (char string[]);
void graficoEdad(ePersona vector[], int length);
