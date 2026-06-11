#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
template <typename T> bool chmax(T &a, const T b){if(a < b){a = b;return true;}return false;}
template <typename T> bool chmin(T &a, const T b){if(a > b){a = b;return true;}return false;}
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(i = 0;i < n;++i){
        rep(j,m){
            cin >> a.at(i).at(j);
            --a.at(i).at(j);
        }
    }
    vector<ll> kazu(m);
    for(i = 0;i < n;++i){
        ++kazu.at(a.at(i).at(0));
    }
    ll ans = 0;
    ll ind;
    for(i = 0;i < m;++i){
        if(chmax(ans, kazu.at(i))) ind = i;
    }

    vector<ll> now(n,0);
    set<ll> mita;
    for(i = 1;i < m;++i){
        mita.insert(ind);
        kazu.at(ind) = 0;

        ll tmp = 0;
        for(j = 0;j < n;++j){
            bool flag = false;
            while(mita.count(a.at(j).at(now.at(j)))){
                flag = true;
                ++now.at(j);
            }
            if(flag) ++kazu.at(a.at(j).at(now.at(j)));
        }
        for(j = 0;j < m;++j){
            if(chmax(tmp, kazu.at(j))) ind = j;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}