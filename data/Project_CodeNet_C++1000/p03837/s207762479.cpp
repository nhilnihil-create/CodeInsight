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
#include <map> 
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

int N,M;
//点iと点j1,点j2,点j3...が隣接していて、
//かつそれぞれの移動コストがc1,c2,c3....である時
//adj[i] = {(c1,j1),(c2,j2),(c3,j3),.....}と決める
vector<vector<pair<LL,LL>>> adj;
vector<pair<LL,LL>> edge;

LL ans = 0;

void solve(){
	map<pair<LL,LL>,bool> is_passed; 
	for(int start=1;start<=N;start++){
		//pair<スタート地点からの最短距離,頂点番号>
		//pairのfirstが小さいものから取り出せる優先度付きキュー
		priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> q;
		vector<LL> dist(N+1,INF);//スタート地点と点iの最小距離をdist[i]とおく
		vector<LL> from(N+1,INF);//点iにどこからきたかを格納
		dist[start] = 0;//点startをスタート地点に決める
		q.push(pair<LL,LL>(0,start));

		while(!q.empty()){
			pair<LL,LL> now = q.top();q.pop();
			int now_v = now.second;
			if(dist[now_v]<now.first) continue;
			for(int i=0;i<adj[now_v].size();i++){
				LL next_v = adj[now_v][i].second;
				LL cost = adj[now_v][i].first;
				if(dist[next_v]>dist[now_v]+cost){
					dist[next_v] = dist[now_v] + cost;
					from[next_v] = now_v;
					q.push(pair<LL,LL>(dist[next_v],next_v));
				}
			}
		}

		for(int end=start+1;end<=N;end++){
			int now = end;
			while(now!=start){
				is_passed[pair<LL,LL>(now,from[now])] = 1;
				is_passed[pair<LL,LL>(from[now],now)] = 1;
				now = from[now];
			}
		}
	}

	for(int i=0;i<edge.size();i++){
		if(!is_passed[edge[i]]) ans++;
	}
}
 
int main(){
    cin >> N >> M;
    adj = vector<vector<pair<LL,LL>>>(N+1);
    for(int i=0;i<M;i++){
    	LL a,b,c;cin >> a >> b >> c;
    	adj[a].push_back(pair<LL,LL>(c,b));
    	adj[b].push_back(pair<LL,LL>(c,a));
    	edge.push_back(pair<LL,LL>(a,b));
    }
 
    solve();

    cout << ans << endl;
    return 0;
}