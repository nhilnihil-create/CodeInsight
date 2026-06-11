#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
int main() {
    int n, m; scanf("%d%d", &n, &m);
    if(abs(n - m) > 1) { 
        printf("0\n");
        return 0;
    }
    // 同数の場合 N! * M! * 2
    // 1個違いの場合 N! * M!
    ll n_kai = 1;
    ll m_kai = 1;
    for(int i = 1; i <= n; i++) n_kai = (n_kai * i) % MOD;
    for(int i = 1; i <= m; i++) m_kai = (m_kai * i) % MOD;

    ll ans = 1;
    if(n == m) {
        ans = (n_kai * m_kai * 2) % MOD;
    }
    else {
        ans = (n_kai * m_kai) % MOD;
    }
    printf("%lld\n", ans % MOD);
    return 0;
}