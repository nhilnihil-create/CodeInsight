#include <cstdio>

int n;

int main()
{
    scanf("%d", &n);
    while (n > 0) {
        if (n % 10 == 9) {
            printf("Yes\n");
            return 0;
        } else {
            n /= 10;
        }
    }

    printf("No\n");
    return 0;
}