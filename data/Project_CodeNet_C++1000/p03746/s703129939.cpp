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
#include <random>
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
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

int n, m;
vector<int> vec[100010];
bool bl[100010];
vector<int> ans;

signed main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ans.push_back(1);
	int k = 1;
	bl[1] = true;
	while (1) {
		int x = k;
		for (int i = 0; i < (int)vec[k].size(); i++)if (!bl[vec[k][i]]) {
			k = vec[k][i];
			break;
		}
		if (x == k)break;
		ans.push_back(k);
		bl[k] = true;
	}
	reverse(all(ans));
	k = ans[(int)ans.size() - 1];
	while (1) {
		int x = k;
		for (int i = 0; i < (int)vec[k].size(); i++)if (!bl[vec[k][i]]) {
			k = vec[k][i];
			break;
		}
		if (x == k)break;
		ans.push_back(k);
		bl[k] = true;
	}
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++)cout << ans[i] << " ";
	cout << endl;
}