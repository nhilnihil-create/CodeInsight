#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    ll lim, w1, maxv = 0;
    cin >> n >> lim;
    vector<ll> vec[4], vsum[4];
    rep(i, n){
        ll ww, vv;
        cin >> ww >> vv;
        if(i == 0) w1 = ww;
        vec[ww - w1].push_back(vv);
    }
    rep(i, 4){
        sort(vec[i].begin(), vec[i].end());
        reverse(vec[i].begin(), vec[i].end());
    }
    rep(i, 4){
        vsum[i].push_back(0);
        rep(j, vec[i].size())
            vsum[i].push_back(vsum[i][j] + vec[i][j]);
    }
    
    rep(x, vec[0].size()+1)
        rep(y, vec[1].size()+1)
            rep(z, vec[2].size()+1)
                rep(w, vec[3].size()+1){
                    if(x*w1 + y*(w1+1) + z*(w1+2) + w*(w1+3) > lim)
                        continue;
                    maxv = max(maxv,
                        vsum[0][x] + vsum[1][y]
                        + vsum[2][z] + vsum[3][w]);
                }
    
    cout << maxv << endl;
    return 0;
}