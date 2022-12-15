#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// ft_mem.c - Fonction gestion mémoire
void	prnt_dbl_tb(double **M,int n);
double   **crea_tab_floa(int n,int m);
void    free_tab(double **M,int n);

// ft_mat.c - Fonction gestion matrice
double    **ini_tab(int n);
void    crea_LU(double **A,double **L,double **U,int n);
double	*ft_maillage(int n);
double *second_membre(int n,double alpha,double beta, double *X);
double *descente(double **L,double *B_h,int n);
double *remonte(double ** U,double *Y,int n);
double	S(double x);




