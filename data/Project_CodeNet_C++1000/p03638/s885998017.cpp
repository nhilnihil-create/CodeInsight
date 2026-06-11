#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int H, W; cin >> H >> W;
    int N; cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    int k = 0;
    vector<vector<string>> ans(H);
    for(int j = 0; j < H; ++j) {
        if(j % 2 == 0) {
            rep(i, W) {
                ans[j].pb(to_string(k + 1));
                --a[k];
                if(a[k] == 0)++k;
            }
        }else {
            rnr(i, W - 1, 0) {
                ans[j].pb(to_string(k + 1));
                --a[k];
                if(a[k] == 0)++k;
            }
            reverse(all(ans[j]));
        }
    }
    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}
