#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
#define INF 1e+9

int n;

void warshall_floyd(vector<vector<int> > &d) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int m,r; cin >> n >> m >> r;
    vector<int> R(r);
    vector<vector<int> > d(n,vector<int>(n));
    rep(i,n) rep(j,n) d[i][j] = INF;
    rep(i,r){
        cin >> R[i];
        R[i]--;
    } 
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
         --a,--b;
         d[a][b] = c;
         d[b][a] = c;
    }
    
    warshall_floyd(d);
    sort(R.begin(),R.end());
    ll ans = INF;
    do{
        ll res = 0;
        rep(i,r-1){
            res+=d[R[i]][R[i+1]];
        }
        ans = min(ans,res);
    } while(next_permutation(R.begin(),R.end()));
    cout << ans << endl;
}
