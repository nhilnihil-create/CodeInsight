#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, x, ans;

// a => short, b => long
void cal(LL a, LL b) {
    if (b % a == 0) {
        ans += (b - a) / a * 2 * a + a;
        return; 
    } else {
        ans += b / a * 2 * a;
        cal(b % a, a);
    }
}

int main() {
    scanf("%lld%lld", &n, &x);
    ans += n;
    cal(min(x, n - x), max(x, n - x));
    printf("%lld\n", ans);
    return 0;
}