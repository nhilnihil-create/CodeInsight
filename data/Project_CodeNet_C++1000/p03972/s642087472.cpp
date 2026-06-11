#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long 

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int W, H;
    cin >> W >> H;
    int p[100010], q[100010];
    rep(i, W) cin >> p[i];
    rep(i, H) cin >> q[i];
    p[W] = INF;
    q[H] = INF;
    sort(p, p + W);
    sort(q, q + H);
    //rep(i, W) cout << p[i] << " ";
    //rep(i, H) cout << q[i] << " ";
    //cout << endl;
    int ans = 0;
    int idx1 = 0, idx2 = 0;
    int w = W, h = H;
    while(idx1 + idx2 < H + W) {
        
        if(p[idx1] < q[idx2]) {
            ans += p[idx1] * (H - idx2 + 1);
            idx1++;
        } else {
            ans += q[idx2] * (W - idx1 + 1);
            idx2++;
        }
        //cout << idx1 << " " << idx2 << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
