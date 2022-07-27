#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

static const double EPSILON = 1e-6;

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

struct node_t {
    int m; /* Constraints. */
    int n; /* Decision variables. */
    int k; /* Parent branches on xk. */
    int h; /* Branch on xh. */
    double xh; /* xh. */
    double ak; /* Parent ak. */
    double bk; /* Parent bk. */
    double* min; /* Lower bounds. */
    double* max; /* Upper bounds. */
    double** a; /* A. */
    double* b; /* b. */
    double* x; /* x. */
    double* c; /* c. */
    double z; /* z. */
    struct node_t* next;
};

typedef struct node_t node_t;

struct node_list_t {
    node_t* head;
    node_t* tail;
    double size;
};

typedef struct simplex_t simplex_t;
typedef struct node_list_t node_list_t;

double** make_matrix(int m, int n);

void print_equation(int m, 
                    int n, 
                    double** a,
                    double* b, 
                    double* c);

int init(   simplex_t* s, 
            int m, 
            int n, 
            double** a,
            double* b, 
            double* c, 
            double* x,
            double y, 
            int* var);

int select_nonbasic(simplex_t* s);

void prepare(simplex_t* s, int k);

int initial(simplex_t* s,
            int m,
            int n,
            double** a,
            double* b,
            double* c,
            double* x,
            double y,
            int* var);

void pivot(simplex_t* s, int row, int col);

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


node_t* initial_node(int m, int n, double** a, double* b, double* c);

node_t* extend(  node_t* p,
                int m,
                int n,
                double** a,
                double* b,
                double* c,
                int k,
                double ak,
                double bk);

int is_integer(double* xp);

int integer(node_t* p);

void bound(node_t* p, node_list_t* h, double* zp, double* x);

int branch(node_t* q, double z);

void succ(  node_t* p,
            node_list_t* h,
            int m,
            int n,
            double** a,
            double* b,
            double* c,
            int k,
            double ak,
            double bk,
            double* zp,
            double* x);

double intopt(int m, int n, double** a, double* b, double* c, double* x);

node_list_t* init_set(node_t* p);

node_t* get_node(node_list_t* h);

void add_node(node_list_t* h, node_t* q);

void put_tail(node_list_t* h, node_t* q);

#endif