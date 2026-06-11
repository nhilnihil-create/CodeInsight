#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
bool yes[200010];
int ans[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),X=gi();
	if(X==1||X==2*n-1)return puts("No"),0;
	puts("Yes");
	if(n==2)puts("1\n2\n3");
	else{
		bool flg=0;
		if(X==2)flg=1,X=2*n-2;
		yes[X]=yes[X-1]=yes[X-2]=yes[X+1]=1;
		ans[n-1]=X-1,ans[n]=X,ans[n+1]=X+1,ans[n+2]=X-2;
		for(int i=1,j=1;i<2*n;++i){
			while(yes[j])++j;
			if(ans[i])continue;
			ans[i]=j,yes[j]=1;
		}
		if(flg)for(int i=1;i<2*n;++i)ans[i]=2*n-ans[i];
		for(int i=1;i<2*n;++i)printf("%d\n",ans[i]);
	}
	return 0;
}
