#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    map<ll,int> ma;
    rep(i,n){
        int a; cin >> a;
        ma[-a]++;
    }
    vector<ll> big;
    ll ans = 0;
    auto itr = ma.begin();
    if(itr->second >= 4){
        ans = itr->first * itr->first;
        cout << ans << endl;
        return 0;
    }
    for(auto elem : ma){
        ll key = -1 * elem.first;
        int value = elem.second;
        if(value >= 2) big.push_back(key);
        if(big.size() == 2) break;
    }
    if(big.size() < 2){
        cout << 0 << endl;
        return 0;
    }
    ans = big[0] * big[1];
    cout << ans << endl;
    return 0;
}