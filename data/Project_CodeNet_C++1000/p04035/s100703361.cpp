#include <bits/stdc++.h>
using namespace std;
#define N 100001
int a[N], n, m;
int main() {
    scanf("%d%d", &n, &m);
    int add = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
        if (a[i] + a[i + 1] >= m) add = i;
    if (add) {
        puts("Possible");
        for (int i = 1; i < add; i++) printf("%d\n", i);
        for (int i = n - 1; i > add; i--) printf("%d\n", i);
        printf("%d\n", add);
    } else
        puts("Impossible");
    return 0;
}