#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i < n; ++i)
#define repe(i, n) for(int i=0; i <= n; ++i)
#define repr(i, n) for(int i=n-1; i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define PI 3.14159265359
using namespace std;
template <class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b<a) {a = b; return 1;} return 0;}
template <class T> using V=vector<T>;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1000000007;
const ll MAX = 510000;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
vector<int> Eratosthenes(const int N)
{
    vector<bool> is_prime(N+1, true);
    vector<int> P;
    for(int i=2; i<=N; i++) {
        if (is_prime[i]) {
            for(int j=2*i; j<=N; j+=i) {
                is_prime[j] = false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}
 
int main() {
    ll n,T;
    cin >> n >> T;
    vector<ll> t(n);
    ll res = 0;
    rep(i,n) {
        cin >> t[i];
    }
    rep(i,n) {
        if (i>0) {
            if (abs(t[i]-t[i-1])<T) {
                res += abs(t[i]-t[i-1]);
            } else {
                res += T;
            }
        }
    }
    res += T;
    cout << res << "\n";
}