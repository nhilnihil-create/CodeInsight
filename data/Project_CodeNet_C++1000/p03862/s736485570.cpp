#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, x;
	cin>>n>>x;
	vector<ll> a(n);
	for(auto &y : a){
		cin>>y;
	}
	ll ans = 0;
	for(int i = 0; i + 1 < n; i++){
		if(a[i] + a[i + 1] <= x)continue;
		ll rem = a[i] + a[i + 1] - x;
		ans += rem;
		if(rem <= a[i + 1])a[i + 1] -= rem;
		else a[i + 1] = 0;
	}
	cout<<ans<<endl;

	return 0;
}