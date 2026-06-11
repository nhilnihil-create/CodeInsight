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
					/*多倍長整数/cpp_intで宣言
					#include <boost/multiprecision/cpp_int.hpp>
					using namespace boost::multiprecision;
					*/

#pragma gcc target ("avx2")
#pragma gcc optimization ("o3")
#pragma gcc optimization ("unroll-loops")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a)//少数出力
#define printdbd(a) printf("%.16lf\n", a)//少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str())//string出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2.0)//等差数列の和、初項,末項,項数
#define pb push_back
#define priq priority_queue
#define rpriq priq<int, vector<int>, greater<int>>
#define deg_to_rad(deg) (((deg)/360.0)*2.0*PI)
#define rad_to_deg(rad) (((rad)/2.0/PI)*360.0)
#define Please return
#define AC 0
#define addf(T) [](T a, T b){return (a + b);}
#define minf(T) [](T a, T b){return min(a, b);}
#define maxf(T) [](T a, T b){return max(a, b);}
#define nof(T) [](T a){return a;}


using ll = long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1000000007;
const long double PI = acos(-1.0L);

using namespace std;

void scans(string& str) {
	char c;
	str = "";
	scanf("%c", &c);
	if (c == '\n')scanf("%c", &c);
	while (c != '\n' && c != -1) {
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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll number1, ll number2) {
	return number1 / gcd(number1, number2) * number2;
}

ll LSB(ll n) { return (n & (-n)); }

/*-----------------------------------------ここからコード-----------------------------------------*/


//遅延セグ木/0-indexed/非再帰/(大きさ, 単位元)で初期化
template<typename T>
struct segtree {
	//木を配列であらわしたもの
	vector<T> seg, lazy;
	//木の1/2の大きさ
	int siz;
	//単位元/
	const T unit;
	//比較関数の型
	using F = function<T(T, T)>;
	//マージする関数
	const F f;
	//lazy を子に伝播させるときの関数の型 伝播されるlazy, 伝播先のlazy
	using F2 = function<T(T, T)>;
	//lazy を子に伝播させるときの関数
	const F2 f2;


	/*
	//n の大きさ, a (単位元) で segtree を初期化する
	segtree(int n, const T a, const F f) : unit(a), f(f) {
		siz = 1;
		while (siz < n)siz <<= 1;
		seg.assign(2 * siz - 1, unit);
		--siz;
	}
	*/

	//n の大きさ, a (単位元), マージ関数, lazy を子に伝播させるときの関数の型(伝播されるlazy, 伝播先のlazy) で segtree を初期化する
	segtree(int n, const T a, const F f, const F2 f2) : unit(a), f(f), f2(f2) {
		siz = 1;
		while (siz < n)siz <<= 1;
		seg.assign(2 * siz - 1, unit);
		lazy.assign(2 * siz - 1, unit);
		--siz;
	}

	//k (0-indexed) 番目に t を代入
	void set(int k, const T& t) {
		seg[k + siz] = t;
	}

	//f によって木を構築
	void build() {
		for (int i = siz - 1; i >= 0; --i) seg[i] = f(seg[i * 2 + 1], seg[i * 2 + 2]);
	}

	//子に伝播
	void eval(int k) {
		if (lazy[k] != unit) {
			seg[k] = f(seg[k], lazy[k]);
			if (k < siz) {
				lazy[(k << 1) + 1] = f2(lazy[k], lazy[(k << 1) + 1]);
				lazy[(k << 1) + 2] = f2(lazy[k], lazy[(k << 1) + 2]);
			}
		}
		lazy[k] = unit;
	}

	//i 番目の要素を返す
	T operator[](const int i) {
		return seg[i + siz];
	}

	//k 番目の値を a で更新
	void update(int k, T a) {
		k += siz;
		//必要であればここを変える
		seg[k] = a;
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
	}

	//[l, r) の値を a で更新
	void update(int l, int r, T a) {
		/*
		k += siz;
		//必要であればここを変える
		seg[k] = a;
		while (k > 0) {
			k = ((k - 1) >> 1);
			seg[k] = f(seg[k * 2 + 1], seg[k * 2 + 2]);
		}
		*/
	}

	//[a, b) について f した結果を返す
	T query(int a, int b) {
		T l = unit, r = unit;
		for (a += siz, b += siz; a < b; a >>= 1, b >>= 1) {
			if (!(a & 1))l = f(l, seg[a++]);
			if (!(b & 1))r = f(seg[--b], r);
		}
		return f(l, r);
	}



	//[start, end) について、[l, r) を調べながら k 番目が check を満たすか二分探索 最後が true なら left, false なら right fの逆演算
	template<typename C>
	int find(const int start, const int end, int l, int r, int k, const C check, T& checknum, const bool b, const function<T(T, T)> revf) {
		//cerr << checknum << '\n';
		//範囲外またはそこがすでに満たさないとき
		//cerr << k << ',' << checknum << '\n';
		if (start <= l && r <= end && !check(seg[k], checknum)) {
			checknum = revf(checknum, seg[k]);
			return -1;
		}
		if ((r <= start || l >= end)) {
			return -1;
		}
		//既に葉
		if (k >= siz) {
			return k - siz;
		}
		int res;
		if (b) {
			//左側を調べる
			res = find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
			//左側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
		}
		else {
			//右側を調べる
			res = find< C >(start, end, ((l + r) >> 1), r, (k << 1) + 2, check, checknum, b, revf);
			//右側が適してたらそれが答え
			if (res != -1)return (res);
			return find< C >(start, end, l, ((l + r) >> 1), (k << 1) + 1, check, checknum, b, revf);
		}
	}

	template<typename C>
	int find_left(int start, int end, const C check, T& checknum, function<T(T, T)> revf) {
		return find< C >(start, end, 0, siz + 1, 0, check, checknum, true, revf);
	}

	template<typename C>
	int find_right(int start, int end, const C check, T& checknum, function<T(T, T)> revf) {
		return find< C >(start, end, 0, siz + 1, 0, check, checknum, false, revf);
	}

};

//ワーシャルフロイド
void WarshallFloyd(int n, vector<vector<int>>& d) {
	rep(i, n) {//経由する頂点
		rep(j, n) {//始点
			rep(k, n) {//終点
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	int a, b, c;
	vector<vector<int>> graph(n, vector<int>(n));
	vector<tuple<int, int, int>> ab(m);
	rep(i, n)fill(all(graph[i]), INF);
	rep(i, n)graph[i][i] = 0;
	rep(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		--a; --b;
		graph[a][b] = graph[b][a] = c;
		ab[i] = { a, b, c };
	}
	WarshallFloyd(n, graph);
	int ans = 0;
	bool flag = false;
	rep(i, m) {
		flag = true;
		rep(j, n) {
			for (int k = j + 1; k < n; ++k) {
				if (graph[j][k] == graph[j][get<0>(ab[i])] + get<2>(ab[i]) + graph[get<1>(ab[i])][k] || graph[j][k] == graph[k][get<0>(ab[i])] + get<2>(ab[i]) + graph[get<1>(ab[i])][j])flag = false;
			}
		}
		if (flag)++ans;
	}
	printf("%d\n", ans);

	Please AC;
}
