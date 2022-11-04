void ordenamiento_burbuja_int(int *, int);
void ordenamiento_seleccion_int(int *, int);
void ordenamiento_insercion_int(int *, int);

void ordenamiento_burbuja_int(int *num1, int num1_length)
{
    int aux;
    int eliminar = 2;
    while(num1_length > eliminar - 1)
    {
        for(int i = 0; i <= num1_length - eliminar; i++)
            if(num1[i] > num1[i + 1])
            {
                aux = num1[i];
                num1[i] = num1[i + 1];
                num1[i + 1] = aux;
            }
            else
            {
            }
        eliminar++;
    }
}

void ordenamiento_seleccion_int(int *num1, int num1_length)
{
    int menor_ap;
    int menor_val;
    for(int i = 0; i <= num1_length - 1; i++)
    {
        menor_ap = i;
        menor_val = num1[i];
        for(int j = i + 1; j <= num1_length - 1; j++)
            if(num1[j] < num1[menor_ap])
            {
                menor_ap = j;
                menor_val = num1[j];
            }
        num1[menor_ap] = num1[i];
        num1[i] = menor_val;
    }
}

void ordenamiento_insercion_int(int *num1, int num1_length)
{
    int aux;
    for(int i = 0; i < num1_length - 1; i++)
    {
        for(int j = i + 1; j < num1_length; j++)
        {
            if(num1[j] < num1[i])
            {
                aux = num1[j];
                for(int k = j - 1; k >= i; k--)
                {
                    num1[k + 1] = num1[k];
                }
                num1[i] = aux;
            }
        }
    }
}
