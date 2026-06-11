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
    ll n;
    cin >> n;
    ll l = 3 * n;
    vector<ll> a(l);
    for(ll i = 0; i < l; i++) {
        cin >> a[i];
    }
    sort(ALL(a), greater<ll>());
    ll ans = 0;
    for(ll i = 1; i < 2 * n; i += 2) {
        ans += a[i];
    }
    cout << ans << endl;
    
    return 0;
}