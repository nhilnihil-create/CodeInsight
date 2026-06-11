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
int A[200010], B[200010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    
    rep(i, N) cin >> A[i];
    rep(i, N) B[A[i] - 1] = i;
    set<int> st;
    st.insert(-1);
    st.insert(N);
    int ans = 0;
    rep(i, N) {
        auto itr = st.lower_bound(B[i]);
        int r = *itr;
        itr--;
        int l = *itr;
        ans += (r - B[i]) * (B[i] - l) * (i + 1);
        //cout << r << " " << l << endl;
        st.insert(B[i]);
    }
    cout << ans << endl;



    return 0;
}
