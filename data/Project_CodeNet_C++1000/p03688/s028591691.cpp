#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[100010],c[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),mx=0,mn=1e9;
	for(int i=1;i<=n;++i)++c[a[i]=gi()],mx=std::max(a[i],mx),mn=std::min(a[i],mn);
	if(mx-mn>1)return puts("No"),0;
	if(mx==mn){
		if(mx==n-1||mx*2<=n)puts("Yes");
		else puts("No");
		return 0;
	}
	if(mn<c[mn]||n-c[mn]<2*(mx-c[mn]))puts("No");
	else puts("Yes");
	return 0;
}
