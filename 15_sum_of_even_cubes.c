
#include <stdio.h>
int main()
{
    int i;
    int n = 0;
    double sum = 1;
    (void)scanf("%d", &n);
    int b = 1;
    for(i=1; i<=n; i++)
    {
        (void)scanf("%d", &b);
        if (i%2 == 0)
        {
            b = b*b*b;
            sum = sum + b;
        }
    }
    sum = sum-1;
    printf("%lf", sum);
    return 0;
}

