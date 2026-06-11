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
int cnt[100010];
int cnt1[100010];
int cnt2[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int X[100010];
    rep(i, N) cin >> X[i];
    rep(i, N) cnt[X[i]]++;
    rep(i, N) cnt1[X[i] % M]++;
    int ans = 0;
    rep(i, M) {
        int tmp = 0;
        if(i != (M - i) % M) tmp = min(cnt1[i], cnt1[(M - i) % M]);
        else tmp = cnt1[i] / 2;
        ans += tmp;
        cnt2[i] += tmp;
        cnt2[(M - i) % M] += tmp;
        cnt1[i] -= tmp;
        cnt1[(M - i) % M] -= tmp;
    }
    // rep(i, M) cout << cnt2[i] << " ";
    // cout << endl;
    for(int i = 0; i <= M; i++) {
        for(int j = i; j <= 100000; j += M) {
            if(cnt2[i] > 0 && cnt[j] % 2 == 1) {
                cnt2[i]--;
                cnt[j]--;
            }
        }
    }
    for(int i = 0; i <= M; i++) {
        for(int j = i; j <= 100000; j += M) {
            if(cnt2[i] > 0) {
                int tmp = min(cnt2[i], cnt[j]);
                cnt2[i] -= tmp;
                cnt[j] -= tmp;
            }
        }
    }
    // rep(i, M) cout << cnt2[i] << " ";
    // cout << endl;
    rep(i, 100010) ans += cnt[i] / 2;
    cout << ans << endl;



    return 0;
}