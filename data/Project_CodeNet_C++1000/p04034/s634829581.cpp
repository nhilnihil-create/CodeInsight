#include<bits/stdc++.h>
#define rint register int 
using namespace std;
int n,m,tong[1010100],f[1010000];
int main(){
	cin>>n>>m;
	for(rint i=1;i<=n;++i) tong[i]=1;
	f[1]=1;
	for(rint i=1;i<=m;++i) {
		int x,y;
		cin>>x>>y;
		tong[x]--;
		tong[y]++;
		if(f[x]) f[y]=1;
		if(tong[x]==0) f[x]=0;
	}
	int ans=0;
	for(rint i=1;i<=n;++i) ans+=f[i];
	cout<<ans;
	return 0;
}