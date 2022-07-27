#include <stdio.h>
#include <stdlib.h>

double** make_matrix(int m, int n);

int main()
{    
    printf("Hello World!\n");
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d %d\n", m, n);
    double c[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &c[i]);
        printf("%.6g\t", c[i]);
    }
    printf("\n");

    double** a = make_matrix(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &a[i][j]);
            printf("%.6g\t", a[i][j]);
        }
        printf("\n");
    }
    
    double b[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%lf", &b[i]);
        printf("%.6g\t", b[i]);
    }
    printf("\n");
    return 0;
}

double** make_matrix(int m, int n)
{
    double** a;
    int i;
    a = calloc(m, sizeof(double*));
    for (i = 0; i < m; i++)
    {
        a[i] = calloc(n, sizeof(double));
    }
    return a;
}