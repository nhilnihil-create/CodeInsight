#include<bits/stdc++.h>
#define ll long long
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int read()
{
	static char buf[1<<21],*p1,*p2;
	int f=0,c=1; char ch=gc();
	while(ch<'0'||ch>'9') { if(ch=='-') c=-1; ch=gc(); }
	while(ch>='0'&&ch<='9') { f=f*10+ch-'0'; ch=gc(); }
	return c*f;
}
int n,a[123456];
bool cmp(int a,int b) { return a>b; }
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if(i+1<=a[i+1]) continue;//没到边上
		int j=0; 
		while(a[i+j+1]==i) ++j;//一段平的 
		if( ((a[i]-i)&1) || (j&1) ) puts("First");
		else puts("Second");
		return 0;   
	}
	return 0;
}