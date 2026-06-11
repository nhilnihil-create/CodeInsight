#include <cstdio>
#define ll long long
#define MOD 1000000007LL

int n;
int a [200000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf ("%d", &a[i]);
    }
    ll ans = 1, last = 1;
    //4 6 8 9 10 12 14 15 16 18 20 21 22
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] >= 2 * last - 1) {
            last += 1;
        }
        ans = ans * last % MOD;
    }
    printf ("%lld\n", ans);
    return 0;
}
