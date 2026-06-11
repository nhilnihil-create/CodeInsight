#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

bool check(string cur) {
	set<char> ss;
	for (char x : cur)ss.insert(x);
	return (ss.size() != cur.size());
}

void solve() {
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i + 1 < s.length() && check(s.substr(i, 2))) {
			cout << i + 1 << ' ' << i + 2 << endl;
			return ;
		}
		if (i + 2 < s.length() && check(s.substr(i, 3))) {
			cout << i + 1 << ' ' << i + 3 << endl;
			return ;
		}
	}
	cout << -1 << ' ' << -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t; cin >> t;
	// while (t--)
	solve();

}