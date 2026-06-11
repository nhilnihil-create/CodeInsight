#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> a(3*N);
	rep(i, 3*N)cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	ll ans = 0;


	rep(i, N) {
		ans += a[2 * i + 1];
	}

	cout << ans << endl;

	return 0;
}