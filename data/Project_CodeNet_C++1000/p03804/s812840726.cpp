#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int l1, l2;
	cin >> l1 >> l2;
	vector<string> g(l1);
	rep(i,l1) cin >> g[i];
	vector<string> v(l2);
	rep(i,l2) cin >> v[i];
	rep(i,l1) {
		rep(j,l1) {
			if (i + l2 - 1 >= l1 || j + l2 - 1 >= l1) continue;
			bool b = true;
			rep(x,l2) {
				rep(y,l2) {
					if (g[i+x][j+y] != v[x][y]) b = false;
				}
			}
			if (b) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}