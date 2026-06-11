#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, a, b, c, d;

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d), n--;
    for (ll i = 0; i <= n; i++) {
        ll l1 = a + i * c, r1 = a + i * d;
        ll l2 = b + (n - i) * c, r2 = b + (n - i) * d;
        if (max(l1, l2) <= min(r1, r2)) printf("YES\n"), exit(0);
    }
    printf("NO\n");
    return 0;
}