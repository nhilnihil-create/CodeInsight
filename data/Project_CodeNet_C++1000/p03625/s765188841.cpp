
// C - Make a Rectangle

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	map<int, int, greater<int>> cnt;

	int A;
	for (int i=0; i<N; i++) {
		cin >> A;
		cnt[A]++;
	}

	ll H = 0, W = 0;
	for (auto itr : cnt) {
		if (H == 0 && itr.second >= 4) {
			H = itr.first;
			W = H;
			break;
		} else if (itr.second >= 2) {
			if (H == 0) {
				H = itr.first;
			} else {
				W = itr.first;
				break;
			}
		}
	}

	ll ans = H * W;

	cout << ans << endl;

	return 0;
}