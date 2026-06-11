#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int digits(ll n){
	int res = 0;
	while(n > 0){
		n /= 10;
		res++;
	}
	return res;
}

int f(ll x, ll y){
    return max(digits(x), digits(y));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    int ans = digits(n);
    for(ll a = 1; a*a <= n; ++a){
        if(n%a != 0) continue;
        ll b = n / a;
        chmin(ans, f(a, b));
    }
    cout << ans << endl;
    return 0;
}