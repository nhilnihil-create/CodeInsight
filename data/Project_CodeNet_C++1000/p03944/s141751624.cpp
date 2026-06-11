#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<char>> g;
int main(){
    ll w, h, n; cin >> w >> h >> n;
    ll bt=0, top=h, left=0, right=w;
    REP(i, n){
        ll x, y, a;   cin >> x >> y >> a;
        
        if(a==1)    left = max(x, left);
        else if(a==3) bt = max(y, bt);
        else if(a==2) right=min(x, right);
        else top = min(y, top);
    }
    ll res = max(0LL, top-bt)*max(0LL, right-left);
    cout << res << endl;
    
}
