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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> ans(h, vector<int>(w));
    int index = 0;
    rep(i, h) rep(j, w) {
        if (a[index]==0) index++;
        ans[i][j] = index+1;
        a[index]--;
    }
    rep(i, h) {
        if (i%2==1) {
            reverse(whole(ans[i]));
        }
        rep(j, w) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
