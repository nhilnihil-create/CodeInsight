#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct intv{int l,r;}s[300010];
int ans[100010],t[100010],n,m;
void update(int x,int d){while(x<=m)t[x]+=d,x+=x&-x;}
int query(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	for(int i=1;i<=n;++i)s[i].l=gi(),s[i].r=gi();
	std::sort(s+1,s+n+1,[](intv a,intv b){return a.r-a.l<b.r-b.l;});
	for(int i=1,p=1;i<=m;++i){
		while(p<=n&&s[p].r-s[p].l+1==i)update(s[p].l,1),update(s[p].r+1,-1),++p;
		int res=n-p+1;
		for(int j=i;j<=m;j+=i)res+=query(j);
		printf("%d\n",res);
	}
	return 0;
}
