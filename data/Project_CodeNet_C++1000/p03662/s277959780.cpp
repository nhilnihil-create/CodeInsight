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
vector<int>G[100005],ve;
int cnt[100005];
int sec=-1;
void dfs(int v,int p){
	ve.push_back(v);
	cnt[v]=1;
	if(v==n-1){
		sec=ve[(SZ(ve)+1)/2];
	}
	rep(i,SZ(G[v])){
		int to=G[v][i];
		if(to!=p){
			dfs(to,v);
			cnt[v]+=cnt[to];
		}
	}
	ve.pop_back();
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		--u;--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,0);
//	rep(i,n){
//		cout<<cnt[i]<<' ';
//	}
//	cout<<endl;
	bool win=(cnt[sec]*2<n);
	string ans=win?"Fennec":"Snuke";
	cout<<ans<<endl;
	return 0;
}