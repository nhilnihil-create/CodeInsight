
// B - K個のケーキ

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int K, T;
	cin >> K >> T;

	int max_a = 0;
	for (int i=0; i<T; i++) {
		int a;
		cin >> a;
		max_a = max(max_a, a);
	}

	int ans = max(0, max_a - (K - max_a) - 1);

	cout << ans << endl;

	return 0;
}