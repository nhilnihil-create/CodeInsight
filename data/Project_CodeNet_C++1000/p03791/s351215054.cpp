#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
int main(){
	int n;
	vector<ll> a;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	ll ans = 1;
	stack<ll> sta;
	for(int i=0;i<n;i++){
		sta.push(a[i]);
		int k = sta.size();
		if( 2*k-1 > sta.top() ){
			ans *= k;
			ans %= inf;
			sta.pop();
		}
	}
	int c = sta.size();
	for(int i=1;i<=c;i++){
		ans *= i;
		ans %= inf;
	}
	cout<<ans<<endl;
	return 0;
}