#include <bits/stdc++.h>
#define int long long 
using namespace std;
int f[100100],g[100100],a[100100];
char opt,lst;
int x,y,ans,cnt,n;
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		lst=opt;
		if(i!=n)cin>>opt;
		if(lst=='-'){
			x=-x;
			a[++cnt]=x;
		}
		if(y<=0&&x>0)a[++cnt]=x;
		if(y>0&&x>0)a[cnt]+=x;
		y=x;
	}
	f[1]=a[1];
	for(int i=cnt;i>=1;i--)g[i]=g[i+1]+abs(a[i]);
	for(int i=2;i<=cnt;i++)f[i]=f[i-1]+a[i];
	ans=f[cnt];
	for(int i=1;i<cnt;i++)
		if(a[i+1]<0)
			ans=max(ans,f[i+1]-a[i+2]+g[i+3]);
	printf("%lld\n",ans);
} 