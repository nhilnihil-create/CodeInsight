// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

ll n;

vector<int> calc(ll x, int lim) {
    vector<int> ret;

    if (x == 1) {
        return ret;
    }

    if (x & 1) {
        ret = calc(x - 1, lim - 1);
        ret.insert(ret.begin(), lim);
    }
    else {
        ret = calc(x / 2, lim - 1);
        ret.pb(lim);
    }

    return ret;
}

void solve() {
    scanf("%lld", &n);
    vector<int> vv = calc(n + 1, 100);

    for (int i = 1; i <= 100; ++i) {
        vv.pb(i);
    }

    printf("%d\n", vv.size());

    for (int i = 0; i < vv.size(); ++i) {
        printf("%d", vv[i]);
        printf(i + 1 == vv.size() ? "\n" : " ");
    }
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}