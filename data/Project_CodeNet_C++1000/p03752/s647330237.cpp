#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    ll bit;
    ll ans = 1e14;
    for(bit = 1;bit < (1 << n);++bit){
        vector<ll> b;
        for(i = 0;i < n;++i){
            if(bit & (1 << i)) b.push_back(i);
        }
        if(b.size() < k) continue;
        ll tmp = 0;
        ll tmpans = 0;
        j = 0;
        for(i = 0;i < n;++i){
            if(i < b.at(j)) tmp = max(tmp, a.at(i));
            else if(i == b.at(j)){
                if(tmp >= a.at(b.at(j))){
                    tmpans += tmp - a.at(b.at(j)) + 1;
                    tmp += 1;
                }else{
                    tmp = a.at(b.at(j));
                }
                ++j;
                if(j == b.size()) break;
            }
        }
        ans = min(ans, tmpans);
    }
    cout << ans << endl;
    return 0;
}