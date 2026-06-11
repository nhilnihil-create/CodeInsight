#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<bool>> need(n, vector<bool>(n, true));
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(a[i][j] > a[i][k] + a[k][j]){
                    puts("-1");
                    return 0;
                }
                if(a[i][j] == a[i][k] + a[k][j] && a[i][k] > 0 && a[k][j] > 0) need[i][j] = false;
            }
        }
    }

    ll ans = 0;
    rep(i,n){
        rep(j,n){
            if(need[i][j]) ans += a[i][j];
        }
    }
    ans /= 2LL;
    cout << ans << endl;
}