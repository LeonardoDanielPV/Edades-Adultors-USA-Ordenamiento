int LeeArreglo(int []);
void ImpArreglo(int [], int);
int NumsPar(int [], int);
int NumsNon(int [], int);
void InvArr(int [], int);
/* 1 si son iguales, 0 si no son iguales */
int SonIguales(int [], int [], int);
/* Copia el primero en el segundo */
int CopiaArr(int [], int []);
/* 1 si es palindromo, 0 si no lo es */
int EsPalindromo(int [], int);

/* Ruleta, casillas */
void GiraIzq(int [], int);
/* Ruleta, casillas, movimientos */
void GiraIzqN(int [], int, int);
/* Ruleta, casillas */
void GiraDer(int [], int);
/* Ruleta, casillas, movimientos */
void GiraDerN(int [], int, int);

/* Arreglo, longitud */
void Burbuja(int [], int);
/* Arreglo 1, longitud del 1er arreglo, arreglo 2, longitud del 2do arreglo, arreglo que tendra la union */
int UneOrden(int [], int, int [], int, int []);
/* Arreglo, longitud, numero a buscar
Recibe un arreglo de longitud n, regresa cuantas ocurrencias de un numero hay dentro del arreglo */
int Ocurrencias(int [], int, int);
/* Arreglo, longitud, numero a buscar
Version recursiva de la funcion Ocurrencias*/
int OcurrenciasRecur(int [], int, int);
/* Arreglo, longitud */
int OcurrenciasTotal(int [], int);
/* Arreglo, longitud, numero a buscar
Busqueda secuencial, exsaustiva o de fuerza bruta */
int EstaEn(int a[], int n, int x);
void OcurrenciasUnoTotal(int [], int );
/* Utilizando OcurrenciasUno hacer funcion que me diga que elementos ocurren dos veces */
void OcurrenciasDosTotal(int [], int );
/* Arreglo, direccion donde esta la longitud del arreglo, posicion desde donde se recorre(desplazamiento)
Reccore los numeros de un arreglo a la derecha una vez desde la posicion (se repitira el numero que estaba
donde se recorrio) */
void Recorre(int [], int *, int);
/* Una funcion que recibe como argumento un arreglo de enteros, direccion del tamaño del arreglo y dos enteros mas
donde el primero estara envuelto entre el otro*/
void Envuelve(int [], int *, int, int);

int LeeArreglo(int a[])
{
    int i = 0, x;
    do
    {
        scanf("%d", &x);
        if(x)
            a[i++] = x;
    } while (x);
    return i;
}

void ImpArreglo(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}

int NumsPar(int a[], int n)
{
    int c = 0;
    for(;n > 0; n--)
        if(!(a[n - 1] % 2))
            c++;
    return c;
}

int NumsNon(int a[], int n)
{
    return n - NumsPar(a, n);
}

void InvArr(int a[], int n)
{
    int t = 0;
    for(int i = 0; i < n/2; i++)
    {
        t = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = t;
    }
}

int SonIguales(int a[], int b[], int n)
{
    for(; n > 0; n--)
        if(a[n - 1] != b[n - 1])
            return 0;
    return 1;
}

int CopiaArr(int a[], int b[])
{
    int i = 0;
    while(b[i++] = a[i]);
    return i--;
}

int EsPalindromo(int a[], int n)
{
    int b[124] = {0};
    CopiaArr(a, b);
    InvArr(b, n);
    return SonIguales(a, b, n);
}

void GiraIzq(int ruleta[], int cas)
{
    int t = ruleta[cas - 1];
    ruleta[cas - 1] = ruleta[0];
    for(int j = 0; j < cas - 1 - 1; j++)
        ruleta[j] = ruleta[j + 1];
    ruleta[cas - 1 - 1] = t;
}

void GiraIzqN(int ruleta[], int cas, int mov)
{
    for(int i = 0; i < mov; i++)
        GiraIzq(ruleta, cas);
}

void GiraDer(int ruleta[], int cas)
{
    InvArr(ruleta, cas);
    GiraIzq(ruleta, cas);
    InvArr(ruleta, cas);
}

void GiraDerN(int ruleta[], int cas, int mov)
{
    for(int i = 0; i < mov; i++)
        GiraDer(ruleta, cas);
}

void Burbuja(int a[], int n)
{
    int i, j, t;
    for(j = 1; j < n; j++)
        for(i = n - 1; i >= j; i--)
            if(a[i] < a[i - 1])
            {
                t =a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
            }
}

int UneOrden(int a[], int n, int b[], int m, int c[])
{
    int i_a = 0, i_b = 0, i_c = 0;
    while(i_a < n && i_b < m)
        if(a[i_a] < b[i_b])
            c[i_c++] = a[i_a++];
        else
            c[i_c++] = b[i_b++];
    while(i_a < n)
        c[i_c++] = a[i_a++];
    while(i_b < m)
        c[i_c++] = b[i_b++];
    return i_c;
}

int Ocurrencias(int a[], int n, int x)
{
    int c = 0;
    while(--n >= 0)
        if(a[n] == x)
            c++;
    return c;
}

int OcurrenciasRecur(int a[], int n, int x)
{
    if(n == 0)
        return 0;
    if(a[--n] == x)
        return 1 + OcurrenciasRecur(a, n, x);
    return OcurrenciasRecur(a, n, x);
}

int OcurrenciasTotal(int a[], int n)
{
    int aux[128] = {0}, num, c = 0;
    for(int i = 0; i < n; i++)
    {
        if(aux[i] == 0)
        {
            num = a[i];
            for(int j = 0; j < n; j++)
            {
                if(a[j] == num)
                {
                    aux[j] = 1;
                    c++;
                }
            }
            printf("El numero %d ocurre %d veces", num, c);
        }
        c = 0;
    }  
}

int EstaEn(int a[], int n, int x)
{
    while(--n >= 0)
        if(a[n] == x)
            return 1;
    return 0;
}

void OcurrenciasUnoTotal(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(!EstaEn(a + i + 1, n - i, a[i]) && !EstaEn(a, i, a[i]))
        {
            printf("%d\n", a[i]);
        }
    }
}

void OcurrenciasDosTotal(int a[], int n)
{
    int copia[128] = {0};
    CopiaArr(a, copia);
    int borrados[128] = {0};
    int longborrados = 0;
    for(int i = 0; i < n; i++)
    {
        while(!EstaEn(borrados, longborrados, copia[i]))
        {
            borrados[longborrados] = copia[i];
            longborrados++;
            copia[i] = 0;
            GiraIzq(copia + i, n);
            n--;
        }
    }
    OcurrenciasUnoTotal(copia, longborrados);
}

void Recorre(int a[], int *n, int posicion)
{
    for(int i = 0; i < (*n - posicion); i++)
        a[*n - i] = a[*n - i - 1];
    (*n)++;
}

void Envuelve(int a[], int *n, int x, int y)
{
    if(EstaEn(a, *n, x))
    {
        int i = 0;
        while(a[i] != x)
            i++;
        Recorre(a, n, i);
        Recorre(a, n, i);
        a[i] = y;
        a[i + 2] = y;
    }
}
