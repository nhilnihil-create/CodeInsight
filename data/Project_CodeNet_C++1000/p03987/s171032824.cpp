#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int stk[200010],tp,a[200010],L[200010],R[200010],n;
void work(int*A){
	tp=0;
	for(int i=1;i<=n;++i){
		while(tp&&a[stk[tp]]>a[i])--tp;
		A[i]=i-stk[tp];
		stk[++tp]=i;
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	work(L);std::reverse(a+1,a+n+1);work(R);
	ll ans=0;
	for(int i=1;i<=n;++i)
		ans+=1ll*a[i]*L[n-i+1]*R[i];
	printf("%lld\n",ans);
	return 0;
}
