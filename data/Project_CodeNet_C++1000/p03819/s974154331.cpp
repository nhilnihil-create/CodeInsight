#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 300002
using namespace std;
struct shop{
	int l,r;
}a[N];
int n,m,i,j=1,d,c[N];
int read()
{
	char c=getchar();
	int w=0;
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0'){
		w=w*10+c-'0';
		c=getchar();
	}
	return w;
}
int my_comp(const shop &x,const shop &y)
{
	return x.r-x.l<y.r-y.l;
}
int lowbit(int x)
{
	return x&(-x);
}
int ask(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i)) ans+=c[i];
	return ans;
}
void add(int x,int y)
{
	for(int i=x;i<=m+1;i+=lowbit(i)) c[i]+=y;
}
int main()
{
	n=read();m=read();
	for(i=1;i<=n;i++) a[i].l=read()+1,a[i].r=read()+1;
	sort(a+1,a+n+1,my_comp);
	for(d=1;d<=m;d++){
		while(j<=n&&a[j].r-a[j].l<d){
			add(a[j].l,1);
			add(a[j].r+1,-1);
			j++;
		}
		int ans=n-j+1;
		for(i=1;i<=m+1;i+=d) ans+=ask(i);
		printf("%d\n",ans);
	}
}