#include<stdio.h>
#include<math.h>

#define f(x) (cos(x)-x)
#define tolarance 0.005
#define max_steps 3

int Significant_digits(double error)
{
    return (int)(2-log10(2*error));
}

int main()
{

    double x1,x2,x3,fx1,fx2,Rel_error, Abs_error;
    int step = 1,digits = 0;
    printf("Give 2 guesses: \n");
    scanf("%lf %lf",&x1,&x2);

    printf("Step\t\tX\t\tError\n");

    do
    {
        fx1 = f(x1);
        fx2 = f(x2);

        if(fx2- fx1 == 0)
        {
            printf("Cant calculate due to the zero devision error.\n");
            break;
        }else
        {
            x3 = x2 - (fx2*(x2-x1))/(fx2-fx1);
            Rel_error = ((x3-x2)/x3)*100;
            Abs_error = fabs(Rel_error);

            printf("%d\t\t%.4lf\t\t%.4lf\n",step,x3,Abs_error);

            x1=x2;
            x2=x3;
            digits = Significant_digits(Abs_error);
            step++;
        } 
    }while(step<=max_steps);

    printf("Final approximation: %.4lf\n",x3);
    printf("Relative error: %.4lf\n",Rel_error);
    printf("Significant digits: %d",digits);
}