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

int cnt[100010];
int cnt2[100010];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int X[100010];
    rep(i, N) cin >> X[i];
    rep(i, N) {
        cnt[X[i] % M]++;
        cnt2[X[i]]++;
    }
    // rep(i, M) cout << cnt[i] << " ";
    // cout << endl;
    int ans = 0;
    rep(i, M) {
        int a = i, b = (M - i) % M;
        int tmp = min(cnt[a], cnt[b]);
        if(a == b) tmp /= 2;
        ans += tmp;
        cnt[a] -= tmp;
        cnt[b] -= tmp;
    }
    // rep(i, M) cout << cnt[i] << " ";
    // cout << endl;
    rep(i, 100001) {
        if(cnt[i % M] > 1) {
            //cout << i << " " << cnt2[i] << endl;
            int tmp = min(cnt[i % M], cnt2[i]) / 2;
            ans += tmp;
            cnt[i % M] -= tmp * 2;
        }
    }
    cout << ans << endl;

    return 0;
}
