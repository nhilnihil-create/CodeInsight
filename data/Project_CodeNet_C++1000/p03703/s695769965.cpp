#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
using namespace std; using ll = long long; using ld = long double;  using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
using vs = vector<string>; using tll = tuple<ll, ll, ll>; using vtll = vector<tll>;
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
void in() {}
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop, bitSearch, bitList, nod//
//gcdlcm, isPrime, eratos, primeFactorize, Npow, combination, divisor, modinv,  digitDP//
//dfs, bfs, dijkstra, WarshallFloyd, BellmanFord, UnionFind, Kruskal ,RMQ, LCA//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag; vll path, D;
//***********//
/* BIT: RAQ対応BIT
    BITはインデックスが1から始まっているので要注意！！！！
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    計算量は全て O(logn)
*/
template <typename T>
struct BIT {
    ll n; vector<T> bit[2];
    BIT(ll n_) { init(n_); }
    void init(ll n_) {
        n = n_ + 1;
        for (ll p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(ll p, ll i, T x) {
        for (ll idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(ll l, ll r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    T sum_sub(ll p, ll i) {
        T s(0);
        for (ll idx = i; idx > 0; idx -= (idx & -idx)) s += bit[p][idx];
        return s;
    }
    T sum(ll i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
    T query(ll l, ll r) { return sum(r - 1) - sum(l - 1); }
    ll lower_bound(T w) { // a_1 + a_2 + ... + a_x >= w となるような最小の x を求める(ただし a_i >= 0)
        if (w <= 0) return 0;
        else {
            ll x = 0, r = 1;
            while (r < n) r = r << 1;
            for (ll len = r; len > 0; len = len >> 1) { // 長さlenは1段下るごとに半分に
                if (x + len < n && bit[x + len] < w) { // 採用するとき
                    w -= bit[x + len];
                    x += len;
                }
            }
            return x + 1;
        }
    }
};
int main() {
    cin >> N >> K;
    vl A(N);
    vl sum(N+1);
    for (i = 0; i < N; i++) {
        cin >> A[i];
        sum[i + 1] = sum[i] + A[i];
    }
    vpll B(N+1);
    for (i = 0; i <= N; i++) {
        B[i] = mp(sum[i] - i * K,i);
    }
    sort(B.begin(), B.end());
    vl Z(N + 1);
    for (i = 0; i <= N; i++) {
        Z[B[i].second] = i+1;
    }
    //debug(Z);
    BIT<ll> T(N + 1);
    for (i = 0; i <= N; i++) {
        ans += T.sum(Z[i]);
        T.add(Z[i], Z[i]+1, 1);
    }
    cout << ans;
}