#include<bits/stdc++.h>
using namespace std;
#define next Next
#define last Last
#define int long long
const int N=1e6+5;
int n,m,ans,cnt,sum,a[N],gs[N];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
	int ret=0,f=0;char c=gc();
	while(!isdigit(c)){if(c=='-')f=1;c=gc();}
	while(isdigit(c)){ret=ret*10+c-48;c=gc();}
	if(f)return -ret;return ret;
}
signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)
	{
		int l=a[i-1],r=a[i];
		if(l>r)r+=m;
		sum+=r-l;
		if(r-l>1)
		{
			gs[l+2]++;
			gs[r+1]-=r-(l+2)+2;
			gs[r+2]+=r-(l+2)+1;
		}
	}
	for(int i=1;i<=m*2;i++)gs[i]+=gs[i-1];
	for(int i=1;i<=m*2;i++)gs[i]+=gs[i-1];
	ans=sum;
	for(int i=1;i<=m;i++)ans=min(ans,sum-gs[i]-gs[i+m]);
	cout<<ans;
}