#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	bool ok = false;
	for (int i = 1; i < b; i++) {
		if ((a * i) % b == c) ok = true;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}