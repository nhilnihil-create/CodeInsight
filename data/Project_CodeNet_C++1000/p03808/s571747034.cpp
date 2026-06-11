#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[100010],b[100010],c[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();if(n==1)return puts("YES"),0;
	for(int i=1;i<=n;++i)a[i]=gi();
	b[1]=a[1]-a[n];for(int i=2;i<=n;++i)b[i]=a[i]-a[i-1];
	ll m=0;for(int i=1;i<=n;++i)m+=a[i];
	if(m%(1ll*n*(n+1)/2))return puts("NO"),0;
	m/=1ll*n*(n+1)/2;
	for(int i=1;i<=n;++i)if((b[i]-m)%n||(b[i]-m)/n>0)return puts("NO"),0;
	puts("YES");
	return 0;
}
