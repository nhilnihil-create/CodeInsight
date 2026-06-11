#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll b[100010];
	vector<ll>a;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		a.push_back(now);
	}
	sort(a.begin(),a.end());
	b[0]=a[0];
	for(ll j=1;j<n;j++){
		b[j]=b[j-1]+a[j];
	}
	ll ans=1;
	for(ll i=1;i<n;i++){
		if(b[i-1]*2>=a[i]){
			ans++;
		}
		else{
			ans=1;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}