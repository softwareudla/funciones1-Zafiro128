#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Función para ingresar los productos
int ingresarProductos(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS]) {
    int numProductos;

    do {
        printf("¿Cuantos productos deseas ingresar? (Maximo %d): ", MAX_PRODUCTOS);
        scanf("%d", &numProductos);
        getchar();  // Limpiar el buffer
        if (numProductos < 1 || numProductos > MAX_PRODUCTOS) {
            printf("Numero invalido. Debes ingresar entre 1 y %d productos.\n", MAX_PRODUCTOS);
        }
    } while (numProductos < 1 || numProductos > MAX_PRODUCTOS);

    for (int i = 0; i < numProductos; i++) {
        printf("Ingresa el nombre del producto %d: ", i + 1);
        fgets(nombres[i], MAX_LONGITUD_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0;  // Eliminar el salto de línea al final

        printf("Ingresa el precio del producto %d: ", i + 1);
        scanf("%f", &precios[i]);
        getchar();  // Limpiar el buffer
    }

    return numProductos;  // Devolver el número de productos ingresados
}

// Función para calcular el total del inventario
float calcularTotal(float precios[MAX_PRODUCTOS], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

// Función para calcular el promedio de precios
float calcularPromedio(float precios[MAX_PRODUCTOS], int numProductos) {
    float total = calcularTotal(precios, numProductos);
    return total / numProductos;
}

// Función para encontrar el producto más caro
int encontrarMasCaro(float precios[MAX_PRODUCTOS], int numProductos) {
    int idxCaro = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[idxCaro]) {
            idxCaro = i;
        }
    }
    return idxCaro;
}

// Función para encontrar el producto más barato
int encontrarMasBarato(float precios[MAX_PRODUCTOS], int numProductos) {
    int idxBarato = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[idxBarato]) {
            idxBarato = i;
        }
    }
    return idxBarato;
}

// Función para imprimir los resultados
void imprimirResultados(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos, float total, float promedio, int idxCaro, int idxBarato) {
    printf("\n--- Resultados del inventario ---\n");
    printf("Total del inventario: $%.2f\n", total);
    printf("Promedio de precio: $%.2f\n", promedio);
    printf("Producto mas caro: %s ($%.2f)\n", nombres[idxCaro], precios[idxCaro]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[idxBarato], precios[idxBarato]);
}

// Función para buscar un producto por nombre
void buscarProducto(char nombres[MAX_PRODUCTOS][MAX_LONGITUD_NOMBRE], float precios[MAX_PRODUCTOS], int numProductos) {
    char nombreBusqueda[MAX_LONGITUD_NOMBRE];
    char continuar;

    do {
        int encontrado = 0;

        printf("\nIngresa el nombre del producto a buscar: ");
        fgets(nombreBusqueda, MAX_LONGITUD_NOMBRE, stdin);
        nombreBusqueda[strcspn(nombreBusqueda, "\n")] = 0;  // Eliminar el salto de línea al final

        for (int i = 0; i < numProductos; i++) {
            if (strcmp(nombres[i], nombreBusqueda) == 0) {
                printf("Producto encontrado: %s, Precio: $%.2f\n", nombres[i], precios[i]);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }

        // Preguntar al usuario si desea hacer otra búsqueda
        printf("¿Deseas realizar otra busqueda? (s/n): ");
        continuar = getchar();
        getchar();  // Limpiar el buffer para la siguiente entrada

    } while (continuar == 's' || continuar == 'S');  // Continuar si el usuario ingresa 's' o 'S'

    printf("Fin de las busquedas.\n");
}
