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
int a[510][510];
int b[510][510];

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    if (w == W && h == H || h == 1 && w == 1) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, H) {
        rep(j, W) {
            if (j % w != w - 1)
                a[i][j] = 1000;
            else 
                a[i][j] -= (w - 1) * 1000 + 1;
        }
    }
    rep(j, W) {
        rep(i, H) {
            if (i % h != h - 1)
                b[i][j] = 1000;
            else 
                b[i][j] -= (h - 1) * 1000 + 1;
        }
    }
    int suma = 0, sumb = 0;
    rep(i, H) {
        rep(j, W) {
            suma += a[i][j];
            sumb += b[i][j];
        }
    }
    ///*
    if (suma < 0 && sumb < 0) {
        cout << "No" << endl;
        return 0;
    }
    //*/
    cout << "Yes" << endl;
    rep(i, H) {
        rep(j, W) {
            if (j != 0) cout << " ";
            if(suma > 0) cout << a[i][j];
            else cout << b[i][j];
        }
        cout << endl;
    }



    return 0;
}
