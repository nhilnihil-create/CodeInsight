#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();

	vector<int> foo(n + 1, 0);
	for (int i = 0; i < n; i++) {
		foo[i + 1] = foo[i] + (s[i] == 'A' ? 1 : 2);
	}

	vector<int> bar(n + 1, 0);
	for (int i = 0; i < m; i++) {
		bar[i + 1] = bar[i] + (t[i] == 'A' ? 1 : 2);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; c--;

		int x = (foo[b] - foo[a]) % 3;
		int y = (bar[d] - bar[c]) % 3;
		cout << (x == y ? "YES" : "NO") << "\n";
	}
	return 0;
}