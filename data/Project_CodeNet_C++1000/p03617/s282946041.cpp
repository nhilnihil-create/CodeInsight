#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void chmax(ll &a, ll b) { a = min(a, b); }
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    n *= 4;
    chmax(b, a * 2);
    chmax(c, b * 2);
    chmax(d, c * 2);
    ll ans = d * (n / 8);
    n %= 8;
    ans += c * (n / 4);
    n %= 4;
    ans += b * (n / 2);
    n %= 2;
    ans += a * n;
    cout << ans << endl; 
    return 0;
}
