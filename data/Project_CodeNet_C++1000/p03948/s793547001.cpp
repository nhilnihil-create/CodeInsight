#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    ll N,T;
    cin >> N >> T;
    vector<ll> V(N);
    rep(i,0,N)cin >> V[i];
    ll difmax = 0, mini = V[0];
    int cnt = 0;
    rep(i,1,N){
        mini = min(mini, V[i]);
        if(difmax < V[i] - mini){
            difmax = V[i] - mini;
            cnt = 1;
        }else if(difmax == V[i] - mini){
            cnt++;
        }
    }
    cout << cnt << endl;
}