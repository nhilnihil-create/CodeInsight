#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int maxi = 0, between, ans = 100000;
	cin >> s;

	for (char i = 'a'; i <= 'z' ; i++) {
		between = 0;
		maxi = 0;
		for (int j = 0; j< s.size(); j++) {
			if (s[j] == i) {
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