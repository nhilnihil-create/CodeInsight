#include <bits/stdc++.h>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()

typedef long long ll;

using namespace std;

int main(){

    int n;
    ll w;
    cin >> n >> w;

    vector<pair<ll, int>> goods;

    rep(i,n){
        ll weight;
        int value;
        cin >> weight >> value;

        goods.pback(mpair(weight, value)); 
    }

    int dp[n + 1][n + 1][n * 3 + 5] = {};

    rep(i,n){
        rep(j, n + 1){
            
            if(i < j) continue;
            rep(k, n * 3 + 1){

                //入れなかった場合
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);

                //入れた場合
                int dw = goods[i].first - goods[0].first;
                dp[i + 1][j + 1][k + dw] = max(dp[i + 1][j + 1][k + dw], dp[i][j][k] + goods[i].second);
            }
        }
    }

    int ans = 0;

    rep(i, n + 1){
        rep(j, n * 3 + 1){
            ll tmpw = i * goods[0].first + j;

            //cerr << tmpw << "," << dp[n][i][j] << " ";
            
            if(tmpw <= w){ 
                ans = max(ans, dp[n][i][j]);
            }
        }
        //cerr << endl;
    }

    cout << ans << endl;

    return 0;
}