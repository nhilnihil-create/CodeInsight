#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <stack>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

void solve() {
	string s; cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.length();) {
		if (s.substr(i, 6) == "resare") {
			i += 6; continue;

		}
		else if (s.substr(i, 5) == "esare") {
			i += 5;
			continue;
		}

		else if (s.substr(i, 5) == "maerd") {
			i += 5;
			continue;
		}
		else if (s.substr(i, 7) == "remaerd") {
			i += 7; continue;

		}


		if (i == s.length()) {cout << "YES"; return ;}
		cout << "NO"; return ;

	}
	cout << "YES"; return ;
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