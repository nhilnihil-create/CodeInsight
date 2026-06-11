#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define For(i, a, b) for(int i = (a); i < (b); i++)
#define Rep(i, n) For(i, 0, (n))

const int inf = 999999999;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	ll n, m; cin >> n >> m;
	ll a = 0, b = 0, x[n], y[m];
	Rep(i, n){
		cin >> x[i];
		if(i > 0){
			ll s = x[i] - x[i - 1]; s %= mod;
			s *= (n - i) * i; s %= mod;
			a += s; a %= mod;
		}
	}
	Rep(i, m){
		cin >> y[i];
		if(i > 0){
			ll s = y[i] - y[i - 1]; s %= mod;
			s *= (m - i) * i; s %= mod;
			ll t = (a * s) % mod;
			b += t; b %= mod;
		}
	}
	cout << b << endl;
	return 0;
}