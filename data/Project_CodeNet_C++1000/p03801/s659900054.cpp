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
typedef pair<int, int> P;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    P p[100010];
    rep(i, N) {
        cin >> p[i].first;
        p[i].second = -i;
    }
    int ans[100010] = {};
    sort(p, p + N, greater<P>());
    int cnt = 1;
    int idx = -p[0].second;
    rep(i, N) {
        idx = min(idx, -p[i].second);
        int diff = p[i].first;
        if(i + 1 < N) diff -= p[i + 1].first;
        ans[idx] += diff * cnt;
        //cout << p[i].first << " " << p[i + 1].first << " " << cnt << " " << idx << endl;
        cnt++;
    }
    rep(i, N) {
        cout << ans[i] << endl;
    }


    return 0;
}
