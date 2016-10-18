int getInt(char *message);
char getChar(char *mensaje);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char *str);

void getString(char *mensaje,char *data);
int getStringLetras(char *mensaje,char *data);
int getStringNumeros(char *mensaje,char *data);
int getStringNumerosFlotantes(char *mensaje,char *data);
void getStringL(char *mensaje,char *input);

int getValidInt(char *requestMessage,char *errorMessage, int lowLimit, int hiLimit);
void getValidString(char *requestMessage,char *errorMessage, char *input);
