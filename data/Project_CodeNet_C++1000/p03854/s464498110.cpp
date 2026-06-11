#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
using ll = long long; 
using ld = long double;
#define endl "\n"
//#define int long long
#define all(V) V.begin(),V.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
const int MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const int inf = 1 << 25;
constexpr long double pi = 3.141592653589793238462643383279;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll fact_mod(ll n, ll mod) {
    ll f = 1; for (int i = 2; i <= n; i++) f = f * (i % mod) % mod;
    return f;
}
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll keta(ll n) {
    if (n == 0) return 1;
    ll count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {
    ll sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll mch(ll n) {
    if (n == 1) return 1;
    else return n * mch(n - 1);
}
ll powmod(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % mod;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}
ll inv_mod(ll a, ll mod) { //逆元
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}
bool is_prime(const unsigned n) {
    switch (n) {
    case 0: // fall-through
    case 1: return false;
    case 2: // fall-through
    case 3: return true;
    } // n > 3 が保証された
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (unsigned i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return false; // (6の倍数)-1
        if (n % (i + 2) == 0) return false; // (6の倍数)+1
    }
    return true;
}

//宣言とか
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
/*signed*/int main(void) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    bool ok = true;
    while (s.size()!=0) {
        if (s.find("maerd") == 0) {
            s = s.erase(0, 5);
        }
        else if (s.find("esare") == 0) {
            s = s.erase(0, 5);
        }
        else if (s.find("remaerd") == 0) {
            s = s.erase(0, 7);
        }
        else if (s.find("resare") == 0) {
            s = s.erase(0, 6);
        }
        else {
            ok = false;
            break;
        }
    }
    (ok ? puts("YES") : puts("NO"));
    return 0;
}