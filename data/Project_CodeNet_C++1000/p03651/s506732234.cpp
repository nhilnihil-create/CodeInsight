#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int a, g;
	cin >> g;
	int ma = g;
	rep(i,n-1){
		cin >> a;
		chmax(ma, a);
		g = gcd(g, a);
	}
	if(ma >= k && k%g == 0) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}