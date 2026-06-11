#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<pair<ll,ll>> t(n);
    ll tmp = -1;
    for(i = 0;i < n;++i){
        cin >> t.at(i).first;
        t.at(i).first != tmp ? t.at(i).second = 1 : t.at(i).second = 0;
        tmp = t.at(i).first;
    }
    vector<pair<ll,ll>> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i).first;
    }
    tmp = -1;
    for(i = 0;i < n;++i){
        a.at(n-1-i).first != tmp ? a.at(n-1-i).second = 1 : a.at(n-1-i).second = 0;
        tmp = a.at(n-1-i).first;
    }
    ll ans = 1;
    ll MOD = 1e9+7;
    for(i = 0;i < n;++i){
        if(t.at(i).second == 0 && a.at(i).second == 0){
            ans *= min(t.at(i).first, a.at(i).first);
            ans %= MOD;
        }else if(t.at(i).second == 1 && a.at(i).second == 1){
            if(t.at(i).first != a.at(i).first){
                cout << 0 << endl;
                return 0;
            }
        }else{
            if(t.at(i).second == 0){
                if(t.at(i).first < a.at(i).first){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(a.at(i).first < t.at(i).first){
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}