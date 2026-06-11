#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll a[302][302],b[302],c[302];
bool ch[302];
int main() {
	ll n,m;
	cin>>n>>m;
	ll M=m;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			ll x;
			cin>>x;
			x--;
			a[i][j]=x;
		}
	}
	ll ans=inf;
	while(M!=0){
	for(ll i=0;i<n;i++){
		ll now=a[i][c[i]];
		while(ch[now]){
			c[i]++;
			now=a[i][c[i]];
		}
		b[now]++;
	}
	ll sum=0;
	for(ll i=0;i<m;i++){
		if(ch[i]){
			continue;
		}
		sum=max(sum,b[i]);
	}
	ans=min(ans,sum);
	for(ll i=0;i<m;i++){
		if(b[i]==sum){
			ch[i]=true;
			M--;
		}
		b[i]=0;
	}
	}
	cout <<ans;
	// your code goes here
	return 0;
}