#include "bits/stdc++.h"
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
int K[6] = {0, 3, 4, 0, 3, 4};

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int ans = 0;
    int T[7];
    rep(i, 7) cin >> T[i];
    ans += T[1] * 2;
    int original[7] = {};
    rep(i, 7) original[i] = T[i];
    rep(i, 3) {
        ans += (T[K[i]] / 2) * 4;
        T[K[i]] -= (T[K[i]] / 2) * 2;
    }
    if (T[0] == T[3] && T[3] == T[4] && T[0] == 1) {
        ans += 6;
    }
    else {
        rep(i, 3) {
            if (T[K[i]] == T[K[i + 1]] && T[K[i]] == 1 && original[K[i + 2]] >= 2) {
                ans += 2;
                break;
            }
        }
    }
    cout << ans / 2 << endl;

    return 0;
}
