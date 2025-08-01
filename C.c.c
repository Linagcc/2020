
#include<stdio.h>
#include<math.h>

#define N 3

//logic
void enterMatrix(double A[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%lf",&A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void cholesky(double A[N][N], double L[N][N])
{
    for(int i=0;i<N;i++) //loop for  each row
    {
        for(int j=0;j<=i;j++) //loop for each column upto diagonal
        {
            double sum = 0;
            
            if(i==j)
            {
                for(int k=0;k<j;k++) // check whether there are element in back
                {
                    sum += pow(L[j][k],2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            }else
            {
                for(int k =0; k<j;k++) // check whether there are element in back
                {
                    sum += L[j][k]*L[i][k]; //not clear
                }
                L[i][j] = (A[i][j]-sum)/L[j][j]; //not clear
            }
        }
    }
}



void Transpose(double L[N][N], double Ltrans[N][N])
{
    for(int i =0;i<N;i++)
    {
        for( int j=0;j<N;j++)
        {
           Ltrans[j][i] = L[i][j];
        }
    }
}

//forward substitution for L matrix
void forwardSubstitution(double L[N][N], double b[N], double y[N])
{
        for(int i=0;i<N;i++)
        {
            double sum =0;
            for(int j=0;j<i;j++)
                {
                    sum += L[i][j]*y[j];
                }
            y[i] = (b[i]-sum)/L[i][i];
        }
}

void backSubstitution(double Ltrans[N][N], double y[N], double x[N])
{
    for(int i= N-1;i>=0;i--)
    {
        double sum = 0;
        for(int j=i+1;j<N;j++)
        {
            sum += Ltrans[i][j]*x[j];
        }
        x[i] = (y[i]-sum)/Ltrans[i][i];
    }
}

void print(double y[N])
{
    for(int i =0;i<N;i++)
    {
        printf("%lf\n",y[i]);
    }
    printf("\n");
}

void printMatrix(double L[N][N])
{
    for(int i =0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%lf",L[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    double A[N][N], L[N][N] = {0}, Ltrans[N][N]={0}, y[N],x[N], b[N] = {35,33,6};
    int i,j,k;
    
    printf("Enter the matrix elements: \n");
    enterMatrix(A);
    cholesky(A,L);
    printMatrix(L);
    forwardSubstitution(L,b,y);
    print(y);
    Transpose(L,Ltrans);
    backSubstitution(Ltrans,y,x);
    print(x);
    
    return 0;
}























