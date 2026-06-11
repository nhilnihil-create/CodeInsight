#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = (ll) 1e9 + 7;

const int MAXN = (int) 1e5 + 5;
ll fact[MAXN];
void f() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return 0;
    }
    f();
    if (abs(N-M) == 1) {
        cout << (fact[N] * fact[M])%MOD << endl;
        return 0;
    }
    else {
        cout << 2* (fact[N] * fact[M])%MOD << endl;
        return 0;
    }
}
