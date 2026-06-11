#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int A[100010],fir[100010],dis[200010],nxt[200010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
ll dfs(int x,int fa=-1){
	std::vector<int>son;ll sum=0;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa==dis[i])continue;
		son.push_back(dfs(dis[i],x));
		sum+=son.back();
	}
	if(son.empty())return A[x];
	ll c=sum-A[x];
	if(c<0||c*2>sum)puts("NO"),exit(0);
	std::sort(son.begin(),son.end(),std::greater<int>());
	ll _=0,o;for(int i=1;i<son.size();++i)_+=son[i];
	if(son[0]>_)o=_;
	else o=sum/2;
	if(o<c)puts("NO"),exit(0);
	return sum-2*c;
}
int d[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<=n;++i)A[i]=gi();
	for(int i=1;i<n;++i)++d[a=gi()],++d[b=gi()],link(a,b),link(b,a);
	for(int i=1;i<=n;++i)
		if(d[i]>1){
			if(dfs(i))puts("NO");else puts("YES");
			return 0;
		}
	if(A[1]==A[2])puts("YES");else puts("NO");
	return 0;
}
