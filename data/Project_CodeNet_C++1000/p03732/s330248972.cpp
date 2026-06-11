#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

ll sum[4][110];

int main(){
    ll N, W; cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i,N) cin >> w[i] >> v[i];
    vector<vector<ll>> vec(4);
    rep(i,N) vec[w[i] - w[0]].push_back(v[i]);
    rep(i,4) sort(RALL(vec[i]));
    rep(it,4){
        //累積和
        sum[it][0] = 0;
        for(int i = 0; i < 110; ++i){
            sum[it][i+1] = sum[it][i] + (i < vec[it].size() ? vec[it][i] : 0);
        }
    }
    ll ans = 0;
    for(int a = 0; a <= N && w[0] * a <= W; ++a){
        for(int b = 0; b+a <= N && w[0] * a + (w[0]+1) * b <= W; ++b){
            for(int c = 0; c+b+a <= N && w[0] * a + (w[0]+1) * b + (w[0]+2) * c <= W; ++c){
                int d = min((ll)N - a - b - c, (ll)(W - (w[0] * a + (w[0]+1) * b + (w[0]+2) * c))/(w[0] + 3));
                ll tmp = sum[0][a] + sum[1][b] + sum[2][c] + sum[3][d];
                //cout << a << b << c << d  << endl;
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}