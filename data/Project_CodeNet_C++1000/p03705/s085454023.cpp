#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
ll n, a, b;

int main() {
    cin >> n >> a >> b;
    if (a > b || (a != b && n < 2)) return puts("0"), 0;
    printf("%lld\n", (n - 1) * b + a - ((n - 1) * a + b) + 1);
    return 0;
}
