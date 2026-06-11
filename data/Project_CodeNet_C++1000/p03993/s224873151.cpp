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
        --a.at(i);
    }
    ll ans = 0;
    for(i = 0;i < n;++i){
        j = a.at(i);
        if(i < j && a.at(j) == i) ++ans;
    }
    cout << ans << endl;

    return 0;
}