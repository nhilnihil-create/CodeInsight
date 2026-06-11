#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const int MOD = (int)1e+9 + 7;

signed main(){
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(m);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for(int j = 0; j < m; ++j) {
		cin >> y[j];
	}
	int a, b;
	a = b = 0;
	for(int i = 0; i < n; ++i) {
		a += ((x[i + 1] - x[i]) % MOD * ((i + 1) * (n - i - 1)) % MOD) % MOD;
		a %=  MOD;
	}
	for(int i = 0; i < m; ++i) {
		b += ((y[i + 1] - y[i]) % MOD * ((i + 1) * (m - i - 1)) % MOD) % MOD;
		b %=  MOD;
	}
	cout << (a * b) % MOD << endl;
	return 0;
}
