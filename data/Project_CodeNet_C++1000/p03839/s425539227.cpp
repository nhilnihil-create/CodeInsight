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


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    ll a[100010];
    rep(i, N) cin >> a[i];
    
    ll sum0 = 0, sum1 = 0;
    rep(i, N) sum1 += max(0LL, a[i]);
    rep(i, K) {
        sum1 -= max(0LL, a[i]);
        sum0 += a[i];
    }
    ll ans = sum1 + max(0LL, sum0);
    //cerr << sum0 << " " << sum1 << endl;
    rep(i, N - K) {
        sum1 = sum1 + max(0LL, a[i]) - max(0LL, a[K + i]);
        sum0 = sum0 - a[i] + a[K + i];
        ans = max(ans, max(0LL, sum0) + sum1);
        //cerr << sum0 << " " << sum1 << endl;
    }
    cout << ans << endl;

    return 0;
}
