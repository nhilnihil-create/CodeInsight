//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> hen;
    map<ll, ll> mp;

    for(auto v : a) {
        mp[v]++;
        if(mp[v] == 2) {
            hen.push_back(v);
            mp[v] = 0;
        }
    }
    sort(hen.rbegin(), hen.rend());
    cout << (hen.size() < 2 ? 0 : hen[0] * hen[1]) << endl;
    return 0;
}
