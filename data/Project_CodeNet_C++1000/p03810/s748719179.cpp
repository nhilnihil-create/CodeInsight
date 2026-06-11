#include <cstdio>

#define MAXN 100000

int n, v[MAXN];

inline int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

inline bool solve() {
    if (n == 1)
        return 0;
    int pare = 0;
    for (int i = 0; i < n; i++)
        pare += 1 - v[i] % 2;
    if (pare < n - 1)
        return pare % 2;
    if ((n - 2) % 2 == 0)
        return 1;
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 1 && v[i] != 1)
            v[i]--;
    int a = v[0];
    for (int i = 1; i < n; i++)
        a = gcd(v[i], a);
    if (a == 1)
        return 0;
    for (int i = 0; i < n; i++)
        v[i] /= a;
    return 1 - solve();
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    if (solve())
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}
