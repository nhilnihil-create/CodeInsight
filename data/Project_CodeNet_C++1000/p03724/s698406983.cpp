#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int n, m; cin >> n >> m;
	map<int, int> ab;
	REP(i, m) {
		int a, b; cin >> a >> b;
		ab[a]++;
		ab[b]++;
	}
	bool ok = true;
	for (auto x : ab)
		if (x.second % 2)
			ok = false;
	cout << ((ok == true) ? "YES" : "NO") << '\n';
    return 0;
}
