#include<bits/stdc++.h>
using namespace std;
#define next Next
#define last Last
const int N=1e5+5;
int n,ans,a[N];
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
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
			ans++;
			swap(a[i],a[i+1]);
		}
	}
	cout<<ans;
}