#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF=1e18;

ll cost[300][300];
int main(){
    int n,m,R; cin >> n >> m >> R;
    vector<ll> v(R);
    rep(i,R){
        cin >> v[i];
        v[i]--;
    }
    sort(v.begin(),v.end());
    rep(i,n+1){
        rep(j,n+1){
            if(i==j) cost[i][j]=0;
            else cost[i][j] = INF;
        }
    }
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    rep(k,n+1){
        rep(i,n+1){
            rep(j,n+1){
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }      
    }
    ll ans = INF;
    do{
        ll sum=0;
        for(int i=0;i+1<R;i++){
            sum += cost[v[i]][v[i+1]];
        }
        ans = min(ans,sum);
    }while(next_permutation(v.begin(),v.end()));
    cout << ans << endl;
}