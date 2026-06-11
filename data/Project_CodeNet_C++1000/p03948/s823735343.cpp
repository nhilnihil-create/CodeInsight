#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
int n,k,a[114514],ma[114514],mi[114514],Max,ans;
signed main(){
	cin>>n>>k;
	rep(i,n)cin>>a[i];
	mi[0]=a[0];
	for(int i=1;i<n;i++)mi[i]=min(a[i],mi[i-1]);
	ma[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)ma[i]=max(a[i],ma[i+1]);
	rep(i,n)Max=max(Max,ma[i]-mi[i]);
	rep(i,n){
		if(ma[i]-mi[i]==Max){
			if(i==0)ans++;
			else if(mi[i]!=mi[i-1])ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
