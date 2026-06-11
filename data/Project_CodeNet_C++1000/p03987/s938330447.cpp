#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200010],l[200010],r[200010];
ll s[200010],tol=0;
signed main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		l[i]=0;
		r[i]=n+1;
	}
	for(ll i=1;i<=n;i++){
		while(tol&&a[s[tol]]>a[i]){
			r[s[tol]]=i;
			tol--;
		}
		l[i]=s[tol];
		tol++;
		s[tol]=i;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=(i-l[i])*(r[i]-i)*a[i];
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}