#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
int n;
vector<vi> g;
int G(int v, int p) {
	int val = 0;
	for(auto i : g[v]) {
		if(i == p) continue;
		val ^= 1+G(i, v);
	}
	return val;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	cout << (G(1, 1)?"Alice":"Bob");
}
