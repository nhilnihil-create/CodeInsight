#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N], B[N];
	rep(i,N) cin >> A[i] >> B[i];
	ll ans = 0;
	for (int i = N-1; i >= 0; i--) {
		int p = (ans+A[i]+B[i])%B[i];
		if (p != 0) p = B[i] - p;
		ans += p;
	}
	cout << ans << endl;

	return 0;
}
