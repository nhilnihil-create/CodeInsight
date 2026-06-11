#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n, 1), red(n);
	red[0] = 1;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cnt[a]--, cnt[b]++;
		if (red[a]) red[b] = 1;
		if (cnt[a] == 0) red[a] = 0;
	}
	int ans = 0;
	rep(i, n) if (red[i]) ans++;
	cout << ans << endl;
	return 0;
}