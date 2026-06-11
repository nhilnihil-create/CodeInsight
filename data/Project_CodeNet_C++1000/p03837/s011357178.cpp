#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int INF = 1<<29;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    vector<vector<int>> dist(n, vector<int>(n,INF));
    rep(i,n) dist[i][i] = 0;
    rep(i,m){
        cin >> a[i] >> b[i] >> c[i];
        --a[i], --b[i];
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int res = 0;
    rep(i,m){
        if(c[i] > dist[a[i]][b[i]])res++;
    }
    cout << res << endl;
}