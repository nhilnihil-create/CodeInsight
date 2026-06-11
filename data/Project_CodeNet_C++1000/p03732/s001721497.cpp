#include <bits/stdc++.h>
#include <vector>
#include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9+5;
const int mod = 1e9+7;
int V;
int n,w;
vector<vector<int> > pq(4);

signed main(){
    cin >> n >> w;
    vector<int> ww(n);
    vector<int> vv(n);
    
    rep(i,n) {
        cin >> ww[i] >>vv[i];
    }
    int base = ww[0];
    // cout << base << endl;
    rep(i,n) {
        int weight = ww[i]-base;
        pq[weight].push_back(vv[i]);
        // cout << weight<<" "<<vv[i] << endl;
    }
    rep(i,4) {
        pq[i].push_back(0);
        sort(pq[i].begin(),pq[i].end(),greater<int>());
    }
    rep(i,4) {
        // cout << pq[i][0] << " "<< flush;
        FOR(j,1,pq[i].size()) {
            pq[i][j] += pq[i][j-1];
            // cout << pq[i][j]<<" " << flush;
        }
        // cout << "" << endl;
    }
    int ans = 0;
    rep(i,pq[0].size()) {
        int sum = 0;
        if(i!=0) sum +=pq[0][i-1];
        rep(j,pq[1].size()) {
            if(j!=0) sum +=pq[1][j-1];
            rep(k,pq[2].size()) {
                if(k!=0) sum +=pq[2][k-1];
                rep(l,pq[3].size()) {
                    if(l!=0) sum +=pq[3][l-1];
                    int weight = i*base+j*(base+1)+k*(base+2)+l*(base+3);
                    if(weight<=w)ans = max(ans, sum);
                    if(l!=0) sum -=pq[3][l-1];
                }
                if(k!=0) sum -=pq[2][k-1];
            }
            if(j!=0) sum -=pq[1][j-1];
        }
    }
    cout << ans << endl;
    return 0;

}
