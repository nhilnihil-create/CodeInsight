#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int x, t;
	cin >> x >> t;
	int ans = x - t;
	if (ans < 0) ans = 0;
	cout << ans << endl;
	return 0;
}
