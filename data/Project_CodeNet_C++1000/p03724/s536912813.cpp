#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	//vector<vector<int>>path(m, vector<int>(2));
	vector<int>a(n+1,0);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a.at(x)++;
		a.at(y)++;
	}
	for (int i = 2; i <= n; i++) {
		if (a.at(i) % 2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}