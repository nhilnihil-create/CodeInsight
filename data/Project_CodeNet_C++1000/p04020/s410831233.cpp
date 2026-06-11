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
    ll tmp = 0;
    ll ans = 0;
    for(i = 0;i < n;++i){
        if(a.at(i) == 0){
            tmp = 0;
            continue;
        }else{
            ans += (a.at(i) + tmp)/2;
            tmp = (a.at(i) + tmp)%2;
        }
    }
    cout << ans << endl;
    return 0;
}