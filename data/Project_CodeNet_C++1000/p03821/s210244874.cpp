#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N;
	cin >> N;

	vector<ll> A(N),B(N);
	rep(i,N){
		cin >> A[i] >> B[i];
	}
	
	for(ll i = N-1; i >= 0; i-- ){
		A[i] += ans;
		if(A[i]<=B[i]){
			if(A[i]!=0){
				ans += B[i] - A[i];
				// A[i] += B[i] - A[i];
			}
		}
		else{
			if(A[i] % B[i] == 0){
				ans += B[i]*(A[i]/B[i]) - A[i];
				// A[i] += B[i]*(A[i]/B[i]) - A[i];
			}
			else{
				ans += B[i]*(A[i]/B[i] + 1) - A[i];
				// A[i] += B[i]*(A[i]/B[i] + 1) - A[i];
			}
		}
	}
	
	cout << ans << endl;

	// 間違っていたら表示
	// rep(i,N){
	// 	if(A[i] % B[i] != 0){
	// 		cout << "NG" << endl;
	// 		cout << i << ": " << A[i] << " " << B[i] << endl;
	// 	}
	// }

	return 0;
}