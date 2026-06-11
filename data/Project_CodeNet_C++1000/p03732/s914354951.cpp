#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int N; ll W;
    cin >> N >> W;
    ll w0, v0;
    vector<ll> value[4];
    cin >> w0 >> v0;
    value[0].push_back(v0);
    for(int i = 1; i < N; ++i) {
        ll w, v;
        cin >> w >> v;
        value[w - w0].push_back(v);
    }
    for(int i = 0; i < 4; ++i)
        sort(value[i].begin(), value[i].end(), greater<ll>());
    
    for(int i = 0; i < 4; ++i) 
        for(int j = 1; j < value[i].size(); ++j)
            value[i][j] += value[i][j-1]; //累積和
    
    

    ll res = 0;
    ll weight =0;
    for(ll i0 = 0; (weight = i0*w0) <= W && i0 <= value[0].size(); ++i0) {
        for(ll i1 = 0; weight + i1*(w0 + 1) <= W && i1 <= value[1].size(); ++i1) {
            weight += i1*(w0 + 1);
            for(ll i2 = 0; weight + i2*(w0 + 2) <= W && i2 <= value[2].size(); ++i2) {
                weight += i2*(w0 + 2);
                for(ll i3 = 0; weight + i3*(w0 + 3) <= W && i3 <= value[3].size(); ++i3) {
                    ll tmp = 0;
                    tmp += (i0 == 0) ? 0 : value[0][i0-1];
                    tmp += (i1 == 0) ? 0 : value[1][i1-1];
                    tmp += (i2 == 0) ? 0 : value[2][i2-1];
                    tmp += (i3 == 0) ? 0 : value[3][i3-1];
                    res = max(res, tmp);
                }
                weight -= i2*(w0 + 2);
            }
            weight -= i1*(w0 + 1);
        }
    }

    cout << res << endl;
    return 0;
}