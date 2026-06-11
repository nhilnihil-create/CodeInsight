
// A - STring

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string X;
	cin >> X;

	stack<char> s;
	int cnt = 0;

	for (int i=0; i<X.size(); i++) {
		if (s.empty() == false) {
			if (s.top() == 'S' && X[i] == 'T') {
				cnt += 2;
				s.pop();
				continue;
			}
		}

		s.push(X[i]);
	}

	int ans = X.size() - cnt;;

	cout << ans << endl;

	return 0;
}