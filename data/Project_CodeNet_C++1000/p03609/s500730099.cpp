#include <cstdio>

int main()
{
    int X,t;
    scanf("%d %d", &X, &t);
if (X < t)
    {
        printf("%d", 0);
    }
else
    printf("%d", X - t);
}