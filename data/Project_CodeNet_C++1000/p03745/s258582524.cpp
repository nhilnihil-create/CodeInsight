#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans=0;
    ll flg = 0;
    cin >> a[0];
    rep(i, n-1){
        cin >> a[i+1];
        if (flg == 1){
            if (a[i] > a[i+1]){
                ans++;
                flg = 0;
            }
        }else if (flg == -1){
            if (a[i] < a[i+1]){
                ans++;
                flg = 0;
            }
        }else{
            if (a[i] < a[i+1]){
                flg = 1;
            }else if (a[i] > a[i+1]){
                flg = -1;
            }
        }
    }

    cout << ans+1 << endl;

    return 0;
}
