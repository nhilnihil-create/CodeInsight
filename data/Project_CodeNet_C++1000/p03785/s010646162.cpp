#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> T(n);
    rep(i, n) cin >> T[i];
    sort(ALL(T));
    ll ans = 0;
    rep(i, n) {
        ans++;
        ll time = T[i] + k;
        ll cnt = 1;
        while(i + 1 < n && cnt < c && T[i + 1] <= time) {
            i++;
            cnt++;
        }
    }
    cout << ans << endl;

    return 0;
}