#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K, rec[60], ans[60];
const ll N = 50;
int main() {
	cin >> K;
	if (K == 0) {
		cout << 2 << endl;
		cout << 1 << " " << 1;
		exit(0);
	}
	ll div = (K - 1) / N, mo = K % N;
	iota(ans, ans + N, 0);
	for (ll i=0;i<N;i++)
		ans[i] += div;
	if (mo == 0)
		for (ll i = 0; i < N; i++)
			ans[i]++;
	else {
		for (ll i=0;i< mo;i++) {
			ans[i] += 50;
			for (ll j=0;j<N;j++)
				if(i != j)
					ans[j]--;
		}
	}
	cout << N << endl;
	for (ll i=0;i<N;i++) cout << ans[i]<<" ";
	return 0;
}