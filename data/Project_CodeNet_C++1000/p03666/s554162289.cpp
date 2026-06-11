#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi()-1,a=gi(),b=gi(),c=gi(),d=gi();
	for(int i=0;i<=n;++i){
		ll L=1ll*c*i-1ll*d*(n-i),R=1ll*d*i-1ll*c*(n-i);
		if(a+L<=b&&b<=a+R)return puts("YES"),0;
	}
	puts("NO");
	return 0;
}
