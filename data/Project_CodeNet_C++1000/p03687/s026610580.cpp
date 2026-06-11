#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int maxi = 0, between, ans = 100000;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		between = 0;
		maxi = 0;
		for (int j = 0; j< s.size(); j++) {
			if (s[j] == s[i]) {
				maxi = max(maxi, between);
				between = 0;
			}
			else between++;
		}
		maxi = max(maxi, between);
		ans = min(maxi, ans);
	}
	cout << ans << endl;
}