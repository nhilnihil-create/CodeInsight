//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,M;
//i->jにコストcで行けるならば、集合adj[i]は要素(j,c)を含む
vector<vector<pair<LL,LL>>> adj;
//i->jにコストcで行けるならば、集合adj_rev[j]は要素(i,c)を含む
vector<vector<pair<LL,LL>>> adj_rev;

LL ans = 0;

//点startからiに行けるかどうかを、隣接行列adを使ってもとめ、dist[i]として返す
vector<LL> dfs(LL start,vector<vector<pair<LL,LL>>>& ad){
	vector<LL> dist(N+1,0);
	dist[start] = 0;
	queue<LL> q;
	q.push(start);
	while(!q.empty()){
		LL now = q.front();
		q.pop();
		dist[now] = 1;
		for(auto next_node:ad[now]){
			LL next = next_node.first;
			if(dist[next]==0){
				dist[next] = 1;
				q.push(next);
			}
		}
	}
	return dist;
}

void solve(){
	//点1から点iに行けるかどうかを計算
	vector<LL> to = dfs(1,adj);
	//点iから点Nに行けるかどうかを計算
	vector<LL> from = dfs(N,adj_rev);

	//ベルマンフォード法
	//点1から点iまでの距離をdist[i]とおく
	vector<LL> dist(N+1,INF);
	//点1から1への距離は0
	dist[1] = 0;
	bool update = true;
	int step = 0;//何ループかかったか
	while(update){
		update = false;
		for(int now=1;now<=N;now++){
			for(auto next_pair:adj[now]){
				LL next = next_pair.first;
				LL cost = next_pair.second;
				if(to[next] && from[next] && to[now] && from[now]){
					LL new_dist = dist[now] + cost;
					if(dist[next]>new_dist){
						dist[next] = new_dist;
						update = true;
					}
				}
			}
		}
		step++;
		if(step>N){
			ans = -1;
			return;
		}
	}
	ans = -dist[N];
}

int main(){
    cin >> N >> M;
    adj = vector<vector<pair<LL,LL>>>(N+1);
    adj_rev = vector<vector<pair<LL,LL>>>(N+1);
    for(int i=0;i<M;i++){
    	LL a,b,c; cin >> a >> b >> c;
    	adj[a].push_back(pair<LL,LL>(b,-c));
    	adj_rev[b].push_back(pair<LL,LL>(a,-c));
    }

    solve();

    if(ans==-1) cout << "inf" << endl;
    else cout << ans << endl;
    return 0;
}