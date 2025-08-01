#include<stdio.h>
#include<math.h>

#define f(x) (32*exp(0.09*x)-39)

double Abs_Rel_Error(double x3, double prev_x3)
{
    return fabs(((x3-prev_x3)/x3)*100);
}

int Significant_Digits(double error)
{
    return (int)(2-log10(2*error));
}

int main()
{
    double x1,x2,x3,fx1,fx2,fx3,abs_error;
    int steps,Digits;
    int max_steps = 20;
    double tolarance = 0.005;

    printf("Give 2 guesses: \n");
    scanf("%lf %lf",&x1,&x2);

    fx1 = f(x1);
    fx2 = f(x2);

    if(fx1*fx2 > 0)
    {
        printf("Invalid guesses\n");
    }else
    {
        printf("Step\t\tx1\t\t\tx2\t\t\tx3\t\tf(x3)\t\tAbs_error\t\tSign_digits\n");

        for(steps=1;steps<=max_steps;steps++)
        {
            x3 = (x1+x2)/2;
            fx3 = f(x3);

            if(steps == 1)
            {
                printf("%d\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\tN/A\t\tN/A\n",steps,x1,x2,x3,fx3);
            }else
            {
                abs_error = Abs_Rel_Error(x3,x2);
                Digits = Significant_Digits(abs_error);
                printf("%d\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\t%.6lf\t\t%d\n",steps,x1,x2,x3,fx3,abs_error,Digits);

                if(abs_error<tolarance)
                {
                    printf("Absolute error is less than Tolarance: \n");
                    break;
                }
            }

            steps++;

            if(fx1*fx3 < 0)
            {
                x2 = x3;
            }else
            {
                x1= x3;
            }
        }
    }
    printf("Approximation root is: %.6lf\n",x3);
    printf("Absolute error is: %.6lf",abs_error);
    printf("Significant digits count is: %d",Digits);
    return 0;
}