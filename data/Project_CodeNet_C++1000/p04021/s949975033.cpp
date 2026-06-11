#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>a,b;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
		b.push_back(x);
	}
	sort(b.begin(),b.end());
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll now=a[i];
		auto itr=lower_bound(b.begin(),b.end(),now);
		ll iti=itr-b.begin();
		//cout << iti<<endl;
		if(abs(iti-(i))%2!=0){
			ans++;
		}
	}
	cout <<ans/2;
	// your code goes here
	return 0;
}