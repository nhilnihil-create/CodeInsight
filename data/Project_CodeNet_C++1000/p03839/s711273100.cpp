#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll posi[101010];
ll imos[101010];

int main(){

	ll N, K;
	cin >> N >> K;
	for(ll i = 1; i <= N; i++){
		cin >> imos[i];
		if(imos[i] > 0)posi[i] = imos[i];
		imos[i] += imos[i - 1];
		posi[i] += posi[i - 1];
	}
	ll ans = 0;
	for(ll l = 1; l <= N; l++){
		ll r = l + K - 1;
		if(r > N)break;
		ll tmp = max(0LL, imos[r] - imos[l - 1]);
		tmp += (posi[N] - posi[r]);
		tmp += (posi[l - 1] - posi[0]);
		ans = max(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}
