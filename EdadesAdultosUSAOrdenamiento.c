// Funciones a utilizar

/*
    Biblioteca con funciones de entrada y salida de datos estandar 
    Funciones utilizadas:
    void printf(char *, ...);               Imprime en consola el texto con formato pasado en el argumento.
    int puts(char *);                       Imprime en consola el texto pasado en el argumento.
                                            Devuelve la cantidad de caracteres impresos.
    int putchar(char);                      Imprime en consola el caracter pasado en el argumento.
                                            Devuelve el caracter impreso.
    int scanf(char *, ...);                 Guarda con formato lo escrito en la consola estandar en el argumento.
                                            Devuelve un numero igual o mayo que 1 si leyo y guardo correctamente
                                            al menos elemento.
    int fscanf(FILE *, char *, ...);        Guarda con formato el contenido en un archio en el argumento.
                                            Devuelve un numero igual o mayo que 1 si leyo y guardo correctamente
                                            al menos elemento.
    FILE *fopen(char *, char *);            Abre un flujo entre el archvio y el programa, en el primer argumento
                                            se manda la direccion completa o relativa del archivo y en el segundo
                                            argumento la manera de leer.
                                            Devuelve un puntero a una estructura de datos de tipo FILE.
    int fclose(FILE *);                     Cierra el flujo de un archivo.
                                            Devuelve un numero que indica si la operacion se realizo con exito.
*/
#include <stdio.h>

/*
    Biblioteca con funciones para crear arreglos dinamicos con las funciones
    void *malloc(size_t);             Asigna el numero de bytes mandados en el argumento.
    void *realloc(void *, size_t);    Reasigna el numero de bytes mandados en el argumento
                                      a un arreglo asignado anteriormente con malloc(size_t);
    void free(void *);                Libera un espacio de memeoria asignado con malloc(size_t); o realloc(void *, size_t);
*/
#include <stdlib.h>

/*
    Biblioteca con funciones para manejar tiempo, contiene la funcion
    clock_t clock();    Devuelve el numero de pulsos de reloj que lleva el procesador desde que se inicio
                        el programa
*/
#include <time.h>

/*
    Mi biblioteca con funcion para imprimir arreglos
    void print_i(int *, int);    Imprime un arreglo de enteros como lo hace el lenguaje R.
*/
#include "MyPrintR.h"

/*
    Mi biblioteca con las funciones de ordenamiento echas en clase:
    void ordenamiento_burbuja_int(int *, int);   Ordena un arreglo con el ordanmiento burbuja.
    void ordenamiento_seleccion_int(int *, int); Ordena un arreglo con el ordenamiento por seleccion.
    void ordenamiento_insercion_int(int *, int); Ordena un arreglo con el ordenamiento por insercion.
*/
#include "C:\Programas\ESCOM_NS_ISC_S2_AED_(C)\Practicas\Algoritmos_Ordenamiento.h"

/*
    Mi biblioteca con funciones para manejar archivos, que contiene la unica funcion
    int LeerDatos(FILE *, int **);  Guarda en un arreglo todos los numeros en un archivo hasta que
                                    encuentre un caracter que no sea un numero o hasta que llego al fin
                                    de archivo.
                                    Devuelve la cantidad de numeros leidos.
*/
#include "C:\Programas\ESCOM_NS_ISC_S2_AED_(C)\Herramientas\archivos_funciones.h"


// Funcion principal

int main(int argc, char **argv)
{
    // Variables a utilizar

    FILE *base_datos = fopen(*(argv + 1), "rt");                        // Crear el flujo entre el archivo mandado desde consola y el programa.
    int *edades;                                                        // Puntero a un int que guardara la direccion de memoria donde
                                                                        // empieza el arreglo.
    int edades_longitud = LeerDatos(base_datos, &edades);               // Guardar los datos del archivo en el arreglo y alamacenar la cantidad de estos.
    fclose(base_datos);                                                 // Cerrar el flujo del archivo.
    int edades_copia1[edades_longitud], edades_copia2[edades_longitud]; // Punteros a int que guaradaran la direccion de memeoria donde
                                                                        // empeizan copias del arreglo edades.
    for(int i = 0; i < edades_longitud; i++)                            // Ciclo para hacer las copias.
    {
        edades_copia1[i] = edades[i];
        edades_copia2[i] = edades[i];
    }
    clock_t inicio, fin;                                                // Variables que alamacenara los pulsos de reloj, inicio para los
                                                                        // pulsos de reloj antes de ejecutar el algoritmo de ordenamiento
                                                                        // y fin para los pulsos de reloj despues de ejecutar el algoritmo de
                                                                        // ordenamiento.
    clock_t tiempo_burbuja, tiempo_seleccion, tiempo_insercion;         // Variables que alamacenaran la diference entre las variables inicio y fin
                                                                        // ejecutando el algortimo respectivo.


    // Procesamiento de datos

    // Ordenacion con ordenamiento burbuja
    inicio = clock();                                                   // Guardar los puslsos de reloj antes de ejecutar el algoritmo.
    ordenamiento_burbuja_int(edades, edades_longitud);                  // Ejecutar algoritmo de ordenamiento burbuja.
    fin = clock();                                                      // Guardar los pulsos de reloj despues de ejecutar el algoritmo.
    tiempo_burbuja = fin - inicio;                                      // Guardar la diferencia de los pulsos de reloj para calcular solo los
                                                                        // que le llevo al algoritmo ejecutarse por completo.

    // Ordenacion con ordenamiento por seleccion
    inicio = clock();
    ordenamiento_seleccion_int(edades_copia1, edades_longitud);
    fin = clock();
    tiempo_seleccion = fin - inicio;

    // Ordenacion con ordenamiento por insercion
    inicio = clock();
    ordenamiento_insercion_int(edades_copia2, edades_longitud);
    fin = clock();
    tiempo_insercion = fin - inicio;


    // Finalizacion

    // Impresion de datos del ordenamiento burbuja
    puts("\nOrdenamiento burbuja:");                                    // Titulo del algoritmo que se utilizo.
    print_i(edades, edades_longitud);                                   // Impresion del arreglo ordenado.
    printf("%d pulsos de reloj.\n", tiempo_burbuja);                    // Pulsos de reloj que le llevo al algoritmo
                                                                        // correspondiente ordenar el arreglo.
    
    // Impresion de datos del ordenamiento por seleccion
    puts("\nOrdenamiento seleccion:");
    print_i(edades_copia1, edades_longitud);
    printf("%d pulsos de reloj.\n", tiempo_seleccion);

    // Impresion de datos del ordenamiento por insercion
    puts("\nOrdenamiento insercion:");
    print_i(edades_copia2, edades_longitud);
    printf("%d pulsos de reloj.\n", tiempo_insercion);
}
