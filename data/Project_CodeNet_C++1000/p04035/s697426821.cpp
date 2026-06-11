
// C - Knot Puzzle

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int a[100000];

int main() {
	int N, L;
	cin >> N >> L;

	for (int i=0; i<N; i++) {
		cin >> a[i];
	}

	int max_pair_len = 0;
	int pair_knot;
	for (int i=1; i<N; i++) {
		if (a[i-1] + a[i] > max_pair_len) {
			max_pair_len = a[i-1] + a[i];
			pair_knot = i;
		}
	}

	if (max_pair_len < L) {
		cout << "Impossible" << endl;
		return 0;
	}

	vector<int> ans;

	for (int i=1; i<pair_knot; i++) {
		ans.push_back(i);
	}

	for (int i=N-1; i>pair_knot; i--) {
		ans.push_back(i);
	}

	ans.push_back(pair_knot);

	cout << "Possible" << endl;

	for (int a : ans) {
		cout << a << endl;
	}

	return 0;
}