#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int N;
    ll W;
    cin >> N >> W;
    ll w[N],v[N];
    REP(i,N){
        cin >> w[i] >> v[i];
    }
    vector<ll> sum[4];
    REP(i,4){
        sum[i].push_back(0);
    }
    REP(i,N){
        sum[w[i] - w[0]].push_back(v[i]);
    }
    REP(i,4){
        sort(sum[i].begin() + 1, sum[i].end());
        reverse(sum[i].begin() + 1, sum[i].end());
    }
    REP(i,4){
        REP(j,sum[i].size() - 1){
            sum[i][j + 1] += sum[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < sum[0].size(); i++){
        for(int j = 0; j < sum[1].size(); j++){
            for(int k = 0; k < sum[2].size(); k++){
                for(int l = 0; l < sum[3].size(); l++){
                    if(w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l > W){
                        continue;
                    }
                    ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}