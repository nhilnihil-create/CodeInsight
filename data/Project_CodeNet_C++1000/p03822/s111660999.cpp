//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/agc009/tasks/agc009_b

//参考：
//http://tutuz.hateblo.jp/entry/2018/10/09/052545

//ポイント：
//グラフとトーナメントを対応させ、DFSを行う

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

LL N;
vector<vector<LL>> adj;

LL ans = INF;

LL dfs(LL now=1,LL prev=-1){
	//頂点1を根としてみなした時、
	//頂点nowより下の木が表す
	//トーナメントの深さをこの関数は返す
	vector<LL> depth;
	for(auto next:adj[now]){
		if(next==prev) continue;
		depth.push_back(dfs(next,now));
	}
	if(depth.size()==0) return 0;
	sort(depth.begin(),depth.end(),greater<LL>());
	LL ret = -1;
	for(int i=0;i<depth.size();i++){
		depth[i] += (i+1);
		ret = max(ret,depth[i]);
	}
	return ret;
}

void solve(){
	ans = dfs();
}

int main(){
    cin >> N;
    adj = vector<vector<LL>>(N+1);
    for(int i=2;i<=N;i++){
    	LL a;cin >> a;
    	adj[i].push_back(a);
    	adj[a].push_back(i);
    }

    solve();

    cout << ans << endl;
    return 0;
}