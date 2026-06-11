#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>
#include <iomanip>

using namespace std;
typedef long long ll;
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define all(x) x.begin(),x.end()


vector<vector<int>> to(2100);
vector<vector<int>> ot(2100);
vector<bool> fromS(1100);
vector<bool> fromG(1100);
struct edge{
	int from;
	int to;
	ll cost;
};
void dfs(int now){
    if(fromS[now])return;
    fromS[now]=true;
    for(int next:to[now]){
        dfs(next);
    }
}
void rdfs(int now){
    if(fromG[now])return;
    fromG[now]=true;
    for(int next:ot[now]){
        rdfs(next);
    }
}

int main(){
	int n,m;cin>>n>>m;
	vector<edge> edges(m);
	rep(i,m){
		int a,b;cin>>a>>b;
		--a,--b;
		ll c;cin>>c;
		edges[i]={a,b,c};
		to[a].push_back(b);
		ot[b].push_back(a);
	}
	vector<bool> ok(n);
	dfs(0);
	rdfs(n-1);
	rep(i,n)ok[i]=(fromS[i]&&fromG[i]);
	ll INF =1e18;
	vector<ll> res(n,-INF);
	res[0]=0;
	rep(i,n){
		bool upd=false;
			rep(j,m){
				edge e=edges[j];
				if(!ok[e.from]||!ok[e.to])continue;
				if(res[e.from]==-INF)continue;
				if(res[e.to]<res[e.from]+e.cost){
					res[e.to]=res[e.from]+e.cost;
					upd=true;
					if(i==n-1){
					    cout<<"inf"<<endl;
					    return 0;
					}
				}
			}
		if(!upd)break;
	}
	cout<<res[n-1]<<endl;
}