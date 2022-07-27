#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

struct simplex_t {
    int m;
    int n;
    int* var;
    double** a;
    double* b;
    double* x;
    double* c;
    double y;
};

typedef struct simplex_t simplex_t;

double** make_matrix(int m, int n);

int init(   simplex_t* s, 
            int m, 
            int n, 
            double** a,
            double* b, 
            double* c, 
            double* x,
            double y, 
            int* var);

double xsimplex(int m,
                int n, 
                double** a, 
                double* b, 
                double* c, 
                double* x, 
                double y, 
                int* var, 
                int h);

double simplex( int m, 
                int n, 
                double** a,
                double* b,
                double* c, 
                double* x, 
                double y);

void pivot(simplex_t* s, int row, int col);

int initial(simplex_t* s,
            int m,
            int n,
            double** a,
            double* b,
            double* c,
            double* x,
            double y,
            int* var);

int select_nonbasic(simplex_t* s);

#endif