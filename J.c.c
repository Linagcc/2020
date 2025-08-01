#include<stdio.h>
#include<math.h>

#define SIZE 3
#define ERROR 1e-9
#define Max_Iterations 100

void printMatrix(double A[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
        {
            printf("%.4lf  ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void maxOffDiagonal(double A[SIZE][SIZE], int *p, int *q)
{
    for(int i=0;i<SIZE;i++)
    {
        double max = 0.0;
        for(int j=i+1;j<SIZE;j++)
        {   
            if(fabs(A[i][j])> max)
            {
                max = fabs(A[j][i]);
                *p = i;
                *q = j;
            }
        }
    }
}

void eigenVectors(double eigenVector[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            eigenVector[i][j] = (i==j? 1:0);
        }
    }
}

void jacobi(double A[SIZE][SIZE], double eigenVector[SIZE][SIZE])
{ 
    eigenVectors(eigenVector); // have to create the eigenvector = I
    int p , q;  // define as integer
    int iterations;
    for(iterations = 0 ; iterations< Max_Iterations; iterations++)
    {
        maxOffDiagonal(A,&p,&q);  //pass the arguments by derefferencing
        if(fabs(A[p][q]) < ERROR) break;

        double theta = 0.5*atan2(2*A[p][q], A[q][q]-A[p][p]);
        double sinT = sin(theta);
        double cosT = cos(theta);

        double temp1 = A[p][p];
        A[p][p] = cosT*cosT*temp1 - 2*cosT*sinT*A[p][q] + sinT*sinT*A[q][q];
        A[q][q] = sinT*sinT*temp1 + 2*cosT*sinT*A[p][q] + cosT*cosT*A[q][q];
        A[p][q] = A[q][p] = 0;

        for(int i=0;i<SIZE;i++)
        {
                if(i != p && i != q)
                {
                    double temp2 = A[i][p];
                    A[i][p] = cosT*temp2 - sinT*A[i][q];
                    A[p][i] = A[i][p];

                    A[i][q] = sinT*temp2 + cosT*A[i][q];
                    A[q][i] = A[i][q];     
                }
        }

        
        for(int i=0;i<SIZE;i++)
        {
            double temp3 = eigenVector[i][p];
            eigenVector[i][p] = cosT*temp3 - sinT*eigenVector[i][q]; 
            eigenVector[i][q] = sinT*temp3 + cosT*eigenVector[i][q];            
        }
    }
}

int main()
{
    double eigenVector[SIZE][SIZE] = {0};
    double A[SIZE][SIZE] = 
    {
        {4, -2, 2},
        {-2, 3, -1},
        {2, -1, 1}
    };

    printf("Original matrix is: \n");
    printMatrix(A);

    jacobi(A,eigenVector);

    printf("Eigen values are: \n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%.4lf\n",A[i][i]);
    }
    printf("\n");

    printf("Eigen vectors are \n");
    printMatrix(eigenVector);
}

