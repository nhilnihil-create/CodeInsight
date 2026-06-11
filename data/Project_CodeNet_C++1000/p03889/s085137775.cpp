#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(int i=0;i<n;i++)
#define int long long
#define ggr getchar();getchar();return 0;
#define prique priority_queue
#define mod 1000000007
#define inf 1e15
#define key 1e9
using namespace std;
typedef pair<int, int>P;
void yes() { cout << "Yay!" << endl; }
void no() { cout << ":(" << endl; }
template<class T> inline void chmax(T& a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T& a, T b) {
	a = std::min(a, b);
}
bool prime(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0)cnt++;
	}
	if (cnt != 1)return false;
	else return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y)* mod_pow(kai(y, y), mod - 2, mod) % mod;
}
struct edge { int to, cost; };
int par[114514], rrank[114514];//親、木の深さ
void init(int n) {
	rep(i, n) {
		par[i] = i;
		rrank[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else return par[x] = find(par[x]);
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rrank[x] < rrank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rrank[x] == rrank[y])rrank[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}
string s;
signed main() {
	cin >> s;
	int n = s.size();
	if (n % 2 == 1)puts("No");
	else {
		int cnt = 0;
		rep(i, n / 2) {
			if (s[i] == 'p' && s[n - 1 - i] == 'q')cnt++;
			else if (s[i] == 'q' && s[n - 1 - i] == 'p')cnt++;
			else if (s[i] == 'd' && s[n - 1 - i] == 'b')cnt++;
			else if (s[i] == 'b' && s[n - 1 - i] == 'd')cnt++;
		}
		if (cnt == n / 2)puts("Yes");
		else puts("No");
	}
	ggr
}

