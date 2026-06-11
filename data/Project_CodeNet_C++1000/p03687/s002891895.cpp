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
    ll ans = 1e9;
    for(i = 'a';i <= 'z';++i){
        char tmpchar = i;
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