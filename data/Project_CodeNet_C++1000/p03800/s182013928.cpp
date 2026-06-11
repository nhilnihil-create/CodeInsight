#include <bits/stdc++.h>
#define int long long
//#define double long double
#define endre getchar();getchar();return 0
#define moder (int)(1e9+7)
#define inf (int)(5*1e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int kai(int x) {
	if (x == 0)return 1;
	return (kai(x - 1)*x) % moder;
}
int comb(int x, int y) {
	return kai(x)*mod_pow(kai(x - y), moder - 2, moder) % moder*mod_pow(kai(y), moder - 2, moder) % moder;
}
struct edge { int from, to, cost; };
int dx[5] = { 0,1,0,-1 }, dy[5] = { 1,0,-1,0 };
map<int, int>factor(int x) {
	map<int, int>res;
	for (int i = 2; i*i <= x; i++) {
		while (x%i == 0) {
			x /= i;
			res[i]++;
		}
	}
	if (x != 1)res[x]++;
	return res;
}
/*--------Library Zone!--------*/

int n;
string s;
signed main() {
	cin >> n >> s;
	rep(i, 4) {
		char c[114514];
		if (i & 1)c[0] = 'W';
		else c[0] = 'S';
		if (i & 2)c[1] = 'W';
		else c[1] = 'S';
		for (int j = 1; j < n - 1; j++) {
			if ((c[j] == 'S'&&s[j] == 'o'&&c[j - 1] == 'S') || (c[j] == 'S'&&s[j] == 'x'&&c[j - 1] == 'W') || (c[j] == 'W'&&s[j] == 'o'&&c[j - 1] == 'W') || (c[j] == 'W'&&s[j] == 'x'&&c[j - 1] == 'S')) {
				c[j + 1] = 'S';
			}
			else {
				c[j + 1] = 'W';
			}
		}
		if ((c[n - 1] == 'S'&&s[n - 1] == 'o'&&c[n - 2] == c[0]) || (c[n - 1] == 'S'&&s[n - 1] == 'x'&&c[n - 2] != c[0]) || (c[n - 1] == 'W'&&s[n - 1] == 'o'&&c[n - 2] != c[0]) || (c[n - 1] == 'W'&&s[n - 1] == 'x'&&c[n - 2] == c[0])) {
			if ((c[0] == 'S'&&s[0] == 'o'&&c[1] == c[n - 1]) || (c[0] == 'S'&&s[0] == 'x'&&c[1] != c[n - 1]) || (c[0] == 'W'&&s[0] == 'o'&&c[1] != c[n - 1]) || (c[0] == 'W'&&s[0] == 'x'&&c[1] == c[n - 1])) {
				rep(j, n)cout << c[j];
				cout << endl;
				endre;
			}
		}
	}
	cout << -1 << endl;
	endre;
}
