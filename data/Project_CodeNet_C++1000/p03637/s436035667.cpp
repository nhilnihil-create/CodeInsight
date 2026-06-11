
// C - 4-adjacent

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int a;
	int m4 = 0, m2 = 0, other = 0;

	for (int i=0; i<N; i++) {
		cin >> a;
		if (a % 4 == 0) m4++;
		else if (a % 2 == 0) m2++;
		else other++;
	}

	string ans = "Yes";
	if (m2 > 0) {
		if (other + 1 > m4 + 1) ans = "No";
	} else {
		if (other > m4 + 1) ans = "No";
	}

	cout << ans << endl;

	return 0;
}