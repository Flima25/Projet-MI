#include "projet.h"

int main(void)
{
    int n = 3;
    double **M;
    double **L;
    double **U;
    double *X;
    M = ini_tab(n);
    L = crea_tab_floa(n,n);
    U = crea_tab_floa(n,n);
    crea_LU(M,L,U,n);
    
    printf("M");
    prnt_dbl_tb(M,n);
    printf("L");
    prnt_dbl_tb(L,n);
    printf("U");
    prnt_dbl_tb(U,n);

    X = ft_maillage(n-2);

    for(int i = 0;i<n;i++)
	    printf("%f|",X[i]);
    double *B_h = second_membre(n,0,0,X);

    for(int i = 0;i<n;i++)
	    printf("%f|",B_h[i]);

    double *Y = descente(L,B_h,n);
    for(int i = 0;i<n;i++)
	    printf("%f|",Y[i]);

    double *X_e = remonte(U,Y,n);
    for(int i = 0;i<n;i++)
	    printf("%f|",X_e[i]);


    free_tab(M,n);
    free_tab(L,n);
    free_tab(U,n);
    free(X);
    free(B_h);
    free(Y);
    free(X_e);
    return 1;
}
