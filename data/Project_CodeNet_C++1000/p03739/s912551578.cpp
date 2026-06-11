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
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    ll ans = 1e18;
    ll tmp = 0;
    ll tmpsum = 0;
    for(i = 0;i < n;++i){
        tmpsum += a.at(i);
        if(i%2){
            if(tmpsum <= 0){
                tmp += abs(tmpsum) + 1;
                tmpsum = 1;
            }
        }else{
            if(tmpsum >= 0){
                tmp += abs(tmpsum) + 1;
                tmpsum = -1;
            }
        }
    }
    ans = min(ans, tmp);
    tmp = 0;    tmpsum = 0;
    for(i = 0;i < n;++i){
        tmpsum += a.at(i);
        if(i%2){
            if(tmpsum >= 0){
                tmp += abs(tmpsum) + 1;
                tmpsum = -1;
            }
        }else{
            if(tmpsum <= 0){
                tmp += abs(tmpsum) + 1;
                tmpsum = 1;
            }
        }
    }
    ans = min(ans, tmp);
    cout << ans << endl;
    return 0;
}