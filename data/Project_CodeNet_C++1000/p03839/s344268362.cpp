#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define INF 1000000000000000000
int n,k,a[114514],b[114514],c[114514],ans;
signed main(){
	cin>>n>>k;
	rep(i,n)cin>>a[i];
	rep(i,n){
		b[i]=a[i];
		if(i)b[i]+=b[i-1];
		c[i]=max(0ll,a[i]);
		if(i)c[i]+=c[i-1];
	}
	ans=max(ans,max(0ll,b[k-1])+c[n-1]-c[k-1]);
	rep(i,n){
		if(i+k>=n)break;
		int x=max(0ll,b[i+k]-b[i]);
		int y=c[n-1]-(c[i+k]-c[i]);
		ans=max(ans,x+y);
	}
	cout<<ans<<endl;
	return 0;
}
