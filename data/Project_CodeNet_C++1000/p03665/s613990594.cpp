#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

const int MAX = 210000;
ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理O(n)
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

// 二項係数計算O(1)
ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {

    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    int odd = 0, even = 0;
    REP(i, n) {
        cin >> a[i];
        if (a[i] % 2) odd++;
        else even++;
    }
    
    COMinit();

    int odd_k = 1, even_k = 0;
    ll sum_odd = 0, sum_even = 0;
    while (true) {
        if (even_k == 50) break;
        sum_odd += COM(odd, odd_k);
        sum_even += COM(odd, even_k);
        odd_k += 2;
        even_k += 2;
    }

    cerr << sum_odd << " " << sum_even << endl;

    if (p == 1) {
        cout << (ll)pow(2, even) * sum_odd << endl;
    } else {
        cout << (ll)pow(2, even) * sum_even << endl;
    }


    //cout << ans << endl;
    return 0;
}