#include<bits/stdc++.h>
#define N 2005
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){ if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
vector<int> e[N];
int ans,n,k,dep[N],a[N],b[N],ban[N][N];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	for(int i=0;i<e[u].size();++i){
		if(ban[u][e[u][i]]) continue;
		if(dep[e[u][i]]) continue;
		dfs(e[u][i],u);
	}
}
int work(int rt){
	int res=0;
	memset(dep,0,sizeof(dep));
	if(k&1) dfs(a[rt],0),dfs(b[rt],0);
	else 
		dfs(rt,0);
	for(int i=1;i<=n;++i){
//		cout<<dep[i]<<' ';
		if(k%2==0&&dep[i]>(k/2+1)) ++res;
		if(k%2==1&&dep[i]>(k/2+1)) ++res;
	}
//	cout<<endl;//
	return res;
}
int main(){
	n=read();k=read();ans=2002;
	for(int i=1;i<n;++i){
		a[i]=read(),b[i]=read();
		e[a[i]].push_back(b[i]),e[b[i]].push_back(a[i]);
	}
	if(k%2==0){
		for(int i=1;i<=n;++i)
			ans=min(ans,work(i));
	}
	else{
		for(int i=1;i<n;++i){
	//		cout<<"hahah1"<<a[i]<<' '<<b[i]<<endl;
			ban[a[i-1]][b[i-1]]=ban[b[i-1]][a[i-1]]=0,
			ban[a[i]][b[i]]=ban[b[i]][a[i]]=1;
			ans=min(ans,work(i));
	//		cout<<"hahah2"<<i<<' '<<work(i)<<endl;
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
6 3
1 2
3 2
4 2
1 6
5 6

6 2
1 2
3 2
4 2
1 6
5 6
*/
