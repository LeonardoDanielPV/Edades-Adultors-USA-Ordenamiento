#include <stdio.h>
#include<C:\Programas\ESCOM_NS_LCD_S1_FP_(C)\Ejercicios\Manejo de matrices\mystringint.h>

int long_num_i(int);
int long_num_mayor_i(int [], int);
void print_i(int [], int); // max 80 (despues de los corchetes de desplazamiento)
int myceil(float);
int myfloor(float);
float mycociente(int, int);

int main()
{
    int a[128] = {0};
    int l;
    l = LeeArreglo(a);
    print_i(a, l);
}

int long_num_i(int n)
{
    int aux = n;
    if(n < 0)
        aux = -aux;
    int digitos = 1;
    while((aux = aux/10) != 0)
        digitos++;
    if(n < 0)
        return digitos + 1;
    return digitos;
}

int long_num_mayor_i(int a[], int l)
{
    int aux, mayor = 0;
    for(int i = 0; i < l; i++)
        if((aux = long_num_i(a[i])) > mayor)
            mayor = aux;
    return mayor;
}

void print_i(int a[], int l)
{
    int digitos_del_numero_mayor = long_num_mayor_i(a, l);
    int numeros_por_renglon = myfloor(mycociente(80, digitos_del_numero_mayor + 1));
    int renglones = myceil(mycociente(l, numeros_por_renglon));
    int ultimo_corchete = numeros_por_renglon * (renglones - 1);
    for(int h = 0; h <= ultimo_corchete; h += numeros_por_renglon)
    {
        for(int j = 0; j < long_num_i(ultimo_corchete) - long_num_i(h); j++)
                putchar(' ');
        printf("[%d]", h);
        for(int i = 0; i < numeros_por_renglon && (i + h) < l; i++)
        {
            putchar(' ');
            for(int j = 0; j < digitos_del_numero_mayor - long_num_i(a[i + h]); j++)
                putchar(' ');
            printf("%d", a[i + h]);
        }
        putchar('\n');
    }
}

int myceil(float n)
{
    int aux = n;
    if(aux < n)
        return aux + 1;
    else
        return aux;
}

int myfloor(float n)
{
    int aux = n;
    return aux;
}

float mycociente(int n, int d)
{
    float nf = n, df = d;
    return nf / df;
}
