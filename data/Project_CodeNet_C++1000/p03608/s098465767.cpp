#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M,R;
    cin >> N >> M >> R;
    vector<int> r(R);
    rep(i,R){
        int a;
        cin >> a;
        r[i]=a-1;
    }
    sort(r.begin(),r.end());
    vector<vector<ll>> dist(N,vector<ll>(N,INF));
    rep(i,M){
        int A,B,C;
        cin >> A >> B >> C;
        A--;B--;
        dist[A][B] = C;
        dist[B][A] = C;
    }

    // ワーシャルフロイド法
    rep(i,N) dist[i][i] = 0;
    for (int k = 0; k < N; ++k){
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = INF;
    do{
        ll tmp = 0;
        for(int i=1;i<R;i++){
            tmp += dist[r[i]][r[i-1]];
        }
        ans = min(ans,tmp);
    }while(next_permutation(r.begin(),r.end()));
    cout << ans << endl;
    return 0;
}