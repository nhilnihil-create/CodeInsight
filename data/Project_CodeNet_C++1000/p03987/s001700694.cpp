#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
inline int read()
{
	int neg=1,num=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')neg=-1;
	for(;isdigit(c);c=getchar())num=(num<<1)+(num<<3)+c-'0';
	return neg*num;
}
int n,a[N],s[N],l[N],r[N];
long long ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		for(l[i]=i;l[i]>1 && a[l[i]-1]>a[i];l[i]=l[l[i]-1]); 
	for(int i=n;i>=1;i--)
		for(r[i]=i;r[i]<=n && a[r[i]+1]>a[i];r[i]=r[r[i]+1]);
	for(int i=1;i<=n;i++)ans+=1ll*a[i]*(r[i]-i+1)*(i-l[i]+1);
	printf("%lld",ans);
	return 0;
}
