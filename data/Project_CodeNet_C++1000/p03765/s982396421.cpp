#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct string_table {
	string s;
	int n, LOG_N;
	vector<vector<int>> type;
	string_table(string& s) {
		this->s = s;
		n = s.length();
		int tmp = n; LOG_N = 1;
		while (tmp)
			tmp >>= 1, ++LOG_N;
		type.resize(n, vector<int>(LOG_N));
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'A') type[i][0] = 0;
			else type[i][0] = 1;
		}
		for (int j = 1; j < LOG_N; ++j) {
			for (int i = 0; i < n; ++i) {
				int l = type[i][j - 1], r = type[min(n - 1, i + (1 << (j - 1)))][j - 1];
				if (l == 2) type[i][j] = r;
				else if (r == 2) type[i][j] = l;
				else if (l == 0) type[i][j] = r + 1;
				else if (l == 1) type[i][j] = (r + 2) % 3;
			}
		}
	}
	int get_type(int a, int b) {
		--a;
		int res = 2;
		for (int j = LOG_N - 1; j >= 0; --j) {
			if ((b - a) & (1 << j)) {
				int right = type[a][j];
				if (res == 2) res = right;
				else if (right == 2) res = res;
				else if (res == 0) res = right + 1;
				else if (res == 1) res = (right + 2) % 3;
				a += (1 << j);
			}
		}
		return res;
	}
};

int main() {
	string s;  cin >> s;
	string_table sts(s);
	string t; cin >> t;
	string_table stt(t);
	int q; cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (sts.get_type(a, b) == stt.get_type(c, d))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}