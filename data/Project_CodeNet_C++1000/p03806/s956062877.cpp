#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

ll INF = 10000000000000;

int main(void){
    ll n, ma, mb;
    cin >> n >> ma >> mb;

    ll a[n], b[n], c[n];
    rep(i, 0, n){
        cin >> a[i] >> b[i] >> c[i];
    }

    ll d[n + 1][401][401];
    rep(i, 0, n + 1){
        rep(j, 0, 401){
            rep(k, 0, 401){
                d[i][j][k] = INF;
            }
        }
    }

    d[0][0][0] = 0;
    rep(i, 0, n + 1){
        rep(j, 0, 401){
            rep(k, 0, 401){
                if(i == 0){
                    continue;
                }else if(j - a[i - 1] < 0 || k - b[i - 1] < 0){
                    d[i][j][k] = d[i-1][j][k];
                }else{
                    d[i][j][k] = min(d[i-1][j][k], d[i-1][j - a[i - 1]][k - b[i - 1]] + c[i - 1]);
                }
            }
        }
    }

    ll ans = INF;
    rep(i, 1, 401){
        rep(j, 1, 401){
            if(ma * j == mb * i){
                ans = min(ans, d[n][i][j]);
            }
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}
