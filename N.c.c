#include<stdio.h>
#include<math.h>

#define f(x) ((3*x*x*x) - (2*x*x) +1)
#define fd(x) ((9*x*x) -(4*x))
#define tolarance 0.005

int main()
{
    double x1,x2,fx1,fdx1,error;
    int step =1;
    int max_steps = 20;

    printf("Enter a guess: \n");
    scanf("%lf",&x1);

    printf("\tstep\t\tx1\t\terror\n");

    do
    {
        fx1 = f(x1);
        fdx1 = fd(x1);

        if(fdx1 == 0)
        {
            printf("Invalid calculation. Root not found\n");
            break;
        }else
        {
            x2 = x1 - (fx1/fdx1);

            error = fabs((x2-x1)/x2)*100;
            printf("%d\t\t%.4lf\t\t%.4lf\n",step,x1,error);
            step++;
            x1 = x2;

            if(step>max_steps)
            {
                break;
            }
        }
    }while(error>tolarance);

    printf("Root is: %.4lf",x2);
}