#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int d[100010],x[100010],ans[100010],_[100010];ll ANS[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)x[i]=gi();
	int m=gi(),p;ll k=gi();
	for(int i=1;i<=n;++i)d[i]=ans[i]=i;
	for(int i=1;i<=m;++i)p=gi(),std::swap(d[p],d[p+1]);
	while(k){
		if(k&1){
			memcpy(_,ans,sizeof _);
			for(int i=1;i<=n;++i)ans[i]=d[_[i]];
		}
		k>>=1;
		memcpy(_,d,sizeof _);
		for(int i=1;i<=n;++i)d[i]=_[_[i]];
	}
	for(int i=1;i<=n;++i)printf("%lld\n",ANS[i]=ANS[i-1]+x[ans[i]]-x[ans[i]-1]);
	return 0;
}
