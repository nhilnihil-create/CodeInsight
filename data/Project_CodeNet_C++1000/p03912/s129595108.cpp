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

int cnt[100010];
int cnt1[100010];
int cnt2[100010];
int X[100010];
typedef pair<int, int> P;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int ans = 0;
    rep(i, N) cin >> X[i];
    rep(i, N) cnt[X[i]]++;
    //REP(i, 1, 100000) if(cnt[i] != 0) cout << i << " " << cnt[i] << endl;
    REP(i, 0, 100000) {
        if (cnt[i] % 2) {
            cnt1[i % M]++;
            cnt[i]--;
        }
        cnt2[i % M] += cnt[i];
    }
    //REP(i, 0, M - 1) cout << i << ": "<< cnt1[i] << " " << cnt2[i] << endl;
    rep(i, M + 1) {
        int num1 = i;
        int num2 = M - i;
        while (cnt1[num1] - cnt1[num2] >= 2 && cnt2[num2] >= 2) {
            cnt1[num2] += 2;
            cnt2[num2] -= 2;
        }
    }
    //REP(i, 0, M - 1) cout << i << ": "<< cnt1[i] << " " << cnt2[i] << endl;
    rep(i, M/2 + 1) {
        if ((i * 2) % M == 0) {
            ans += (cnt1[i] + cnt2[i]) / 2;
        } else {
            ans += min(cnt1[i], cnt1[M - i]) + cnt2[i]/2 + cnt2[(M - i) % M]/2;
        }
        //cout << i << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
