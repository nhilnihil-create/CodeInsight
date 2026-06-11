#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int colors[10];
int main() {
	int n;
	cin >> n;
	rep(i, n) {
		int a; cin >> a;
		a /= 400;
		if (a>=8) colors[8]++;
		else colors[a] = 1;
	}
	int ans = 0;
	rep(i, 8) ans += colors[i];
	if (ans == 0) cout << 1 << ' ' << colors[8] << endl;
	else cout << ans << " " << ans + colors[8] << endl;
	return 0;
}