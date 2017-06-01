

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;

void muestraTitulo();
void agregarPelicula(EMovie*, EMovie*[], int);
EMovie* newMovie(void);
EMovie* newMovieParametros(char[], int, char[], char[], int, char[]);
int guardarEnArchivo(EMovie*[], int);
void generarPagina(EMovie*[], char[], int, EMovie*);

