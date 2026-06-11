#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    string s;
    cin >> s;
    set<char> s_set;
    ll n = s.size();
    rep(i, n){
        s_set.insert(s[i]);
    }
    ll ans = LLONG_MAX;
    for(auto x: s_set){
        string s_(s);
        ll cnt = 0;
        while (true)
        {
            ll s_n = s_.size();
            bool flg = true;
            rep(i, s_n){
                if (s_[i] != x){
                    flg = false;
                }
            }
            if (flg){
                ans = min(ans, cnt);
                break;
            }

            cnt++;
            rep(i, s_n-1){
                if (s_[i] != x && s_[i+1] == x){
                    s_[i] = x;
                }
            }
            s_.pop_back();
        }
    }

    cout << ans << endl;


    return 0;
}
