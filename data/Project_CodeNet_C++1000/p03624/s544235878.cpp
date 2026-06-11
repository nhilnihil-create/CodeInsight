
// B - Not Found

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	string ans = "None";

	for (char c = 'a'; c <= 'z'; c++) {
		if (S.find(c) == string::npos) {
			ans = c;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}