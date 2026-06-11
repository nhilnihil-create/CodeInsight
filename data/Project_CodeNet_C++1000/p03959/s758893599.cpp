#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <time.h>

//     MLE,TLE魔
//↓↓↓↓↓↓↓↓↓↓↓↓
#define int long long
//↑↑↑↑↑↑↑↑↑↑↑↑
//     MLE,TLE魔
#define endre getchar();getchar();return 0
#define moder 1000000007
#define inf 5000000000000000000
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
struct edge { int to, cost; };
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


int n, a[100005], b[100005];
int t[100005];
signed main() {
	cin >> n;
	REP(i, n + 1) {
		cin >> a[i];
	}
	REP(i, n + 1) {
		cin >> b[i];
	}
	int ans = 1;
	REP(i, n + 1) {
		if (a[i] != a[i - 1] && a[i] > b[i]) {
			cout << 0 << endl;
			endre;
		}
		if (b[i] != b[i + 1] && b[i] > a[i]) {
			cout << 0 << endl;
			endre;
		}
		if (a[i] != a[i - 1] || b[i] != b[i + 1])continue;
		ans *= min(a[i], b[i]);
		ans %= moder;
	}
	cout << ans << endl;
	endre;
}
