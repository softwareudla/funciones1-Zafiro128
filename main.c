#include <stdio.h>
#include <string.h>
#include "funciones.h"


// Funciones
int ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS]);
float calcularTotal(float precios[MAX_PRODUCTOS], int numProductos);
float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos);
int encontrarMasCaro(float precios[MAX_PRODUCTOS], int numProductos);
int encontrarMasBarato(float precios[MAX_PRODUCTOS], int numProductos);
void imprimirResultados(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, float total, float promedio, int idxCaro, int idxBarato);
void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos);

int main() {
    char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE];  // Matriz para almacenar los nombres
    float precios[MAX_PRODUCTOS];                      // Arreglo para almacenar los precios
    float total, promedio;
    int idxCaro, idxBarato, numProductos;

    // Ingreso de productos
    numProductos = ingresarProductos(nombres, precios);

    // Cálculos
    total = calcularTotal(precios, numProductos);
    promedio = calcularPromedio(precios, numProductos);
    idxCaro = encontrarMasCaro(precios, numProductos);
    idxBarato = encontrarMasBarato(precios, numProductos);

    // Imprimir resultados
    imprimirResultados(nombres, precios, numProductos, total, promedio, idxCaro, idxBarato);

    // Búsqueda de producto
    buscarProducto(nombres, precios, numProductos);

    return 0;
}


