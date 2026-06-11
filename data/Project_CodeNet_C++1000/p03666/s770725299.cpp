#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 5e5 + 10;
typedef long long ll;
ll n, a, b, c, d;

int main() {
    cin >> n >> a >> b >> c >> d;
    n--;
    rep(x, 0, n)
        if (b >= a - 1ll * x * d + (n - x) * c && b <= a - 1ll * x * c + (n - x) * d)
            return puts("YES"), 0;
    puts("NO");
    return 0;
}
