#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<ll>> v;
vector<ll> cost;



int main(){
    ll w, h, n; cin >> w >> h >> n;
    ll l=0, r=w, t=h, b=0, res=0;
    rep(i, n){
        ll x, y, op;    cin >> x >> y >> op;
        if(op==1)   l = max(x, l);
        else if(op==3) b = max(y, b);
        else if(op==2) r = min(x, r);
        else t = min(y, t);
    }
    if(l<r && b<t) res = (r-l)*(t-b);
    cout << res << endl;
}
