#include "projet.h"


// Affiche un tableau double de taille n 
void	prnt_dbl_tb(double **M,int n)
{
    printf("\nNew\n\n");
    for (int i = 0;i<n;i++)
    {
	printf("|");
    	for (int j = 0;j<n;j++)
	{
		printf("%f|",M[i][j]);
	}
	printf("\n");
    }
}

// Crée un tableau de double de taille n*m
double   **crea_tab_floa(int n,int m)
{
    double **ret;
    int i;
    int j;

    if (!(ret = (double**)(malloc(sizeof(ret)*n))))
        exit(1);
    for(i=0;i<n;i++)
        if(!(ret[i] = (double*)malloc(sizeof(*ret)*m)))
            exit(1);
    for (i = 0;i<n;i++)
    	{
    		for (j = 0;j<n;j++)
		{
			ret[i][j] = (0);
		}
    	}
    return (ret);
}

//Libere un tableau de taille ?*n
void    free_tab(double **M,int n)
{
    int i;
    for(i=0;i<n;i++)
        free(M[i]);
    free(M);
}


