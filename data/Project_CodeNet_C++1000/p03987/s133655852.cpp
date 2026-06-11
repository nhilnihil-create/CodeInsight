#include<bits/stdc++.h>
using namespace std;
int n,l[200010],r[200010],a[200010]={},st[200010]={},top=0;
long long ans=0;
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++){
		l[i]=0,r[i]=n+1;
		a[i]=read();
		while(a[i]<a[st[top]])
			r[st[top--]]=i;
		l[i]=st[top];
		st[++top]=i;
	}
	for(int i=1;i<=n;i++)
		ans+=(long long)a[i]*(i-l[i])*(r[i]-i);
	printf("%lld\n",ans);
}