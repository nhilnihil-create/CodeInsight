#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(int argc, char const *argv[]) {
    ll n;
	cin >> n;
	vector<int> a(n+1, 0), d(n);
	ll sum = 0;
	rep(i,n){
		cin >> a[i];
		sum += a[i];
	}
	rep(i,n-1){
		d[i] = a[i+1] - a[i];
	}
	d[n-1] = a[0] - a[n-1];
	ll cnt = n*(n+1)/2;
	if(sum%cnt != 0){
		cout << "NO" << endl;
		return 0;
	}
	ll k = sum / cnt;
	rep(i,n){
		if(d[i] > k || (k-d[i])%n != 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
    return 0;
}
