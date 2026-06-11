#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s;
    cin >> s;
    ll n = s.size();
    map<char,ll> mp;
    for(i = 0;i < n;++i){
        if(!mp.count(s.at(i))) mp[s.at(i)] = 0;
    }
    ll ans = 1e9;
    for(auto x:mp){
        char tmpchar = x.first;
        ll tmpn = n;
        ll tmpans = 0;
        string tmps = s;
        while(true){
            bool flag = true;
            rep(j,tmpn){
                if(tmps.at(j) != tmpchar){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = min(ans,tmpans);
                break;
            }
            for(j = 0;j < tmpn-1;++j){
                if(tmps.at(j) == tmpchar || tmps.at(j+1) == tmpchar){
                    tmps.at(j) = tmpchar;
                }
            }
            --tmpn;
            ++tmpans;
        }
    }
    cout << ans << endl;
    return 0;
}