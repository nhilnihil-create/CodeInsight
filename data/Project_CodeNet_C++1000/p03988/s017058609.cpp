#pragma GCC optimize("O2,unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using vi = vector<int>;
using ll = long long;
const int maxn = 1<<20;
map<int, int> dd;
int n, mx = 0, mn;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int d, i = 1; i <= n; i++) {
		cin >> d;
		dd[d]++;
		mx = max(mx, d);
	}
	for(int i = mx; i >= mx-i; i--) {
		int m = 1 + (i != mx-i);
		if(dd[i] < m) return cout << "Impossible", 0;
		dd[i] -= m;
	}
	
	for(auto i : dd) {
		int t = i.first - 1;
		if(mx-t <= t) i.second = 0;
		if(i.second) return cout << "Impossible", 0;
	}
	cout << "Possible";
}
