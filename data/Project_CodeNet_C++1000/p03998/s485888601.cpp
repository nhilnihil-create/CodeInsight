/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>
#include <regex>
#include <functional>
#include <complex>
#include <list>
#include <cassert>
#include <iomanip>
#include <set>
#include <stack>
#include <bitset>

////多倍長整数, cpp_intで宣言
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

//#pragma gcc target ("avx2")
//#pragma gcc optimization ("Ofast")
//#pragma gcc optimization ("unroll-loops")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a) //少数出力
#define printLdb(a) printf("%.50Lf\n", a) //少数出力
#define printdbd(a) printf("%.16lf\n", a) //少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str()) //string出力
#define all(x) (x).begin(), (x).end()
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d)) /*(a, b) から (c, d) のマンハッタン距離 */
#define inf numeric_limits<double>::infinity();
#define linf numeric_limits<long double>::infinity()

using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1e9 + 7;
constexpr long double eps = 1e-6;
const long double PI = acosl(-1.0L);

using namespace std;

void scans(string & str) {
	char c;
	str = "";
	scanf("%c", &c);
	if (c == '\n')scanf("%c", &c);
	while (c != '\n' && c != -1 && c != ' ') {
		str += c;
		scanf("%c", &c);
	}
}

void scanc(char& str) {
	char c;
	scanf("%c", &c);
	if (c == -1)return;
	while (c == '\n') {
		scanf("%c", &c);
	}
	str = c;
}

double acot(double x) {
	return PI / 2 - atan(x);
}

ll LSB(ll n) { return (n & (-n)); }

/*-----------------------------------------ここからコード-----------------------------------------*/

/*
* @title unionfind
* @docs kyopro/docs/unionfind.md
*/

//0-indexed
struct unionfind {
	vector<ll> par, siz;

	unionfind(ll n) : par(n), siz(n) {
		for (ll i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	void init(ll n) {
		par.resize(n);
		siz.resize(n);
		for (ll i = 0; i < n; ++i) {
			//全部根で初期化
			par[i] = i;
			//サイズは1
			siz[i] = 1;
		}
	}

	//根を返す
	ll find(ll a) {
		return par[a] == a ? a : par[a] = find(par[a]);
	}

	//くっつける。元から同じだったらfalseを返す
	bool unite(ll a, ll b) {
		ll x = find(a), y = find(b);
		if (x == y)return false;
		else if (siz[x] < siz[y]) {
			par[x] = y;
			siz[y] += siz[x];
		}
		else if (siz[x] > siz[y]) {
			par[y] = x;
			siz[x] += siz[y];
		}
		else {
			par[x] = y;
			siz[y] += siz[x];
		}
		return true;
	}

	//同じ集合か判定する
	bool same(ll a, ll b) {
		return find(a) == find(b);
	}

	//サイズを返す
	ll size(ll a) {
		return siz[find(a)];
	}

	//同じ集合に属す葉を纏めて返す
	vector<ll> leaf(ll a) {
		vector<ll> x;
		ll n = par.size();
		for (ll i = 0; i < n; ++i)if (same(a, i))x.push_back(i);
		return x;
	}

};


int main() {

	string a, b, c, ans = "";
	scans(a);
	scans(b);
	scans(c);
	reverse(all(a));
	reverse(all(b));
	reverse(all(c));
	int turn = 0;
	while (true) {
		if (turn == 0) {
			if (a.empty()) {
				puts("A");
				return 0;
			}
			turn = a.back() - 'a';
			a.pop_back();
		}
		else if (turn == 1) {
			if (b.empty()) {
				puts("B");
				return 0;
			}
			turn = b.back() - 'a';
			b.pop_back();
		}
		else {
			if (c.empty()) {
				puts("C");
				return 0;
			}
			turn = c.back() - 'a';
			c.pop_back();
		}
	}

	Please AC;
}