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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n, 0), dist(n-1);
    rep1(i, n){
        cin >> x[i];
        if (i!=0) dist[i-1] = a * abs(x[i]-x[i-1]);
    }
    ll ans = 0; 
    for (ll i: dist){
        if (i>b) ans += b;
        else ans += i;
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}