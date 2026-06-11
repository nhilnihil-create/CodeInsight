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

bool exist[100010];
int cnt[100010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    exist[0] = true;
    rep(i, 100000) cnt[i] = 1;
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(exist[x]) {
            exist[y] = true;
        }
        cnt[x]--;
        cnt[y]++;
        if(cnt[x] == 0) exist[x] = false;
    }
    int ans = 0;
    rep(i, N) ans += (exist[i]);
    cout << ans << endl;
    return 0;
}
