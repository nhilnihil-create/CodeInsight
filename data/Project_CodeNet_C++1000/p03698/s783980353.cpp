
// B - Varied

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	sort(S.begin(), S.end());

	string ans = "yes";
	for (int i=0; i<S.size()-1; i++) {
		if (S[i] == S[i+1]) ans = "no";
	}

	cout << ans << endl;

	return 0;
}