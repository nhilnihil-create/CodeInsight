#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main(){
	ll N, x; cin >> N >> x;
	ll a[N];
	for(int i=0; i<N; i++) cin >> a[i];
	ll min_cost[N][N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i==0) min_cost[j][i] = a[j];
			else{
				if(min_cost[j][i-1] > a[(j+N-i)%N]) min_cost[j][i] = a[(j+N-i)%N];
				else min_cost[j][i] = min_cost[j][i-1];
			}
		}
	}
	ll ans = 1e18;
	for(int i=0; i<N; i++){
		ll cnt = x*i;
		for(int j=0; j<N; j++){
			cnt += min_cost[j][i];
		}
		if(ans > cnt) ans = cnt;
	}
	cout << ans << endl;
	return 0;
}