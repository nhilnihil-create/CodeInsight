#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a, b))*b;
}

int main(){
    int n;
    cin >> n;

    ll ans = 1;
    rep(i, n) {
        ll t;
        cin >> t;
        ans = lcm(ans, t);
    }
    
    cout << ans << endl;
    return 0;
}
