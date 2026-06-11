#include<bits/stdc++.h>
#define FastIO1 ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define si(n) scanf("%d",&n)
#define sl(n) scanf_s("%lld",&n)
#define nsl(n) scanf_s("%lld\n",&n)
#define nsi(n) scanf("%d\n",&n)
#define repz(i,a,n) for(int i=a;i<n;i++)
#define repo(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define stlfor(it,stl) for(auto &it:stl)
#define pb push_back
#define mp make_pair
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char* s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	template<typename T>
	bool read(T& x) {
		int n = read(str), bf;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};
using namespace FastIO;
using namespace std;
typedef long long ll;
typedef long double db;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll qpow(ll a, ll b,ll mod) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a)%mod ; b >>= 1; a = (a * a)%mod; }return ans; }
ll qmul(ll a, ll b, ll mod) { ll ans = 0; while (b > 0) { if (b & 1)ans = (ans + a) % mod; b >>= 1; a = (a + a) % mod; }return ans; }
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
string hack = { "NB" };
int hack1 = 0;
int hack2 = hack1 + 666;
const int maxn = 2e5 + 5;
int  x[maxn], y[maxn];
int findp(int x,int *pre) { return pre[x] == x?pre[x] : pre[x] = findp(pre[x],pre); }
void init(int n,int *pre) {
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
	}
}
void unite(int x, int y,int *pre)
{
	int p1 = findp(x, pre);
	int p2 = findp(y, pre);
	if (p1 != p2) {
		pre[p1] = p2;
	}
}
bool same(int x, int y,int *pre) { return findp(x,pre) == findp(y,pre); }
void NB() {
	map<pair<int, int>, int> mapp;
	int n, k, l;
	FastIO::read(n); FastIO::read(k); FastIO::read(l);
	init(n, x);
	init(n, y);
	while (k--) {
		int X, Y;
		FastIO::read(X); FastIO::read(Y);
		unite(X, Y, x);
	}
	while (l--) {
		int X, Y;
		FastIO::read(X); FastIO::read(Y);
		unite(X, Y, y);
	}
	repo(i, 1, n) {
		findp(i, x);
		findp(i, y);
	}
	pair<int, int>temp;
	repo(i, 1, n) {
		temp = make_pair(x[i], y[i]);
		mapp[temp]++;
	}
	repo(i, 1, n) {
		temp = make_pair(x[i], y[i]);
		cout << mapp[temp] << " ";
		if (i == n)cout << '\n';
	}
}
int main() {
	FastIO1
	NB();
	return 0;
}