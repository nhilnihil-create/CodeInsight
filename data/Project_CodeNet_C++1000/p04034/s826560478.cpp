#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
int main(){
    ll n, m;
    cin >> n >> m;
    ll x[m], y[m];
    for (ll i = 0; i < m;i++){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    bool red[n];
    ll all[n];
    for (ll i = 0; i < n;i++){
		if(i==0){
            red[i] = true;
            all[i] = 1;
        }
		else{
            red[i] = false;
            all[i] = 1;
        }
    }
    for (ll i = 0; i < m;i++){
		if(red[x[i]]){
            red[y[i]] = true;
		    all[x[i]]--;
			all[y[i]]++;
            if (all[x[i]] == 0) red[x[i]] = false;
        }
		else {
		    all[x[i]]--;
			all[y[i]]++;
		}
    }
    ll cnt = 0;
    for (ll i = 0; i < n;i++){
        if (red[i]) cnt++;
    }
    cout << cnt << endl;
}