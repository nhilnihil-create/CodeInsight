#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
vector<int> V[100010];
void dfs(int x, int dist, vector<int> &v){
    if(v[x])return;
    v[x] = dist;
    for(auto next:V[x]){
        dfs(next, dist+1, v);
    }
}
main(){
    int N;
    cin >> N;
    rep(i,0,N-1){
        int a,b;
        cin >> a >> b;
        a--,b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    vector<int> distA(N), distB(N);
    dfs(0, 1, distA);
    dfs(N-1, 1, distB);
    //for(auto i:distA)cout << i << " ";cout << endl;
    //for(auto i:distB)cout << i << " ";cout << endl;
    int cnt = 0;
    rep(i,0,N){
        cnt += (distA[i] <= distB[i] ? 1 : -1);
    }
    //cout << cnt << endl;
    if(cnt > 0)cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}