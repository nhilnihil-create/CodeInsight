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
using namespace std;
#define pie 3.141592653589793238462643383279
#define int long long
#define mod 1000000007
#define INF 1145141919364364
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

int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1)*x%mod;
}

int mod_pow(int x, int y, int mood) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%mood;
		x = x * x%mood;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}

int N, W, w, v;
vector<int> vec[4];
int cnt;
int ans;
int coun;

signed main() {
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		if (i == 0)cnt = w;
		vec[w - cnt].push_back(v);
	}
	for (int i = 0; i < 4; i++) {
		sort(all(vec[i]));
		reverse(all(vec[i]));
	}
	for (int i = 0; i <= max((int)0,min(W / (cnt + 3),(int)vec[3].size())); i++) {
		W -= i * (cnt + 3);
		for (int j = 0; j <= max((int)0,min(W / (cnt + 2), (int)vec[2].size())); j++) {
			W -= j * (cnt + 2);
			for (int k = 0; k <= max((int)0,min(W / (cnt + 1),(int)vec[1].size())); k++) {
				W -= k * (cnt + 1);
				for (int l = 0; l <= max((int)0,min(W / cnt, (int)vec[0].size())); l++) {
					coun = 0;
					for (int ii = 0; ii < i; ii++)coun += vec[3][ii];
					for (int jj = 0; jj < j; jj++)coun += vec[2][jj];
					for (int kk = 0; kk < k; kk++)coun += vec[1][kk];
					for (int ll = 0; ll < l; ll++)coun += vec[0][ll];
					ans = max(ans, coun);
				}
				W += k * (cnt + 1);
			}
			W += j * (cnt + 2);
		}
		W += i * (cnt + 3);
	}
	cout << ans << endl;
}