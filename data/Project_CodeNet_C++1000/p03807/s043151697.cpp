#include <bits/stdc++.h>
using namespace std;

int n, a[100010];
long long s;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), s += a[i];
    }
    printf("%s\n", s & 1 ? "NO" : "YES");
    return 0;
}