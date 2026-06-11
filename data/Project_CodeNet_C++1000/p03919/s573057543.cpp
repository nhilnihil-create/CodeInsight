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
    int H, W;
    cin >> H >> W;
    string S[H][W];
    rep(i, H) rep(j, W) cin >> S[i][j];
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == "snuke") {
                char tmp = 'A' + j;
                cout << tmp << i+1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
