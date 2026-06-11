#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1000;
const long INF=1e13;
int N,M;
vector<pair<int,long>> g[size];
long score[size]={};int check[size]={};
void dfs(int v){
    check[v]++;
	for(pair<int,long> p:g[v]){
		int u=p.first;
		if(score[u]==INF) continue;
        else if(score[u]<score[v]+p.second){
            if(check[u]) score[u]=INF;
            else score[u]=min(score[v]+p.second,INF);
            dfs(u);
        }
	}return;
}
int main(){
	cin>>N>>M;
	int a,b;long c;
	rep(i,0,M){
		cin>>a>>b>>c;a--;b--;
		g[a].push_back({b,c});
	}
    rep(i,1,N) score[i]=-INF;
	dfs(0);
    //print(score,N);
	if(score[N-1]==INF) cout<<"inf"<<endl;
    else cout<<score[N-1]<<endl;
}