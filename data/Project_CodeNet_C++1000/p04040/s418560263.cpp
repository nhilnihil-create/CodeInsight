#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;
int H, W, A, B;
const int MAXH = 100010;
const int MAXW = 100010;
int mod = 1e9 + 7;

ll a[MAXW];
// (H + W)!
ll fact[MAXH + MAXW];
//(H + W)!^{-1}
ll invfact[MAXH + MAXW];

// a^n modを計算
ll modpow(ll a, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}

	return res;
}

ll modinv(ll a, ll m) {
	return modpow(a, m - 2, m);
}

ll modkaijo(ll n) {
	ll res = 1;
	while(n > 1) {
		res = (res % mod) * (n % mod);
		n--;
	}

	return res;
}

void init() {
	fact[0] = invfact[0] = 1;
	rep(i, 1, MAXH + MAXW) {
		fact[i] = (fact[i - 1] * i) % mod;
		invfact[i] = modinv(fact[i], mod);
	}
}

ll nCr(ll n, ll r) {
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> H >> W >> A >> B;
	init();

	memset(a, 0, sizeof(a));

	for(int i = W; i > B; i--) {
		(a[i] = nCr(i - 1 + H - A - 1, H - A - 1)) %= mod;
		(a[i] *= nCr(W - i + A - 1, A - 1)) %= mod;
	}

	ll rsl = 0;
	for(int i = W; i > B; i--) (rsl += a[i]) %= mod;

	cout << rsl % mod << endl;

}
