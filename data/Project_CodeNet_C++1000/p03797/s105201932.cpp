#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;


int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    ans += min(n,m/2);
    n-=ans;m-=ans*2;
    if(n){
        cout << ans << endl;
        return 0;
    }
    ans += m/4;
    cout << ans << endl;
    return 0;
}
