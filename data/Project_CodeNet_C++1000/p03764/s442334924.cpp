#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, mod = 1e9+7;
vector<ll> x, y;

ll f(vector<ll> &v){
	int p = v.size()-1;
	vector<ll> a(p, 0), b(p, 0);
	a[0] = v[0];
	b[0] = v[0];
	for(int i=1; i<p; ++i){
		b[i] = b[i-1] + (i+1)*v[i];
		b[i] %= mod;
		a[i] = a[i-1] + b[i];
		a[i] %= mod;
	}
//	for(int i=0; i<p; ++i)
//		cout << i << " " << a[i] << " " << b[i] << "\n";
	return a[p-1];
}

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> m;
	x.resize(n);
	y.resize(m);
	for(int i=0; i<n; ++i) cin >> x[i];
	for(int i=0; i<m; ++i) cin >> y[i];
	for(int i=0; i<n-1; ++i) x[i] = x[i+1] - x[i];
	for(int i=0; i<m-1; ++i) y[i] = y[i+1] - y[i];
	cout << f(x) * f(y) % mod << "\n";
}