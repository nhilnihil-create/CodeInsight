#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int P[40010],A[40010],B[40010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)A[i]=i*20000,B[i]=(n-i+1)*20000;
	for(int i=1;i<=n;++i)P[i]=gi(),A[P[i]]-=n-i;
	for(int i=1;i<=n;++i)printf("%d ",A[i]);puts("");
	for(int i=1;i<=n;++i)printf("%d ",B[i]);puts("");
	return 0;
}
