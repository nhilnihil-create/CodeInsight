#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[4020],b[2020][2020];
int main(){
	ll n,x;
	cin>>n>>x;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	for(int i=n;i<2*n;i++)a[i]=a[i-n];
	for(int i=0;i<n;i++)b[0][i]=a[i];
	for(int i=1;i<n;i++){
		ll sum=x*i;
		for(int j=0;j<n;j++){
			b[i][j]=min(b[i-1][j],a[j+i]);
			sum+=b[i][j];
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}