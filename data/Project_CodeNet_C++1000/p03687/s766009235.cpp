#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int x = s.length();
	vector<vector<int>> sim(26, vector<int>(x));
	for (int i = 0; i < 26; i++) {
		char y = 'a' + i;
		for (int j = 0; j < x; j++) {
			if (y == s.at(j))sim.at(i).at(j)++;
		}
	}
	int ans = 10000;
	for (int i = 0; i < 26; i++) {
		int res = 0;
		for (int j = 0; j < x; j++) {
			bool flag = true;
			for (int k = 0; k < x - j; k++) {
				if (sim.at(i).at(k) == 0)flag = false;
			}
			if (flag)break;
			for (int k = 0; k < x-1; k++) {
				sim.at(i).at(k) = max(sim.at(i).at(k), sim.at(i).at(k + 1));
			}
			res++;
		}
		ans = min(res, ans);
	}
	cout << ans << endl;
}