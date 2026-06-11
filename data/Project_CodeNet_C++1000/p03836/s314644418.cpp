#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans = "";
    ans += string(d-b, 'U') + string(c-a, 'R');
    ans += string(d-b, 'D') + string(c-a, 'L');
    ans += string(1, 'L') + string(d-b+1, 'U') + string(c-a+1, 'R') + string(1, 'D');
    ans += string(1, 'R') + string(d-b+1, 'D') + string(c-a+1, 'L') + string(1, 'U');
    cout << ans << endl;
    //printf("%.12f", ans);
}