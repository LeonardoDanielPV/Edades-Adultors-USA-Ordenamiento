int LeerDatos(FILE *, int **);

int LeerDatos(FILE *archivo, int **arreglo)
{
    int valida;
    int arreglo_longitud = 0;
    int *x = (int *)malloc((arreglo_longitud + 1) * sizeof(int));
    int *y;
    while((valida = fscanf(archivo, "%d", x + arreglo_longitud)) == 1)
    {
        arreglo_longitud++;
        y = (int *)realloc(x, (arreglo_longitud + 1) * sizeof(int));
        if(y == NULL)
        {
            free(y);
            return 0;
        }
        x = y;
    }
    *arreglo = x;
    return arreglo_longitud;
}
