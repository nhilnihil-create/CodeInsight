#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e2;
const int INF=1e9;
int N,M;
vector<int> g[size];
int len[size][size]={};
int d[size];
void dijkstra(int a){//O(E+NlogN)
    priority_queue<pair<int,int>> pq;
	rep(i,0,N){
		d[i]=INF;
		pq.push(make_pair(-d[i],i));
	}
	d[a]=0;pq.push(make_pair(0,a));
	int v,temp;
	while(!pq.empty()){
		v=pq.top().second;
		pq.pop();
		for(int u:g[v]){
			temp=d[v]+len[v][u];
			if(d[u]>temp){
				d[u]=temp;
				pq.push(make_pair(-d[u],u));
			}
		}
	}return;
}
int main(){
	cin>>N>>M;
	vector<pair<int,int>> edge(M);
	rep(i,0,M){
		int a,b,c;
		cin>>a>>b>>c;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
		len[a][b]=c;len[b][a]=c;
		edge[i].first=a;
		edge[i].second=b;
	}
	int ans=0;
	rep(i,0,M){
		int a=edge[i].first,b=edge[i].second;
		dijkstra(a);
		if(d[b]<len[a][b]) ans++;
	}cout<<ans<<endl;
}