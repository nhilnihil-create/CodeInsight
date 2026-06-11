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

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1)*x;
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
int comb(int x, int y) {
	return kai(x)*mod_pow(kai(x - y), moder - 2, moder) % moder*mod_pow(kai(y), moder - 2, moder) % moder;
}
/*--------Library Zone!--------*/

int n, a[114514], sum;
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % ((1 + n)*n / 2)) {
		cout << "NO" << endl;
		endre;
	}
	int k = sum / ((1 + n)*n / 2);
	//N個取り除く回数
	int cnt = 0;
	rep(i, n) {
		int x = a[i], y = a[(i + 1) % n];
		if (y - x > k) {
			cout << "NO" << endl;
			endre;
		}
		if ((k - (y - x)) % n) {
			cout << "NO" << endl;
			endre;
		}
		cnt += (k - (y - x)) / n;
	}
	if (cnt != k)cout << "NO" << endl;
	else cout << "YES" << endl;
	endre;
}