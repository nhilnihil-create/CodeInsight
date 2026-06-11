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

int A[310][310];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, N) {
        rep(j, M) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    int ans = N;
    bool used[310];
    rep(i, M) used[i] = true;
    rep(k, M - 1) {
        int cnt[310] = {};
        int tmp = 0;
        int idx = 0;
        rep(i, N) {
            rep(j, M) {
                if(!used[A[i][j]]) continue;
                cnt[A[i][j]]++;
                if(cnt[A[i][j]] > tmp) {
                    tmp = cnt[A[i][j]];
                    idx = A[i][j];
                }
                break;
            }
        }
        ans = min(ans, tmp);
        used[idx] = false;
    }
    cout << ans << endl;

    return 0;
}
