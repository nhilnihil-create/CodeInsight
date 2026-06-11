#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    ll lb = a * (n-1) + b;
    ll ub = b * (n-1) + a;
    ll ans = ub - lb + 1;
    chmax(ans, 0LL);
    cout << ans << endl;
	return 0;
}