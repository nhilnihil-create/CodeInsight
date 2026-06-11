#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, N;
    cin >> H >> W >> N;
    int a[N], b[N];
    rep(i, N) cin >> a[i] >> b[i];
    ll ans[10] = {};
    map<pair<int, int>, int> ma;
    rep(i, N) {
        int x;
        int y;
        rep(k, 9) {
            x = a[i] + k % 3 - 1;
            y = b[i] + k / 3 - 1;
            if (x < 2 || x > H - 1 || y < 2 || y > W - 1) continue;
            else ma[make_pair(x, y)]++;
            //cout << x << ", " << y << endl;
        }

    }
    ans[0] = (ll)(H-2) * (W-2);
    rep(i, N) {
        int x;
        int y;
        rep(k, 9) {
            x = a[i] + k % 3 - 1;
            y = b[i] + k / 3 - 1;
            if (x < 2 || x > H - 1 || y < 2 || y > W - 1)  continue;
            else if (ma[make_pair(x, y)] != 0){
                ans[ma[make_pair(x, y)]]++;
                //dump(ma[make_pair(x, y)]);
            }
        }
    }
    rep(i, 9) ans[0] -= ans[i+1]/(i+1);
    rep(i, 10) cout << ans[i]/(max(1, i)) << endl;


    return 0;
}
