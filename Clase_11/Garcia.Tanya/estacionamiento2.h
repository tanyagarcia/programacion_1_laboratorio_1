
typedef struct
{
    int idDuenio;
    char nombre[50];
    char apellido[50];
    char direccion[100];
    int tarjeta;
    int flagEstado;

}eDuenio;

typedef struct
{
    char patente[100];
    int marca;
    int idDuenio;
    int horarioEntrada;
    int horarioSalida;
    int totalEstadia;
    int flagEstado;

}eEstacionamiento;

void inicializarDuenios(eDuenio[], int);
void cargarDuenios(eDuenio[], int);
void modificarTarjeta(eDuenio[], int);

void inicializarEstacionamiento(eEstacionamiento[], int);
int buscarLibre(eEstacionamiento[], int);
void cargarAutos(eEstacionamiento[], int);


void egresoDeAuto(eEstacionamiento[], int);
void ordenarEstacionamiento(eEstacionamiento[], int);
void marcaAudi(eEstacionamiento[], int);
void informesDeRecaudacion(eEstacionamiento[], int);
