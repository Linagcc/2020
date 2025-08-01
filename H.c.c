#include<stdio.h>
#include<math.h>

#define SIZE 3

void printMatrix(double A[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            printf("%.4lf",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void householder(double A[SIZE][SIZE])
{
    
    for(int i=0;i<SIZE-2;i++)
    {
        double noam = 0;
        for(int k=i+1;k<SIZE;k++)
        {
            noam += A[k][i]*A[k][i];
        }
        noam = sqrt(noam);
        if(noam == 0.0) break;


        double v[SIZE] = {0};
        double sign = (A[i+1][i] >= 0) ? 1.0: -1.0;
        v[i+1] = A[i+1][i] + sign*noam;

        for(int k = i+2;k<SIZE;k++)
        {
            v[k] = A[k][i];
        }

        double v_noam = 0;
        for(int k =i+1;k<SIZE;k++)
        {
            v_noam += v[k]*v[k];
        }
        v_noam = sqrt(v_noam);

        for(int k =i+1; k<SIZE;k++)
        {
            v[k] /= v_noam;
        }


        for(int k=i;k<SIZE;k++)
        {
            for(int j=k;j<SIZE;j++)
            {
                double dot = 0.0;
                for(int m = i+1;m<SIZE;m++)
                {
                    dot += v[m]*A[m][j];
                }

                for(int m = i+1;m<SIZE;m++)
                {
                    A[m][j] -= 2*v[m]*dot;
                }
            }
        }

        for(int k=i;k<SIZE;k++)
        {
            for(int j=k;j<SIZE;j++)
            {
                double dot = 0.0;
                for(int m = i+1;m<SIZE;m++)
                {
                    dot += v[m]*A[j][m];
                }

                for(int m = i+1;m<SIZE;m++)
                {
                    A[j][m] -= 2*v[m]*dot;
                }
            }
        }
    }  
}

int main()
{
    double A[SIZE][SIZE] = 
    {
        {4.0,1.0,-2.0},
        {1.0,2.0,0.0},
        {-2.0,0.0,3.0}
    };

    printf("Original matrix is: \n");
    printMatrix(A);

    householder(A);

    printf("\nMatrix after Householder Tridiagonalization:\n");
    printMatrix(A);

    return 0;
}