#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }

const ll MOD = 1e9 + 7;

int main() {
    FAST_IO();
    int N, M; cin >> N >> M;
    vector<ll> x(N+1), y(M+1);
    repp(i, 1, N) cin >> x[i];
    repp(j, 1, M) cin >> y[j];
    ll Si = 0, Sj = 0;
    repp(i, 1, N - 1) {
        Si += 1LL * i * (N - i) % MOD * (x[i+1] - x[i]) % MOD;
        Si %= MOD;
    }
    repp(j, 1, M - 1) {
        Sj += 1LL * j * (M - j) % MOD * (y[j+1] - y[j]) % MOD;
        Sj %= MOD;
    }
    cout << Si * Sj % MOD << endl;
    return 0;
}