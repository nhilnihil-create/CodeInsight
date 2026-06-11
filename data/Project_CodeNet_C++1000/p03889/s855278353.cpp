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
#define int long long
#define endre getchar();getchar();return 0
#define moder 1000000007
#define inf 1000000000000000000
#define rep(i,n) for(int i=0;i<n;i++)
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
	if (x < y)swap(x, y);
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
map<int, int> factor(int m) {
	map<int, int>res;
	for (int i = 2; i*i <= m; i++) {
		while (m%i == 0) {
			res[i]++;
			m /= i;
		}
	}
	if (m != 1)res[m]++;
	return res;
}

/*--------Library Zone!--------*/

string s, t;
signed main() {
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	rep(i, t.size()) {
		if (t[i] == 'b')t[i] = 'd';
		else if (t[i] == 'd')t[i] = 'b';
		if (t[i] == 'p')t[i] = 'q';
		else if (t[i] == 'q')t[i] = 'p';
	}
	if (s == t)puts("Yes");
	else puts("No");
	endre;
}