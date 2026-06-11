#include<bits/stdc++.h>
#include<numeric>
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

	ll N, C, K;
	cin >> N >> C >> K;

	vector<ll> T(N);
	rep(i,N){
		cin >> T[i];
	}
	sort(T.begin(),T.end());

	rep(index,N){
		ll end = T[index] + K;
		ll cnt=1;
		while(1){
			if(cnt>=C || index==N-1) break;

			if(end >= T[index + 1]){
				cnt++;
				index++;
			}
			else break;
		}
		// cout << index << ": " <<  cnt << endl;
		ans++;
	}

	cout << ans << endl;

	return 0;
}