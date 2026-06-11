#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

ll dfs(ll cur, vector<vector<ll>>& net){
    vector<ll> tmp;
    for(ll nxt : net.at(cur)){
        tmp.push_back(dfs(nxt, net));
    }
    sort(ALL(tmp));
    ll ans = tmp.size();
    for(ll i = tmp.size() - 1; i >= 0; --i){
        ans = max(tmp.at(i) + (ll)tmp.size() - i, ans);
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> net(n);
    for(ll i = 1; i < n; ++i){
        ll ai;
        cin >> ai;
        ai--;
        net.at(ai).push_back(i);
    }
    cout << dfs(0, net) << endl;
    return 0;
}
