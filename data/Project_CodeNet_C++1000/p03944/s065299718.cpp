#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int w, h, n;
    cin >> w >> h >> n;
    vector<vector<bool>> f(w, vector<bool>(h));
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        rep(i, w) rep(j, h) {
            if (a==1 && i<x) f[i][j] = true;
            if (a==2 && i>=x) f[i][j] = true;
            if (a==3 && j<y) f[i][j] = true;
            if (a==4 && j>=y) f[i][j] = true;
        }
    }
    int ans = 0;
    rep(i, w) rep(j, h) {
        if (!f[i][j]) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
