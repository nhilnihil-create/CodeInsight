#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
using ll = long long;
 
const ll INF = 1LL << 60;
ll dist[205][205];
 
int main(){
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> vr;
    rep(i,R){
        int r;
        cin >> r;
        r--;
        vr.push_back(r);
    }
    rep(i,205)rep(j,205){
        dist[i][j] = INF;
        dist[i][i] = 0;
    }
    rep(i,M){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(k, N) rep(i, N) rep(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 
    sort(vr.begin(), vr.end());
    ll ans = INF;
    do{
        ll tmp = 0;
        for (int i = 1; i < vr.size(); i++){
            tmp += dist[vr[i]][vr[i - 1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(vr.begin(), vr.end()));
    cout << ans << endl;
    return 0;
}