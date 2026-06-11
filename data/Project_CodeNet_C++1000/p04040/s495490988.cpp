#pragma region include
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <cstdio>
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define MOD 1000000007
#define INF 1000000000
#define LLINF 4000000000000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#pragma endregion

//#define __DEBUG__
#ifdef  __DEBUG__
#define dump(x) cerr << #x << " = " << (x) << " [" << __LINE__ << ":" << __FUNCTION__ << "] " << endl;
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& v) {
    os << "{";
    REP(i, (int)v.size()) { os << v[i] << (i < v.size() - 1 ? ", " : ""); }
    os << "}";
    return os;
}
// pair出力
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
// map出力
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "{";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set 出力
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
#endif

//powMod
ll powMod(ll k, ll n, ll mod) {
    ll x = 1;
    while (n > 0) {
        if (n & 1) {
            x = x * k % mod;
        }
        k = k * k % mod;
        n >>= 1;
    }
    return x;
}

// comb (前計算O(NlogMOD) クエリO(1))
const int MAX_N = 200000;
ll FACT[MAX_N + 1], IFACT[MAX_N + 1];

ll comb(ll n, ll r) {
    if (n < 0 || r < 0 || r > n)return 0;
    if (r > n / 2) r = n - r;
    return FACT[n] * IFACT[n - r] % MOD * IFACT[r] % MOD;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int H, W, A, B; cin >> H >> W >> A >> B;
    ll ans = 0;
    // 前計算(mainに)
    FACT[0] = IFACT[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        FACT[i] = FACT[i - 1] * i % MOD;
        IFACT[i] = powMod(FACT[i], MOD - 2, MOD);
    }
    while (A < H && B < W) {
        ans += comb(B + H - A - 1, B) * comb(A + W - B - 1, A) % MOD;
        ans %= MOD;
        A++; B++;
    }
    cout << ans << endl;
    getchar(); getchar();
}