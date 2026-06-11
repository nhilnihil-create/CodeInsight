#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	string a = "CODEFESTIVAL2016";
	string b;
	cin >> b;
	int ans = 0;
	rep(i, a.size()) {
		if (a[i] != b[i]) {
			ans ++;
		}
	}
	cout << ans << endl;
}