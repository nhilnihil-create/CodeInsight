#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll pos[200010];
ll a[200010];

int main(){
    int n;
    cin >> n;

    rep(i, n){
        ll p;
        cin >> p;
        p--;
        pos[p] = i;
    }

    multiset<ll> st = {-1, n};
    ll ans = 0;
    rep(i, n){
        st.insert(pos[i]);
        auto it = st.lower_bound(pos[i]);
        auto l = prev(it);
        auto r = next(it);
        ans += (i+1) * (*it - *l) * (*r - *it);
    }

    cout << ans << endl;

    return 0;
}
