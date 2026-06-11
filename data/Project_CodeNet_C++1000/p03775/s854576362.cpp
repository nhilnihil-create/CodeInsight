#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
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

int compareDigits(ll a, ll b){
	int A = digits(a);
	int B = digits(b);
	return max(A, B);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	int ans = digits(n);
	for(ll i = 1; i*i <= n; ++i){
		if(n%i != 0) continue;
		chmin(ans, compareDigits(i, n/i));
	}
	cout << ans << endl;
	return 0;
}