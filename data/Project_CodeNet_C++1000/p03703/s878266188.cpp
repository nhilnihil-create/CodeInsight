#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
using namespace std;

ll N, K, bit[200010];
void add(ll a, ll w){
    for(ll i=a; i<=N+1; i += (ll) i&(-i)){
        bit[i] += w;
    }
}
ll sum_bit(ll s){
    if(s<1) return 0;
    return bit[s]+sum_bit(s-(s&(-s)));
}

int main() {
	cin >> N >> K;
	vector<ll> a(N), sum(N+1, 0);
	vector<pair<ll, ll>> z(N+1);
	z[0]=make_pair(0, 0);
	for(ll i=0; i<N; ++i){
	    cin >> a[i];
	    a[i] -= K;
	    sum[i+1]=sum[i]+a[i];
	    z[i+1]=make_pair(sum[i+1], i+1);
	}
	sort(z.begin(), z.end());
	sum[z[0].second]=1;
	for(ll i=1; i<=N; ++i){
	    if(z[i-1].first<z[i].first) sum[z[i].second]=sum[z[i-1].second]+1;
	    else sum[z[i].second]=sum[z[i-1].second];
	}
	ll ans=N*(N+1)/2;
	for(ll i=0; i<=N; ++i){
	    ans -= (ll) i-sum_bit(sum[i]);
	    add(sum[i], 1);
	}
	cout << ans << endl;
	return 0;
}
