#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,K;
int a[100010],ans;
std::vector<int>G[100010];
int dfs(int x){
	int r=1;
	for(int i:G[x])r=std::max(r,1+dfs(i));
	if(r==K)r=0,ans+=a[x]!=1;
	return r;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),K=gi();int cnt=0;
	for(int i=1;i<=n;++i)a[i]=gi(),cnt+=a[i]!=1;
	if(K==1)return printf("%d\n",cnt),0;
	ans=a[1]!=1;a[1]=1;
	for(int i=2;i<=n;++i)G[a[i]].push_back(i);
	for(int i:G[1])dfs(i);
	printf("%d\n",ans);
	return 0;
}
