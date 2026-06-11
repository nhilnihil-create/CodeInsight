#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	std::sort(a+1,a+n+1,std::greater<int>());
	for(int i=1;i<=n;++i)
		if(a[i+1]<i+1){
			int R=i;while(R<n&&a[R+1]==i)++R;
			R-=i;
			if((a[i]-i&1)||(R&1))puts("First");
			else puts("Second");
			return 0;
		}
}
