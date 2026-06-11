#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    ll n,w; cin >> n >> w;
    ll sw,value; cin >> sw >> value;

    vector<vector<ll>> item(4);
    item[0].push_back(value);

    for (ll i = 0; i < n - 1; i ++)  {
        ll weight,value; cin >> weight >> value;
        item[weight - sw].push_back(value);
    }


    for (ll i = 0; i < 4; i ++) {
        sort(item[i].begin(),item[i].end(),greater<ll>());
        for (ll j = 1; j < item[i].size(); j ++) {
            item[i][j] += item[i][j - 1];
        }
    }
    
    ll ans = 0;
    for (ll i = 0; i < item[0].size() + 1; i ++) {
        for(ll j = 0; j < item[1].size() + 1; j ++) {
            for (ll k = 0; k < item[2].size() + 1; k ++) {
                for (ll l = 0; l < item[3].size() + 1; l ++) {
                    if (sw * i + (sw + 1) * j + (sw + 2) * k + (sw  + 3) * l <= w) {
                        ll tmp = 0;
                        if (i > 0) tmp += item[0][i - 1];
                        if (j > 0) tmp += item[1][j - 1];
                        if (k > 0) tmp += item[2][k - 1];
                        if (l > 0) tmp += item[3][l - 1];
                        ans  = max(ans, tmp);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}