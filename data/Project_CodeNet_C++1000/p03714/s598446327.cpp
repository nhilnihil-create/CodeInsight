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
const ll INF = 1E+18;


int main(){
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i, 3*n) cin >> a[i];
    vector<ll> sum1(n+1);
    vector<ll> sum2(n+1);
    priority_queue<ll> q1;
    priority_queue<ll> q2;
    
    rep(i, n) {
        sum1[0] += a[i];
        q1.push(-a[i]);
        sum2[n] += a[i+2*n];
        q2.push(a[i+2*n]);
    }
    rep(i, n) {
        ll now = -q1.top();
        if (a[i+n]>now) {
            q1.pop();
            q1.push(-a[i+n]);
            sum1[i+1] = sum1[i] - now + a[i+n];
        }
        else sum1[i+1] = sum1[i];
    }
    rrep(i, n) {
        ll now = q2.top();
        if (a[i+n]<now) {
            q2.pop();
            q2.push(a[i+n]);
            sum2[i] = sum2[i+1] - now + a[i+n];
        }
        else sum2[i] = sum2[i+1];
    }
    ll ans = -INF;

    rep(i, n+1) {
        ll res = sum1[i] - sum2[i];
        chmax(ans, res); 
    }
    
    cout << ans << endl;
    return 0;
}
