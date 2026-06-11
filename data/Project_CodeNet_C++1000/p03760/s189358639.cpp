#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = (int)s1.size();
	int m = (int)s2.size();
	int i = 0; 
	int j = 0;
	string ans = "";
	while (i < n || j < m) {
		if (i == n) {
			for (int k = j; k < m; ++k) {
				ans += s2[k];
			}
			break;
		}
		if (j == m) {
			for (int k = i; k < n; ++k) {
				ans += s1[k];
			}
			break;
		}
		ans += s1[i];
		ans += s2[j];
		++i;
		++j;
	}
	cout << ans;
}

















