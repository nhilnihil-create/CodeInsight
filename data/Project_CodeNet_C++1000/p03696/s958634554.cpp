#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int left = 0;
	int pointer = 0;
	for (int i = 0; i < n; i++) {
		if (0 < pointer) {
			if (s[i] == '(') {
				pointer++;
			}
			else { // s[i] == ')'
				pointer--;
			}
		}
		else { // pointer == 0
			if (s[i] == '(') {
				pointer++;
			}
			else { // s[i] == ')'
				left++;
			}
		}		
	}
	string ans = "";
	while (left--) {
		ans += "(";
	}
	ans += s;
	while (pointer--) {
		ans += ")";
	}
	cout << ans << endl;
    return 0;
}