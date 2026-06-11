
// C - Write and Erase

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

unordered_map<int, bool> memo;

int main() {
	int N;
	cin >> N;

	int ans = 0;
	int A;
	for (int i=0; i<N; i++) {
		cin >> A;
		if (memo[A]) {
			ans--;
			memo[A] = false;
		} else {
			ans++;
			memo[A] = true;
		}
	}

	cout << ans << endl;

	return 0;
}