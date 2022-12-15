#include "projet.h"

double    **ini_tab(int n)
{
    int i,j;
    double **M;
    M = crea_tab_floa(n,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if (i==j)
            {
                M[i][j] = (2);
            }
            else if (((i < n) && (i + 1 == j)) || ((i>0) && (i-1 == j)))
            {
                M[i][j] = (-1);
            }
        }
    }
    return(M);
}

void    crea_LU(double **A,double **L,double **U,int n)
{
    int i;
    U[0][0] = A[0][0];
    for (i=0;i<n;i++)
    {
        L[i][i] = 1;
        if (i<n-1)
            U[i][i+1] = A[i][i+1];
        if (i>0)
        {
            L[i][i-1] = A[i][i-1] - U[i-1][i-1];
            if (i<n)
                U[i][i] = A[i][i]/(U[i-1][i]*(L[i][i-1]));
        }
    }
}

double	*ft_maillage(int n)
{
	double h;
       	h = 1/((float)(n)+1);
	double *X;

	X = malloc(sizeof(double)*(n+2));
	for(int i = 0;i<n+2;i++)
	{
		X[i] = i*h;
	}
	return(X);
}

double *second_membre(int n,double alpha,double beta, double *X)
{
	double *B_h;
	int h;
	int h2;
        B_h = malloc(sizeof(double)*n);
	h=1/(n+1);
	h2=h*h;
	B_h[0] = h2*S(X[0]) + alpha;
	for(int i = 0;i<n-1;i++)
		B_h[i]=h2*S(X[i]);
	B_h[n-1]=h2*S(X[n-1])+ beta;
	return (B_h);
}

double *descente(double **L,double *B_h,int n)
{
	double *Y;
        Y = malloc(sizeof(double)*n);
	Y[0]=B_h[0];
	for(int i = 1;i<n;i++)
		Y[i]=B_h[i] - L[i][i-1];
	return (Y);
}

double *remonte(double ** U,double *Y,int n)
{
	double *X;
        X = malloc(sizeof(double)*(n));
	X[n-1]=Y[n-1]/U[n-1][n-1];
	for(int i = n-2;i>-1;i--)
		X[i]=(Y[i] - (U[i][i+1]*X[i+1]))/U[i][i];
	return (X);
}

double	S(double x)
{
	return (0);
}
