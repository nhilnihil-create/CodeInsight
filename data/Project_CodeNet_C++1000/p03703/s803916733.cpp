#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919810364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
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
	while (y > 0) {
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
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int BIT[200010];
int n, k;
vector<P> vec;
int ans;

int sum(int i) {
	int res = 0;
	while (0 < i) {
		res += BIT[i];
		i -= i & -i;
	}
	return res;
}

void add(int i) {
	while (i <= n + 1) {
		BIT[i]++;
		i += i & -i;
	}
}

signed main() {
	cin >> n >> k;
	vec.push_back({ 0,1 });
	int cnt = 0;
	for (int i = 2; i <= n + 1; i++) {
		int a; cin >> a;
		cnt += a - k;
		vec.push_back({ cnt,i });
	}
	sort(all(vec));
	for (int i = 0; i < (int)vec.size(); i++) {
		ans += sum(vec[i].second);
		add(vec[i].second);
	}
	cout << ans << endl;
}