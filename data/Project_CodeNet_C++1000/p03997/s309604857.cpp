#include<stdio.h>

int main()
{
    int ub,lb,h, c;
    scanf("%d %d %d", &ub, &lb, &h);

    double area = (ub + lb)*h/2;
    c = (int) area;

    printf("%d\n", c);

    return 0;
}
