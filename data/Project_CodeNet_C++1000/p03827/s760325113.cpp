#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int n;
	string s;
	cin >> n >> s;
	int x = 0, ans = 0;
	rep(i, n) {
		ans = max(ans, x);
		if (s[i] == 'I') x++;
		else x--;
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}