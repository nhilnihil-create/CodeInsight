
// B - ss

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

bool is_even_string(string S) {
	if (S.size() % 2 != 0) return false;

	bool result = true;
	for (int i=0; i < S.size() / 2; i++) {
		if (S[i] != S[i + (S.size() / 2)]) result = false;
	}

	return result;
}

int main() {
	string S;
	cin >> S;

	int ans;
	while(1) {
		S.pop_back();
		if (is_even_string(S)) {
			ans = S.size();
			break;
		}
	}

	cout << ans << endl;

	return 0;
}