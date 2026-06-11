#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll w,h,n;
    cin >> w >> h >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> x[i] >> y[i] >> a[i];
    }

    vector<vector<bool>> mp(h, vector<bool>(w, true));
    
    for (ll i = 0; i < n; i++){
        if (a[i] == 1){
            for (ll j = 0; j < h; j++){
                for (ll k = 0; k < x[i]; k++){
                    mp[j][k] = false;
                }
            }
            continue;
        }
        if (a[i] == 2){
            for (ll j = 0; j < h; j++){
                for (ll k = x[i]; k < w; k++){
                    mp[j][k] = false;
                }
            }
            continue;
        }
        if (a[i] == 3){
            for (ll j = 0; j < w; j++){
                for (ll k = 0; k < y[i]; k++){
                    mp[k][j] = false;
                }
            }
            continue;
        }
        if (a[i] == 4){
            for (ll j = 0; j < w; j++){
                for (ll k = y[i]; k < h; k++){
                    mp[k][j] = false;
                }
            }
            continue;
        }
    }

    ll ans = 0;

    for (ll i = 0; i < h; i++){
        for (ll j = 0; j < w; j++){
            if (mp[i][j]){
                ans++;
            }
        }
    }

    cout << ans << endl;

}