#include<bits/stdc++.h>
using namespace std;
#define ll long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int sum = 0;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << sum - a[x - 1] + y << endl;
	}
}