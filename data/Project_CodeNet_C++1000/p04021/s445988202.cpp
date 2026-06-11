#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
	ll n;
	cin>>n;
	P p[114514];
	for(int i=0;i<n;i++){
		cin>>p[i].first;
		p[i].second=i;
	}
	sort(p,p+n);
	ll ans=0;
	for(int i=0;i<n;i++)if(i%2!=p[i].second%2)ans++;
	ans/=2;
	cout<<ans;
	return 0;
}
