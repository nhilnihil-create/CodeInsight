#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
vector<int> graph[100010];
int d[2][100010];
void dfs(int x, int cost, int num){
    d[num][x] = cost;
    for(auto i:graph[x]){
        if(d[num][i] != INF)continue;
        dfs(i, cost + 1, num);
    }
}
main(){
    int N;
    cin >> N;
    rep(i,0,N-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rep(i,0,N)d[0][i] = d[1][i] = INF;
    dfs(0, 0, 0);
    dfs(N-1, 0, 1);
    int cnt = 0;
    rep(i,0,N)cnt += d[0][i] <= d[1][i] ? 1 : -1;
    if(cnt > 0)cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}