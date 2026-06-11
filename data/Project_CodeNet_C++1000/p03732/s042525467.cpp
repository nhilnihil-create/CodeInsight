#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    ll N, W; cin >> N >> W;
    ll w[111], v[111];
    vector<ll> item[4];
    for(int i=0;i<N;++i) cin >> w[i] >> v[i];
    ll minw = w[0];
    for(int i=0;i<N;++i) w[i] -= minw;
    for(int i=0;i<N;++i) item[w[i]].push_back(v[i]);
    for(int i=0;i<4;++i) {
        sort(item[i].rbegin(), item[i].rend());
        for(int j=0; j < item[i].size(); ++j) item[i][j+1] += item[i][j];
    }


    ll ans = 0;
    for(int i=0; i <= item[0].size(); ++i) {
        for(int j=0; j <= item[1].size(); ++j) {
            for(int k=0; k <= item[2].size(); ++k) {
                for(int l=0; l <= item[3].size(); ++l) {
                    ll sumw = 0, sumv = 0;
                    if(i > 0) sumw +=  minw    * i, sumv += item[0][i-1];
                    if(j > 0) sumw += (minw+1) * j, sumv += item[1][j-1];
                    if(k > 0) sumw += (minw+2) * k, sumv += item[2][k-1];
                    if(l > 0) sumw += (minw+3) * l, sumv += item[3][l-1];
                    
                    if(sumw <= W) ans = max(ans, sumv);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}