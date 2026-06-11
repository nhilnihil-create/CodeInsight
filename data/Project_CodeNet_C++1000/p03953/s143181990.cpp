#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17;
ll n, m, k;
vector<ll> a, d, p;
void apply(vector<ll> a, vector<ll> &b) {
	vector<ll> res(a.size());
	for(int i = 0; i < a.size(); i++) res[i] = b[a[i]];
	b = res;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(int i = 1; i < n; i++) d.push_back(a[i]-a[i-1]);
	cin >> m >> k;
	p.resize(n-1);
	iota(all(p), 0);
	auto r = p;
	for(int t, i = 0; i < m; i++) {
		cin >> t;
		swap(p[t-1], p[t-2]);
	}
	while(k) {
		if(k&1) apply(p, r);
		apply(p, p), k>>=1;
	}
	apply(r, d);
	cout << a[0] << '\n';
	for(auto i : d) cout << (a[0] += i) << "\n";
}
