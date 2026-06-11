#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i,n) for(int i=0;i<(n);i++)
#define foreach(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define all(v) (v).begin(),(v).end()
typedef long long ll;
typedef unsigned uint;
const int INF=0x3f3f3f3f;
int inline in(){int x=0,c;for(;(uint)((c=getchar())-'0')>=10;)
{if(c=='-')return -in();if(!~c)throw ~0;}do{x=(x<<3)+(x<<1)+(c-'0');}
while((uint)((c=getchar())-'0')<10);return x;}
int n;
vector<int>G[100005];
int dist1[100005],dist2[100005];
void dfs1(int v,int p,int t){
	dist1[v]=t;
	rep(i,SZ(G[v])){
		int to=G[v][i];
		if(to!=p){
			dfs1(to,v,t+1);
		}
	}
}
void dfs2(int v,int p,int t){
	dist2[v]=t;
	rep(i,SZ(G[v])){
		int to=G[v][i];
		if(to!=p){
			dfs2(to,v,t+1);
		}
	}
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,-1,0);
	dfs2(n,-1,0);
//	for(int i=1;i<=n;i++){
//		cout<<dist1[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<dist2[i]<<' ';
//	}
//	cout<<endl;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(dist1[i]<=dist2[i])cnt1++;
		else cnt2++;
	}
	if(cnt1>cnt2)cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
	return 0;
}