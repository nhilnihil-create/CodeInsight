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
 
LL N,M,R;
vector<LL> r;
vector<vector<LL>> dist;
 
LL ans = INF;
 
void solve(){
	for(int i=1;i<=N;i++) dist[i][i] = 0;
	//ワーシャルフロイド
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	sort(r.begin(),r.end());
	do{
		LL sum = 0;
		for(int i=0;i<=R-2;i++) sum += dist[r[i]][r[i+1]];
		ans = min(ans,sum);
	}while(next_permutation(r.begin(),r.end()));
}
 
int main(){
    cin >> N >> M >> R;
    r = vector<LL>(R);
    for(int i=0;i<R;i++) cin >> r[i];
    dist = vector<vector<LL>>(N+1,vector<LL>(N+1,INF));
    for(int i=0;i<M;i++){
    	LL a,b,c;cin >> a >> b >> c;
    	dist[a][b] = c;
    	dist[b][a] = c;
    }
 
    solve();
 
    cout << ans << endl;
    return 0;
}