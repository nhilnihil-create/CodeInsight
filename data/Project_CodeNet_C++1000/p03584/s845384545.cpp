#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int bit(int x, int n){
	return (x >> n) & 1;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	vector<ll> B(N);
	rep(i, N) cin >> A[i] >> B[i];

	int l = 32 - __builtin_clz(K);

	ll ans = 0;
	for(int i = 0; i < l; i++){
		if(bit(K, i) == 0) continue;

		ll tmp = 0;
		for(int j = 0; j < N; j++){
			int x = A[j];
			if(bit(x, i) == 1) continue;

			bool ok = true;
			for(int k = 30; k > i; k--){
				if(bit(x, k) > bit(K, k)) {
					ok = false;
					break;
				}
			}

			if(ok) tmp += B[j];
		}

		ans = max(ans, tmp);
	}

	ll tmp2 = 0;
	for(int j = 0; j < N; j++){
		if((A[j] | K) <= K) tmp2 += B[j];
	}

	ans = max(ans, tmp2);

	cout << ans << endl;
}
