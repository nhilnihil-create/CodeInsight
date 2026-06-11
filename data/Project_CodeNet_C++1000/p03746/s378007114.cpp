#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>G[100010];
bool vis[100010],cxk[100010];
std::vector<int>A,B;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),G[a].push_back(b),G[b].push_back(a);
	A.push_back(a),B.push_back(b);vis[a]=vis[b]=1;
	while(1){
		if(!cxk[a]){
			bool flg=1;
			for(int i:G[a])if(!vis[i]){vis[a=i]=1;A.push_back(a);flg=0;break;}
			if(flg)cxk[a]=1;
		}
		if(cxk[a]&&!cxk[b]){
			bool flg=1;
			for(int i:G[b])if(!vis[i]){vis[b=i]=1;B.push_back(b);flg=0;break;}
			if(flg)cxk[b]=1;
		}
		if(cxk[a]&&cxk[b])break;
	}
	printf("%d\n",A.size()+B.size());
	for(int i=A.size()-1;~i;--i)printf("%d ",A[i]);
	for(int i:B)printf("%d ",i);
	return 0;
}
