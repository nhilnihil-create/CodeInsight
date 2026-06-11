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
 
LL N;
//点iと点j1,点j2,点j3...が隣接していて、
//かつそれぞれの移動コストがc1,c2,c3....である時
//adj[i] = {(c1,j1),(c2,j2),(c3,j3),.....}と決める
vector<vector<pair<LL,LL>>> adj;

LL Q,K;
LL x[100000],y[100000];
 
vector<LL> ans;
 
void solve(){
	//ダイクストラ　計算量は辺の数をE,頂点数をVとした時,O(ElogV)
	//pair<スタート地点からの最短距離,頂点番号>
	//pairのfirstが小さいものから取り出せる優先度付きキュー
	priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> q;
	vector<LL> dist(N+1,INF);//スタート地点と点iの最小距離をdist[i]とおく
	dist[K] = 0;//点Kをスタート地点に決める
	q.push(pair<LL,LL>(0,K));

	while(!q.empty()){
		pair<LL,LL> now = q.top();q.pop();
		int now_v = now.second;
		if(dist[now_v]<now.first) continue;
		for(int i=0;i<adj[now_v].size();i++){
			LL next_v = adj[now_v][i].second;
			LL cost = adj[now_v][i].first;
			if(dist[next_v]>dist[now_v]+cost){
				dist[next_v] = dist[now_v] + cost;
				q.push(pair<LL,LL>(dist[next_v],next_v));
			}
		}
	}

	//この時点で、スタート地点(点K)と
	//点iの距離がdist[i]に保管されている
	for(int i=0;i<Q;i++){
		ans.push_back(dist[x[i]]+dist[y[i]]);
	}
}
 
int main(){
    cin >> N;
    adj = vector<vector<pair<LL,LL>>>(N+1);
    for(int i=0;i<N-1;i++){
    	LL a,b,c;cin >> a >> b >> c;
    	adj[a].push_back(pair<LL,LL>(c,b));
    	adj[b].push_back(pair<LL,LL>(c,a));
    }
    cin >> Q >> K;
    for(int i=0;i<Q;i++){
    	cin >> x[i] >> y[i];
    }
 
    solve();
 
    for(int i=0;i<Q;i++)cout << ans[i] << endl;
    return 0;
}