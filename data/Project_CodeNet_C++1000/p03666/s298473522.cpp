#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c, d;

signed main () { 
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
    for (long long m = 0; m < n; ++m) {
        if ((n - 1 - m) * c - m * d <= b - a && b - a <= (n - 1 - m) * d - m * c) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}
