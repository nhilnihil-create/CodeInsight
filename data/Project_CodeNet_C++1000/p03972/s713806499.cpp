/* ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄▄            ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌
▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌   ▄   ▐░▌     ▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌       ▐░▌
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌     ▐░▌▐░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌ ▐░▌░▌ ▐░▌     ▐░▌ ▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌▐░▌ ▐░▌▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌░▌   ▐░▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌     ▐░░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
 ▀            ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀       ▀▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  */

//#pragma optimization_level 3

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <chrono>
#include <ctime>
#include <queue>
#include <math.h>
#include <deque>
#include <stack>
#include <iomanip>
#include <assert.h>
#include <stdio.h>
#include <cstring>
#include <random>

using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pld pair<ld, ld>
#define ti tuple<int, int, int>
#define vi vector <int>
#define vpi vector <pii>
#define vld vector <ld>
#define try tr
#define left left11
#define right right11
#define lb lower_bound
#define ub upper_bound
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define pf push_front
#define sqr(a) ((a) * (a))
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define x first
#define y second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

clock_t START;

inline ld TIME() {
    return (ld) (clock() - START) / CLOCKS_PER_SEC;
}

void SHOW() {
    cout << fixed << setprecision(10);
    cout << TIME() << " SECONDS FROM START\n";
}

ld TL = 2.0; 
int calls = 0;

inline bool IS() {
    if(++calls == 1000) {
        calls = 0;
        if(TL - TIME() < 0.1)
            return true;
    }
    return false;
}

template<typename T1, typename T2>
inline bool amin(T1 &a, T2 b) { if (a > b) { a = b; return true;} return false; }

template<typename T1, typename T2>
inline bool amax(T1 &a, T2 b) { if (a < b) {a = b; return true;} return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &u : v) is >> u;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    for (auto &u : v) os << u << ' ';
    return os;
}

int hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937}, mod = hash_mod[rnd() % 4];
int hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];

int binpow(int x, int p) {
    int res = 1;
    while(p) {
        if(p % 2)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
}

const int N = 1e6 + 7, NS = 2e3 + 7, lg = 20, sq = 550, inf = 2e9 + 7, SM = 1e2 + 7;
const ld eps = 1e-9;
void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    vpi v;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v.pb({p, 0});
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        v.pb({q, 1});
    }
    int x = n + 1, y = m + 1;
    sort(all(v));
    for (auto u : v) {
        if(u.y) {
            ans += x * u.x;
            y--;
        }
        else {
            ans += y * u.x;
            x--;
        }
    }
    cout << ans;
}   

signed main() {
    fast
    solve();
}