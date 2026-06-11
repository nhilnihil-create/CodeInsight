#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<60)
#define mod 1000000007
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


// aとbの最大公約数
ll gcd(ll a, ll b) {
	if (a < b) gcd(b, a);
	ll r;
	while ((r = a%b)) {
		a = b;
		b = r;
	}
	return b;
}

// ax+by=1の解
ll extgcd(ll a, ll b, ll& x, ll& y){
	ll d = a;
	if (b != 0){
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}

// mod mでのaの逆数
ll mod_inverse(ll a, ll m){
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x%m) % m;
}


signed main(){

	int H, W, A, B;
	cin >> H >> W >> A >> B;
	
	int fact[200001], inv_fact[200001];
	fact[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i <= 200000; i++){
		fact[i] = fact[i - 1] * i % mod;
		inv_fact[i] = mod_inverse(fact[i], mod);
	}

	int r = 0;
	for (int i = 0; i < H - A; i++){
		int a = ((fact[B + i - 1] * inv_fact[i]) % mod) * inv_fact[B-1] % mod;
		int b = ((fact[H + W - B - 2 - i] * inv_fact[H - i - 1]) % mod * inv_fact[W - B - 1]) % mod;
		r = r + a*b % mod;
		r %= mod;
	}

	cout << r << endl;

	return 0;
}
