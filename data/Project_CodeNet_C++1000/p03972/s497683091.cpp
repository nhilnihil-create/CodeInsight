#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

vector<ll> a,b;
int main() {
	ll h,w;
	cin>>h>>w;
	for(ll i=0;i<h;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	for(ll i=0;i<w;i++){
		ll y;
		cin>>y;
		b.push_back(y);
	}
	a.push_back(inf);
	b.push_back(inf);
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	ll ans=0;
	while(a.size()!=1||b.size()!=1){
		if(a[a.size()-1]<=b[b.size()-1]){
			ans+=a[a.size()-1]*(w+1);
			h--;
			a.pop_back();
		}
		else{
			ans+=b[b.size()-1]*(h+1);
			w--;
			b.pop_back();
		}
		//cout << ans<<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}