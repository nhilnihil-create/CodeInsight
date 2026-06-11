
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const int MOD = 1e9 + 7;

bool check_XX(string& s, pair<int, int>& result) {
	result = make_pair(-1, -1);
	bool found = false;
	for (int i=0; i<s.size()-1; i++) {
		if (s[i] == s[i+1]) {
			result = make_pair(i+1, i+2);
			found = true;
			break;
		}
	}

	return found;
}

bool check_XYX(string& s, pair<int, int>& result) {
	result = make_pair(-1, -1);
	bool found = false;
	for (int i=0; i<s.size()-2; i++) {
		if (s[i] != s[i+1] && s[i] == s[i+2]) {
			result = make_pair(i+1, i+3);
			found = true;
			break;
		}
	}

	return found;
}

int main() {
	string s;
	cin >> s;

	pair<int, int> result;

	if (!check_XX(s, result)) {
		check_XYX(s, result);
	}

	cout << result.first << " " << result.second << endl;

	return 0;
}