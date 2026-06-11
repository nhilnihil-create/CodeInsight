#include<stdio.h>

int main()
{
    int tc, i, sum =0;
    scanf("%d", &tc);
    for(i=1; i<=tc; i++)
        sum+=i;
    printf("%d\n", sum);

}
