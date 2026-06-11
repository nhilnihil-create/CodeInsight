#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a,b,c,d,n;
    ll ans=0;
    cin >> a >> b >> c >> d >> n;
    vector<pair<ll,char>>p;
    p.push_back(make_pair(a * 8, 'a'));
    p.push_back(make_pair(b * 4, 'b'));
    p.push_back(make_pair(c * 2, 'c'));
    p.push_back(make_pair(d, 'd'));
    sort(all(p));
    if (n >= 2)ans = p[0].first * ll(n / 2);
    if (n % 2 != 0) {
        if (p[0].second != 'd')ans += (p[0].first / 2);
        else ans += (p[1].first / 2);
    }
    cout << ans << endl;
    return 0;
}
