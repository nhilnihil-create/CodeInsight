#include <bits/stdc++.h>
using namespace std;
using P = vector<int>;
using ll = long long;

const int N = 100010;

int n;
int m;
ll k;
ll a[N];

P& operator*=(P& a, const P& b) {
    P c(a.size());

    for (int i = 0; i < int(a.size()); i++) {
        c[i] = a[b[i]];
    }
    a = c;

    return a;
}

P power(P a, ll b) {
    P r(a.size());
    iota(r.begin(), r.end(), 0);

    for (; b > 0; b >>= 1) {
        if (b & 1) {
            r *= a;
        }

        a *= a;
    }

    return r;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    scanf("%d %lld", &m, &k);
    P p(n - 1);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        x--;
        swap(p[x - 1], p[x]);
    }

    P r = power(p, k);

    ll cur = a[0];
    for (int i = 0; i < n - 1; i++) {
        printf("%lld\n", cur);
        int j = r[i];
        cur += a[j + 1] - a[j];
    }
    printf("%lld\n", cur);
}
