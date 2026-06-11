#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> s(N);
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		s[i] = (c == 'x');
	}
	if (N % 3 == 0) {
		string ans(N, 'S');
		for (int i = 1; i < N - 1; i++) {
			if (ans[i] == 'S' && ans[i - 1] == 'S' && s[i] == 1) ans[i + 1] = 'W';
			if (ans[i] == 'S' && ans[i - 1] == 'W' && s[i] == 0) ans[i + 1] = 'W';
			if (ans[i] == 'W' && ans[i - 1] == 'S' && s[i] == 0) ans[i + 1] = 'W';
			if (ans[i] == 'W' && ans[i - 1] == 'W' && s[i] == 1) ans[i + 1] = 'W';
		}
		bool OK = true;
		if (ans[N - 1] == 'S' && s[N - 1] == 0 && ans[N - 2] != ans[0]) OK = false;
		if (ans[N - 1] == 'S' && s[N - 1] == 1 && ans[N - 2] == ans[0]) OK = false;
		if (ans[N - 1] == 'W' && s[N - 1] == 0 && ans[N - 2] == ans[0]) OK = false;
		if (ans[N - 1] == 'W' && s[N - 1] == 1 && ans[N - 2] != ans[0]) OK = false;
		if (s[0] == 0 && ans[N - 1] == 'W') OK = false;
		if (s[0] == 1 && ans[N - 1] == 'S') OK = false;
		if (OK) cout << ans << endl;
		else cout << -1 << endl;
		return 0;
	}
	else {
		int l = (N - 1) / 3;
		vector<int> ans(N);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < l; j++) {
				ans[i] ^= (s[(i + 3 * j) % N] ^ s[(i + 1 + 3 * j) % N]);
			}
			ans[i] ^= s[(i + 3 * l) % N];
		}
		for (int i = 2; i < N; i++) {
			if (N % 3 == 1) ans[i] = s[(i - 1 + N) % N] ^ ans[i - 1] ^ ans[i - 2];
			else ans[i] = s[(N + i - 3) % N] ^ ans[i - 1] ^ ans[i - 2];
		}
		if (N % 3 == 1) {
			for (int a : ans) cout << (a ? "W" : "S");
			cout << endl;
		}
		else {
			for (int i = 2; i < N; i++) cout << (ans[i] ? "W" : "S");
			cout << (ans[0] ? "W" : "S") << (ans[1] ? "W" : "S") << endl;
		}
	}
}