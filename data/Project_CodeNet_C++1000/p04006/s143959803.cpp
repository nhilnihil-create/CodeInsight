#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[2010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),x=gi();ll ans=1e18;
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=0;i<n;++i){
		ll res=1ll*i*x;
		for(int j=1;j<=n;++j)res+=a[j];
		ans=std::min(ans,res);
		int _an=a[n];
		for(int i=n;i>1;--i)a[i]=std::min(a[i],a[i-1]);
		a[1]=std::min(a[1],_an);
	}
	printf("%lld\n",ans);
	return 0;
}
