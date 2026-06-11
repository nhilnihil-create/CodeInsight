#include <stdio.h>
#define MAX_N 100001

int p[MAX_N];

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            cnt++;
            if (i < n && p[i + 1] == i + 1) i++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}