

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
}EMovie;

void muestraTitulo();
void verEstadoDeArchivo(EMovie*);
void agregarPelicula(EMovie*);
EMovie* newMovie(void);
EMovie* newMovieParametros(char[], int, char[], char[], int, char[], int);
int guardarEnArchivo(EMovie*);
void generarPagina(EMovie*);

