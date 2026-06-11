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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int a[200010];
    rep(i, N) cin >> a[i];
    rep(i, N) a[i]--;
    int b[200010];
    rep(i, N) b[a[i]] = i;
    set<int> st;
    st.insert(-1);
    st.insert(N);
    int ans = 0;
    rep(i, N) {
        int idx = b[i];
        auto itr2 = --st.lower_bound(idx);
        auto itr = st.lower_bound(idx);
        ans += (i + 1) * (*itr - idx) * (idx - *itr2);
        // cerr << idx << " " << *itr << " " << (*itr - idx) << endl;
        st.insert(idx);
    }
    cout << ans << endl;

    return 0;
}
// 2 1 3

// 1 3 2 4
// 1 1 1 1 
//   3 2 2
//     2 2
//       4