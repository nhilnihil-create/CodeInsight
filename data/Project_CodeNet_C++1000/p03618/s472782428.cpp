#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char S[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%s",S+1);int c[26]={0},n=strlen(S+1);
	for(int i=1;i<=n;++i)++c[S[i]-'a'];
	ll ans=1ll*n*(n-1)/2+1;
	for(int i=0;i<26;++i)ans-=1ll*c[i]*(c[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
}
