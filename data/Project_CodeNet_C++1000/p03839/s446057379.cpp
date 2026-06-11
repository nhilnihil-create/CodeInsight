#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll a[100010],S[100010],S2[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),K=gi();ll ans=0;
	for(int i=1;i<=n;++i)a[i]=gi(),S[i]=a[i]+S[i-1],S2[i]=(a[i]>0)*a[i]+S2[i-1];
	for(int l=1,r=K;r<=n;++l,++r)ans=std::max(ans,std::max(S[r]-S[l-1],0ll)+S2[l-1]+S2[n]-S2[r]);
	printf("%lld\n",ans);
	return 0;
}
