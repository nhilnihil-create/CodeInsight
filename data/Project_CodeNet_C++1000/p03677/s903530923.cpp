#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,m,a[N];
long long k[N],b[N],ans;

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n-1;i++){
		int x=a[i],y=a[i+1];
		if (y<x) y+=m;
		k[x+1]+=-1;b[x+1]+=y+1;
		k[y+1]-=-1;b[y+1]-=y+1;
		b[y+1]+=y-x;b[x+m+1]-=y-x;
	}
	for (int i=1;i<=2*m;i++)
		k[i]+=k[i-1],b[i]+=b[i-1];
	ans=1ll<<60;
	for (int i=1;i<=m;i++)
		ans=min(ans,k[i]*i+b[i]+k[m+i]*(m+i)+b[m+i]);
	printf("%lld\n",ans);
	return 0;
}