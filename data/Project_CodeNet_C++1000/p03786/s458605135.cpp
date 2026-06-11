#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[114514],b[114514];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	b[0]=a[0];
	for(int i=1;i<n;i++)b[i]=a[i]+b[i-1];
	ll ans=n;
	for(int i=0;i<n-1;i++){
		if(b[i]*2<a[i+1])ans=n-i-1;
	}
	cout<<ans<<endl;
	return 0;
}