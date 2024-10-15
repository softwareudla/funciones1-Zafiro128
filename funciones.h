#define MAX_PRODUCTOS 10
#define MAX_LONGITUD_NOMBRE 20

int ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS]);
float calcularTotal(float precios[MAX_PRODUCTOS], int numProductos);
float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos);
int encontrarMasCaro(float precios[MAX_PRODUCTOS], int numProductos);
int encontrarMasBarato(float precios[MAX_PRODUCTOS], int numProductos);
void imprimirResultados(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, float total, float promedio, int idxCaro, int idxBarato);
void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);