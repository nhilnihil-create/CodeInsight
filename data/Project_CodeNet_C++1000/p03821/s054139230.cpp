#include <bits/stdc++.h>

using namespace std;

#define K 600001

int n;
long long a[K], b[K];

int main() {
    scanf("%d", &n);
    long long ret = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[n - i + 1], &b[n - i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        a[i] += ret;
        long long bar = a[i] % b[i];
        long long val = (b[i] - bar) % b[i];
        ret += val;
    }

    printf("%lld\n", ret);
}