#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[501][501];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),h=gi(),w=gi();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=1000;
	for(int i=h;i<=n;i+=h)
		for(int j=w;j<=m;j+=w)
			a[i][j]-=h*w*1000+1;
	ll sum=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			sum+=a[i][j];
	if(sum<0)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)printf("%lld ",a[i][j]);
		puts("");
	}
	return 0;
}
