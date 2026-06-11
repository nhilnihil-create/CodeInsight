#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

typedef long long ll;

int ap[200005][30];
string anc[200005];

bool comp(const string &s, const string &t) {
	if (s == "-1") return true;
	if (t == "-1") return false;
	if (s.length() != t.length()) return s.length() > t.length();
	return s >= t;
}

int main() {
	string s; cin >> s;
	for (int c = 0; c <= 'z' - 'a'; ++c) ap[s.length()][c] = -1;
	for (int i = (int)s.length() - 1; i >= 0; --i) {
		for (int c = 0; c <= 'z' - 'a'; ++c) {
			ap[i][c] = ('a' + c == s[i]) ? i : ap[i + 1][c];
		}
	}

	deque<int> que;
	for (int i = 0; i <= (int)s.length(); ++i) anc[i] = "-1";
	for (int c = 0; c <= 'z' - 'a'; ++c) {
		if (ap[0][c] == -1) {
			cout << (char)('a' + c) << endl;
			return 0;
		}
		que.push_back(ap[0][c]);
		anc[ap[0][c]] = "";
	}
	string ans = "-1";
	while (!que.empty()) {
		int pos = que.front(); que.pop_front();
		string t = anc[pos] + s[pos];
		for (int c = 0; c <= 'z' - 'a'; ++c) {
			if (ap[pos + 1][c] == -1) {
				if (comp(ans, (t + (char)('a' + c)))) ans = (t + (char)('a' + c));
				continue;
			}
			if (comp(t, anc[ap[pos + 1][c]])) continue;
			que.push_back(ap[pos + 1][c]);
			anc[ap[pos + 1][c]] = t;
		}
	}
	cout << ans << endl;
	return 0;
}