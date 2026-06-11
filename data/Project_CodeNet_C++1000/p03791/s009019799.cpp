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
#define int long long
int x[100010];
stack<int> st;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N) cin >> x[i];
    int ans = 1;
    rep(i, N) {
        st.push(x[i]);
        int size = st.size();
        if (st.top() < size * 2 - 1) {
            ans = (ans * size) % mod;
            st.pop();
        }
    }
    rep(i, st.size()) {
        ans = (ans * (i + 1)) % mod;
    }
    cout << ans << endl;


    return 0;
}
