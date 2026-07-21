#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
    return x*x*x - 2*x - 5;
}

int main()
{
    float a, b, c, Te;
    int i=1;

    file: printf("Enter the a: ");
    scanf("%f", &a);
    printf("Enter the b: ");
    scanf("%f", &b);
    printf("Enter the Tolerance Error (Te): ");
    scanf("%f", &Te);

    if(f(a)*f(b) > 0)
    {
        printf("The guesses are not correct\n");
        goto file;
    }

    printf("\n");
    printf("Step\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");
    printf("-------------------------------------------------------\n");

    do
    {
        c = (a*f(b) - b*f(a)) / (f(b) - f(a));

        printf("%d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",
                i, a, b, c, f(a), f(b), f(c));

        if(f(a)*f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
        i++;

    } while(fabs(f(c)) > Te);

    printf("-------------------------------------------------------\n");
    printf("\nThe approximation root (c) is: %.4f\n", c);
    printf("f(c) = %.4f\n", f(c));

    return 0;
}
