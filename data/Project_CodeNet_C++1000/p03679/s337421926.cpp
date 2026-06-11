#include <cstdio>

int main()
{
    long long X, A, B;
    scanf("%lld %lld %lld", &X, &A, &B);
    if (B - A <= 0)
    {
        printf("delicious\n");
        return 0;
    }
    else
    {
        if (X >= B - A)
        {
            printf("safe\n");
            return 0;
        }
        else
        {
            printf("dangerous\n");
            return 0;
        }
    }
    return 0;
}
