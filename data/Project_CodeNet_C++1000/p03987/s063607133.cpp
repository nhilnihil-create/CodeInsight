#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[2000010],l[2000010],r[2000010],s[2000010];
ll top=0;
ll ans=0;

signed main(){
	std::ios::sync_with_stdio(false);
	cin>>n;

	for(ll i=1;i<=n;i++){
		cin>>a[i];
		l[i]=0;
		r[i]=n+1;
	}
	for(ll i=1;i<=n;i++){
		while(top!=0&&a[s[top]]>a[i]){
			r[s[top]]=i;
			top--;
		}
		l[i]=s[top];
		top++;
		s[top]=i;	
	}
	for(ll i=1;i<=n;i++){
		ans+=(r[i]-i)*(i-l[i])*a[i];
	}
	cout<<ans;
	return 0;
}