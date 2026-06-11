#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

vector<vector<P>> G(256, vector<P>());
int N, M, R, a, b, c, r;

void dijkstra(int f, vector<int> &dist){
	priority_queue<P, vector<P>, greater<P>> Q;
	dist[f] = 0;
	Q.emplace(dist[f], f);
	while(!Q.empty()){
		int ncost = Q.top().first;
		int nf = Q.top().second;
		Q.pop();
		if(ncost > dist[nf])continue;
		for(auto x:G[nf]){
			if(dist[x.first] > ncost + x.second){
				dist[x.first] = ncost + x.second;
				Q.emplace(dist[x.first], x.first);				
			}
		}
	}
}

int main(){
	cin >> N >> M >> R;
	int rts[R];
	G.resize(N);
	rep(i,R){
		cin >> r;
		--r;
		rts[i] = r;
	}
	sort(rts, rts + R);
	rep(i,M){
		cin >> a >> b >> c;
		--a; --b;
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
	vector<vector<int>> dist(N, vector<int>(N, inf));
	rep(i,N)dijkstra(i, dist[i]);
	int ans = inf;
	do{
		int e_ans = 0;
		rep(i,R-1){
			e_ans += dist[rts[i]][rts[i+1]];
		}
		ans = min(ans, e_ans);
	}while(next_permutation(rts, rts + R));
	cout << ans << endl;
	return 0;
}
