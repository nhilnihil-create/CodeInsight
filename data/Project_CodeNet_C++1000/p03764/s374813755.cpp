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
//もう二度とつかわん//
//    ↓ ↓　↓　　 //
#define ll long long
//    ↑　↑　↑    //
//フェルマー方程式の恨み//
#define rep(i,n) for(int i=0;i<n;i++)
#define ggr getchar(); getchar();return 0;
using namespace std;
//素数判定
bool prime(ll n) {
	if (n == 1)return false;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
ll a[114514], b[114514];
signed main() {
	ll n, m;
	cin >> n >> m;
	ll memo1 = 0, memo2 = 0;
	rep(i, n)cin >> a[i];
	rep(i, m)cin >> b[i];
	for (int i = 0; i < n; i++) {
		if ((n - 1 - 2 * i) >= 0)memo1 += (a[n - 1 - i] - a[i])*(n - 1 - 2 * i);
		memo1 %= 1000000007;
	}
	for (int i = 0; i < m; i++) {
		if ((m - 1 - 2 * i) >= 0)memo2 += (b[m - 1 - i] - b[i])*(m - 1 - 2 * i);
		memo2 %= 1000000007;
	}
	cout << memo1 * memo2 % 1000000007 << endl;
	ggr
}
