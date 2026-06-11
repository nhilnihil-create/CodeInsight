#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = ll(1e18)+5;

int main() {
    ll N,M,R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    for(int i=0;i<R;i++){
        ll a;
        cin >> a;
        --a;
        r[i] = a;
    }

    ll d[N][N];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        if(i==j){
            d[i][j] = 0;
        }else{
            d[i][j] = INF;
        }
    }
    for(int i=0;i<M;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        d[a][b] = c;
        d[b][a] = c;
    }

    //ワーシャルフロイド法
    for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    }

    sort(r.begin(),r.end());
    ll ans= INF;
    do{
        ll temp = 0;
        for(int i=1;i<r.size();i++){
            temp += d[r[i-1]][r[i]];
        }
        ans = min(ans,temp);
    }while(next_permutation(r.begin(),r.end()));

    cout << ans << endl;

    return 0;
}