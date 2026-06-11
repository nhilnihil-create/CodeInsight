#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[20002];
ll s[20002];
int main() {
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=INF;
	for(ll i=0;i<n;i++){
		ll sum=i*m;
		for(ll j=0;j<n;j++){
			ll now=j+i;
			if(now>=n){
				now-=n;
			}
			if(s[j]==0){
				s[j]=a[now];
			}
			else if(s[j]>a[now]){
				s[j]=a[now];
			}
			sum+=s[j];
		}
		ans=min(sum,ans);
	}
	cout <<ans;
	// your code goes here
	return 0;
}