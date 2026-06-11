#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a.at(i);
	int ans = 0;
	rep(i, N) {
		if (a.at(a.at(i) - 1) - 1 == i) ans++;
	}
	cout << ans / 2 << endl;
	return 0;
}