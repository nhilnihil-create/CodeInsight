#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

signed main() {
	int n, p; cin >> n >> p;
	int o = 0, e = 0;
	rep(i, n) {
		int a; cin >> a;
		if (a & 1)o++; else e++;
	}
	if (!o) {
		if(p)cout << 0 << endl;
		else cout << (1ll << e) << endl;
	}
	else cout << (1ll << (e + o - 1)) << endl;
}