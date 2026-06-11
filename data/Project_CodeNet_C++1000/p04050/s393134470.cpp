#include <bits/stdc++.h>
using namespace std;
const int M = 101;

int n, m, odd, a[M];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a[i];
		if(a[i] % 2) ++odd;
	}
	if(odd > 2) cout << "Impossible", exit(0);
	for(int i = 0; i < m; i++) if(a[i] % 2) swap(a[i], a[0]);
	for(int i = 1; i < m; i++) if(a[i] % 2) swap(a[i], a[m-1]);
	for(int i = 0; i < m; i++) cout << a[i] << ' ';
	vector<int> res;
	if(m == 1) {
		if(a[0] > 1) res.push_back(a[0]-1);
		res.push_back(1);
	}
	else for(int i = 0; i < m; i++) {
		if(!i) {
			if(a[i] > 1) res.push_back(a[i]-1);
		}
		else if(i == m-1) res.push_back(a[i]+1);
		else res.push_back(a[i]);
	}
	cout << endl << res.size() << endl;
	for(int x: res) cout << x << ' ';
}
