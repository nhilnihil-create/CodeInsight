#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int n;
const int V_MAX = 205;
ll d[V_MAX][V_MAX];

void warshall_floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(d[i][k] == INF) continue;
            for(int j = 0; j < n; j++){
                if(d[k][j] == INF) continue;
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    int m,k; cin >> n >> m >> k;
    vector<int> r(k);
    rep(i,k){
        cin >> r[i];
        r[i]--;
    }
    sort(all(r));
    rep(i,n) rep(j,n){
        if(i == j) d[i][i] = 0;
        else d[i][j] = INF;
    }
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    warshall_floyd();
    ll ans = INF;
    do{
        ll tmp = 0;
        rep(i,k-1){
            tmp += d[r[i]][r[i+1]];
        }
        ans = min(ans,tmp);
    }while(next_permutation(all(r)));
    cout << ans << endl;
}