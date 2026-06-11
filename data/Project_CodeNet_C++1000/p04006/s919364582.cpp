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
const ld PI = 3.1415926535897932;
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
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
void vout(vl V) {
	for (ll i = 0; i < (ll)V.size(); i++) cout << V[i] << " ";
	cout << endl;
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//bitSearch, bitList, nod, gcdlcm, isPrime, primeFactorize, Npow, divisor, modinv, dfs, bfs, eratos//
//dijkstra, WarshallFloyd, BellmanFord, UnionFind, COM, digitDP ,RMQ//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z, R, Q;
ll MOD = 1000000007; ll INF = 1LL << 62; ll ans = 0; ll z = 0, o = 1;
vl flag, color; vll path; vl A; vl dp; vl Ans;
//***********//
/* RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    set(int i, T x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
    find_rightest(a,b,x): [a,b) で x以下の要素を持つ最右位置を求める。O(log(n))
    find_leftest(a,b,x): [a,b) で x以下の要素を持つ最左位置を求める。O(log(n))
*/
template <typename T>
struct RMQ {
    const T e = numeric_limits<T>::max();
    ll n;
    vector<T> dat;
    RMQ(ll n_) : n(), dat(n_ * 4, e) {
        ll x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    void set(ll i, T x) { dat[i + n - 1] = x; }
    void build() {
        for (ll k = n - 2; k >= 0; k--) dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
    void update(ll i, T x) {
        i += n - 1; dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    // the minimum element of [a,b)
    T query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) return e;
        else if (a <= l && r <= b) return dat[k];
        else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T find_rightest(ll a, ll b, ll x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    T find_leftest(ll a, ll b, ll x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    T find_rightest_sub(ll a, ll b, ll x, ll k, ll l, ll r) {
        // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn a-1
        if (dat[k] > x || r <= a || b <= l) return a - 1;
        // 自分が葉ならその位置をreturn
        else if (k >= n - 1) return (k - (n - 1));
        else {
            ll vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            // 右の部分木を見て a-1 以外ならreturn
            if (vr != a - 1) return vr;
            // 左の部分木を見て値をreturn
            else return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
        }
    }
    T find_leftest_sub(ll a, ll b, ll x, ll k, ll l, ll r) {
        // 自分の値がxより大きい or [a,b)が[l,r)の範囲外ならreturn b
        if (dat[k] > x || r <= a || b <= l) return b;
        // 自分が葉ならその位置をreturn
        else if (k >= n - 1) return (k - (n - 1));
        else {
            ll vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            // 左の部分木を見て b 以外ならreturn
            if (vl != b) return vl;
            // 右の部分木を見て値をreturn
            else return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
        }
    }
};
int main() {
	cin >> N >> X;
	vpll A(N);
    RMQ<ll> S(N);
	for (i = 0; i < N; i++) {
        ll a;
		cin >> a;
        S.update(i, a);
	}
    vl cost(N);
    ans = INF;
	//魔法をi回使用した際にスライムjを取得する時の最小コストを取得する
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
            if (j - i >= 0) {
                cost[i] += S.query(j - i, j+1);
            }
            else {
                cost[i] += min(S.query(N+j-i,N),S.query(0, j+1));
            }
            //debug(cost[i]);
		}
        cost[i] += i * X;
        //debug(i, cost[i]);
        ans = min(cost[i], ans);
	}
    cout << ans;
}