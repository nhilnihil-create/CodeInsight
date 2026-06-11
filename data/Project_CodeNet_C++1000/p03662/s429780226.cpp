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
vector<int> bfs(int n,vector<vector<int> >&G,int s){
	vector<int>d(n,INF);d[s]=0;
	queue<int>q;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		rep(i,SZ(G[u])){
			int to=G[u][i];
			if(d[to]>d[u]+1){
				d[to]=d[u]+1;
				q.push(to);
			}
		}
	}
	return d;
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
    int n;
	cin>>n;
	vector<vector<int> >G(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int>d1=bfs(n,G,0);
	vector<int>d2=bfs(n,G,n-1);
	int n1=0,n2=0;
	rep(i,n){
		if(d1[i]<=d2[i])n1++;
		else n2++;
	}
	string ans=n1>n2?"Fennec":"Snuke";
	cout<<ans<<endl;
	return 0;
}