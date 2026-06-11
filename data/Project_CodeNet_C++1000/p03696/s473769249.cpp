#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int left_need = 0;
	int right_need = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') right_need++;
		else { // s[i] == ')'
			if (right_need == 0) {
				left_need++;
			}
			else { // 1 <= right_need
				right_need--;
			}

		}
	}
	string ans = "";
	for (int i = 0; i < left_need; i++) {
		ans += '(';
	}
	ans += s;
	for (int i = 0; i < right_need; i++) {
		ans += ')';
	}
	cout << ans << endl;
	return 0;
}