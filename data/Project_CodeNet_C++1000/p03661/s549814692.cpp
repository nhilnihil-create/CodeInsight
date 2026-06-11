#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n;
ll a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), a[i] += a[i - 1];
    }
    long long mn = 1e18;
    for (int i = 1; i < n; i++) {
        mn = min(mn, abs(a[i] - (a[n] - a[i])));
    }
    printf("%lld\n", mn);
    return 0;
}