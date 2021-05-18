#include <stdio.h>
int main()
{
    int n = 0;
    int i;
    double sum = 1;
    (void)scanf("%d", &n);
    int b = 1;
    for(i=1; i<=n; i++)
    {
        (void)scanf("%d", &b);
        sum = sum + b;
    }
    sum = sum-1;
    sum = sum/n;
    printf("%lf", sum);
    return 0;
}
