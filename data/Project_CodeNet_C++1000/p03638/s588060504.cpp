#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v;
    rep(i, n) {
        int a; cin >> a;
        rep(j, a) {
            v.push_back(i + 1);
        }
    }
    vector<vector<int>> ans(h, vector<int>(w));
    int y = 0, x = 0;
    rep(i, v.size()) {
        if(i > 0 && i % w == 0) {
            x = 0; 
            y++;
        }
        ans[y][x] = v[i];
        x++;
    }
    rep(i, h) {
        if(i % 2 == 1) {
            reverse(ALL(ans[i]));
        }
    }

    rep(i, h) {
        rep(j, w) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}