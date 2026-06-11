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

void solve() {
	vector<int> count(26, 0);
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		count[s[i] - 'a']++;
	}
	for (int i = 0; i < count.size(); i++) {
		if (count[i] % 2 != 0) {
			cout << "No" << endl;
			return ;
		}
	}
	cout << "Yes" << endl;
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