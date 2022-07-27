#include "utils.h"

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
    }

    double** a = make_matrix(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    
    double b[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%lf", &b[i]);
    }

    print_equation(m, n, a, b, c);

    double y;
    double* x = (double*) calloc(n+1, sizeof(double));
    y = simplex(m, n, a, b, c, x, 0);
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
    free(x);
    printf("SIMPLEX RESULT = %lf\n", y);
    return 0;
}