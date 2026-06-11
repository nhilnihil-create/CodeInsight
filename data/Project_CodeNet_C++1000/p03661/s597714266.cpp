#include <cstdio>
#include <vector>
#include <algorithm>

#define LINF 1000000000000000

typedef long long ll;

using namespace std;

int main() {
    ll n, ans = LINF;
    scanf("%lld", &n);
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", a.begin() + i);
        a.at(i) += a.at(i - 1);
    }
    for (ll i = 1; i < n; ++i) ans = min(ans, abs(a.at(n) - 2 * a.at(i)));
    printf("%lld\n", ans);
    return 0;
}
