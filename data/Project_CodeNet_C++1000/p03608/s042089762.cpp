#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M,R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    rep(i,R){
        cin >> r[i];
        r[i]--;
    }
    sort(all(r));
    vector<ll> A(M),B(M),C(M);
    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }
    vector<vector<ll> > dist(N, vector<ll> (N));
    rep(i,N){
        rep(j,N){
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1000000000;
        }
    }
    rep(i,M){
        dist[A[i]][B[i]] = C[i];
        dist[B[i]][A[i]] = C[i];
    }
    for (ll k = 0; k < N; k++){
        for (ll i = 0; i < N; i++){
            for (ll j = 0; j < N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll num = 1;
    for (ll i = 1; i <= R; i++){
        num *= i;
    }
    ll ans = 1000000000;
    rep(i,num){
        ll ans_sub = 0;
        rep(j, R - 1){
            ans_sub += dist[r[j]][r[j + 1]];
        }
        ans = min(ans,ans_sub);
        next_permutation(all(r));
    }
    cout << ans << endl;
}
