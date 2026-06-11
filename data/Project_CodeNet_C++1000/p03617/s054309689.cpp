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
    // 0.25, 0.5, 1.0, 2.0 
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    ll a, b, c;
    a = min(q * 2, h);
    b = min(a * 2, s);
    c = min(b * 2, d);
    ll ans = 0;
    ans += (n / 2) * c;
    n %= 2;
    ans += n * b;

    cout << ans << endl;

    return 0;
}