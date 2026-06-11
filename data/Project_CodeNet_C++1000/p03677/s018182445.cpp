#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,j,xlh,now,ans,a[200010],b[200010],f[200010],g[200010];
int main(){
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<n;i++){
		if(a[i]==a[i+1])continue;
		if(a[i]<=a[i+1]){
			xlh+=a[i+1]-a[i];
			g[a[i]+1]++;g[a[i+1]+1]--;
			f[a[i]+1]+=a[i]+1;f[a[i+1]+1]-=a[i]+1;
		}
		 else{
		 	xlh+=a[i+1]+m-a[i];
		 	g[a[i]+1]++;g[a[i+1]+m+1]--;
		 	f[a[i]+1]+=a[i]+1;f[a[i+1]+m+1]-=a[i]+1;
		 }
	}
	//printf("%lld\n",xlh);
	for(i=1;i<=m*2;i++){
		g[i]+=g[i-1];f[i]+=f[i-1];
		now=g[i]*i-f[i];
		if(i>m)j=i-m;
		 else j=i;
		b[j]+=now;
	}
	for(i=1;i<=m;i++){
	 ans=max(ans,b[i]);
	 //printf("%lld ",b[i]);
}
   //puts("");
	printf("%lld",xlh-ans);
}