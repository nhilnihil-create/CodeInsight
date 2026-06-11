#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<string> ans(h+2);
    rep(i, h+2) {
        rep(j, w+2) {
            if (i==0 || i==h+1 || j==0 || j==w+1) {
                ans[i] += '#';
                continue;
            }
            ans[i] += a[i-1][j-1];
        }
    }
    rep(i, h+2) {
        cout << ans[i] << endl;
    }
    return 0;
}
