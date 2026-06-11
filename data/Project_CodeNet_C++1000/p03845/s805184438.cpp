#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int t[n];
	int total = 0;
	for (int i=0; i<n; i++) {
		cin >> t[i];
		total += t[i];
	}
	int m;
	cin >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		--x;
		cout << total - t[x] + y << '\n';
	}
	
}