#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

ll ans;
ll N, W;
ll bw;
vector<ll> V[4];

void dfs(int idx, ll ww, ll vv){
    if(idx == 4){
        if(W >= ww){
            ans = max(ans, vv);
        }
        return;
    }
    ll sum = 0;
    dfs(idx+1, ww, vv);
    for(int j = 0; j < V[idx].size(); j++) {
        sum += V[idx][j];
        dfs(idx+1, ww+(j+1)*(bw+idx), vv+sum);
    }
}

int main(){
    cin >> N >> W;
    REP(i,N){
        ll w, v;
        cin >> w >> v;
        if(i == 0) bw = w;
        w -= bw;
        V[w].push_back(v);
    }

    for(int i = 0; i < 4; i++){
        sort(V[i].begin(), V[i].end(), greater<ll>());
    }

    dfs(0,0LL,0LL);
    cout << ans << endl;

    return 0;
}
