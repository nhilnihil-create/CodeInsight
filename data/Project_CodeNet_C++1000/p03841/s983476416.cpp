#include <bits/stdc++.h>
#define int long long
#define double long double
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

int n, a[505], b[505 * 505];
//x番目について、y番目の数字
int x, lo[505], up[505];
P p[505];
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		p[i] = { a[i] - 1,i + 1 };
		b[a[i] - 1] = i + 1;
		lo[i + 1] = i;
		up[i + 1] = n - i - 1;
	}
	sort(p, p + n);
	rep(i, n) {
		while (lo[p[i].second]) {
			if (b[x]) {
				if (lo[b[x]]) {
					cout << "No" << endl;
					endre;
				}
				x++;
				continue;
			}
			b[x] = p[i].second;
			x++;
			lo[p[i].second]--;
		}
	}
	x = n * n - 1;
	for (int i = n - 1; i >= 0; i--) {
		while (up[p[i].second]) {
			if (b[x]) {
				if (up[b[x]]) {
					cout << "No" << endl;
					endre;
				}
				x--;
				continue;
			}
			b[x] = p[i].second;
			x--;
			up[p[i].second]--;
		}
	}
	cout << "Yes" << endl;
	rep(i, n*n) {
		cout << b[i] << " ";
	}
	cout << endl;
	endre;
}
