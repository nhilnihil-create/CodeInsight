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
typedef pair<int, int> P;
#define int long long
int ans[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    P a[100010];
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    a[n] = {0, 0};
    sort(a, a + n, greater<P>());
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i, n) {
        int prev = cnt;
        REP(j, cnt, n - 1) {
            if(a[prev].first == a[j].first) {
                cnt++;
                que.push(a[j].second);
            }
            else break;
        }
        ans[que.top()] += cnt * (a[prev].first - a[cnt].first);
        // cout << que.top() << " " << cnt << " " << a[prev].first << " " << a[cnt].first << "->";
        // rep(i, n) cout << ans[i] << " ";
        // cout << endl;
        a[prev].first = a[cnt].first;
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }


    return 0;
}
