#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;


int main() {
    int n,m,r; cin >> n >> m >> r;
    vector<int> dest(r); 
    for (int i = 0; i < r ; i ++) {
        int town; cin >> town;
        dest[i] = town - 1;
    }
    sort(dest.begin(),dest.end());

    vector<vector<ll>> dist(n,vector<ll>(n,INF));
    for (int i = 0; i < m; i ++) {
        int a,b; cin >> a >> b;
        ll c; cin >> c;

        a --; b --;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 0; k < n; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll ans = INF;
    do {
        ll tmp = 0;
        for (int i = 0; i < r - 1; i ++) {
            tmp += dist[dest[i]][dest[i + 1]];
        }
        ans = min (ans, tmp);
    }while(next_permutation(dest.begin(),dest.end()));
    cout << ans << endl;
}