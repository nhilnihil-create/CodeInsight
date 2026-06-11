#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
int main(){
    int n;
    cin >> n;
    vector<ll> a(3*n);
    rep(i, 3*n) cin >> a[i];
 
    vector<ll> v(3*n-1), u(3*n-1);
 
    ll lsum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> lq;
    rep(i, n){
        lsum += a[i];
        lq.push(a[i]);
    }
    v[n-1] = lsum;
    for(int i=n; i<2*n; i++){
        ll t = lq.top();
        if(t < a[i]){
            lsum += (a[i] - t);
            lq.pop();
            lq.push(a[i]);
        }
        v[i] = lsum;
    }
 
//    rep(i, 3*n-1) cout << v[i] << ", ";
//    cout << endl;
 
    ll rsum = 0;
    priority_queue<ll> rq;
    reverse(all(a));
    rep(i, n){
        rsum += a[i];
        rq.push(a[i]);
    }
    u[n-1] = rsum;
    for(int i=n; i<2*n; i++){
        ll t = rq.top();
        if(t > a[i]){
            rsum += (a[i] - t);
            rq.pop();
            rq.push(a[i]);
        }
        u[i] = rsum;
    }
    reverse(all(u));
 
//    rep(i, 3*n-1) cout << u[i] << ", ";
//    cout << endl;
 
    ll ans = - 1e18;
    for(int i=n-1; i<2*n; i++){
        chmax(ans, v[i]-u[i]);
    }
    cout << ans << endl;
}