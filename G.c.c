#include<stdio.h>
#include<math.h>

#define SIZE 3

void printMatrix(double A[SIZE][SIZE+1])
{
    for(int i = 0; i<SIZE;i++)
    {
        for(int j = 0; j<SIZE+1;j++)
        {
            printf("%8.2f",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    double A[SIZE][SIZE+1];
    double x[SIZE];
    int i,j,k;
    
    printf("Enter the augmented matrix\n");
    
    for(i = 0; i<SIZE;i++)
    {
        for(j=0;j<SIZE+1;j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }
    printf("\n");
    
    //forward elimination
    for(i=0;i<SIZE-1;i++)
    {
        if(A[i][i] == 0)
        {
            printf("Math error: division by zero\n");
            return 1;
        }else
        {
            for(j=i+1;j<SIZE;j++)
            {
                float ratio = A[j][i]/A[i][i];
                for(k=0;k<SIZE+1;k++)
                {
                    A[j][k] -= ratio*A[i][k];
                }
            }
        }
    }
    
    printMatrix(A);
    
    //back substitution
    for(i = SIZE-1;i>=0;i--)
    {
        x[i] = A[i][SIZE];
        for(j=i+1;j<SIZE;j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i]; 
     } 
     
     for(i = 0; i<SIZE; i++)
     {
         printf("%d: %f\n", i+1,x[i]);
     }
    
}