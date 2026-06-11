#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<ll,ll>
#define keta(a)  fixed << setprecision(a)
#define ld long double
constexpr auto INF = (ll)1000000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
struct edge { ll to, cost; };

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// mod. m での a の逆元 a^{-1} を計算するよ！
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


//aCbをmod.mで割った余りを求める
ll int c(ll int a, ll int b, ll int m) {
	ll int ans = 1;
	for (ll int i = 0; i < b; i++) {
		ans *= a - i;
		ans %= m;
	}
	for (ll int i = 1; i <= b; i++) {
		ans *= modinv(i, m);
		ans %= m;
	}
	return ans;
}
struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}
	int size(int a) {
		return par[root(a)];
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
whei(edge) G(101);
void dijksra(ll s,vector<ll>&d) {  //d[i]はSからの最短距離(初期化はINF)
	priority_queue<Pint, vector<Pint>, greater<Pint>> que;
	que.push(Pint(0, s));
	d[s] = 0;  
	while (!que.empty()) {
		Pint P = que.top();
		que.pop();
		int v = P.second;
		for (auto x : G[v]) {
			if (d[x.to] > d[v] + x.cost) {
				d[x.to] = d[v] + x.cost;
				que.push(Pint(d[x.to], x.to));
			}
		}
	}
}

int main(){
	int n,p;
	cin >> n >> p;
	hei(int) a(n);
	rep(i, 0, n) {
		cin >> a[i];
		a[i] %= 2;
	}
	ll dp[51][2] = { 0 };
	dp[0][0] = 1;
	rep(i, 0, n) {
		rep(j, 0, 2) {
			dp[i + 1][(j + a[i]) % 2] += dp[i][j];
			dp[i + 1][j] += dp[i][j];
		}
	}
	cout << dp[n][p] << endl;
	return 0;
}
