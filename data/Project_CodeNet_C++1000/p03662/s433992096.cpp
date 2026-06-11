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
const int MAXN=1e5+5;
int ghead[MAXN],gnxt[2*MAXN],gto[2*MAXN];
int path[MAXN],npath;
int col[MAXN];
bool dfs(int v,int p){
	if(v==n-1){
		npath=0;path[npath++]=v;return true;
	}
	for(int x=ghead[v];x!=-1;x=gnxt[x]){
		int to=gto[x];
		if(to!=p){
			if(dfs(to,v)){
				path[npath++]=v;return true;
			}
		}
	}
	return false;
}
void dfscol(int v,int p){
	for(int x=ghead[v];x!=-1;x=gnxt[x]){
		int to=gto[x];
		if(to!=p&&col[to]==-1){
			col[to]=col[v];
			dfscol(to,v);
		}
	}
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,n)ghead[i]=-1;
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gnxt[2*i+0]=ghead[a];ghead[a]=2*i+0;gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b];ghead[b]=2*i+1;gto[2*i+1]=a;
	}
	dfs(0,0);
	reverse(path,path+npath);
//	rep(i,npath)cout<<path[i]<<' ';cout<<endl;
	rep(i,n)col[i]=-1;
	rep(i,npath)col[path[i]]=i<(npath+1)/2?0:1;
	rep(i,npath)dfscol(path[i],path[i]);
	int na=0,nb=0;
	rep(i,n){
		if(col[i]==0)na++;
		else nb++;
	}
//	rep(i,n)cout<<col[i]<<' ';cout<<endl;
//	cout<<na<<' '<<nb<<endl;
	string ans=na>nb?"Fennec":"Snuke";
	cout<<ans<<endl;
	return 0;
}