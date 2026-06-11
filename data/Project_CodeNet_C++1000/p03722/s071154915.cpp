#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>

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

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define P pair<ll, ll>
#define sz(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<ll>
#define COUT(x) cout<<(x)<<endl
#define MA map<ll,ll>
#define SE set<ll>
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,VE,greater<ll>>
#define COUT(x) cout<<(x)<<endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
bool prime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}


const long long MOD = 1000000007;
const long long INF = 1e17;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m; cin >> n >> m;
	VE a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		c[i] *= -1;
	}
	VE dist(n); rep(i, n)dist[i] = INF;
	dist[0] = 0;
	rep(tmp, n - 1) {
		rep(i, m) {
			if (dist[a[i] - 1] == INF)continue;
			if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
				dist[b[i] - 1] = dist[a[i] - 1] + c[i];
			}
		}
	}
	int ans = dist[n - 1];
	VE negative(n); rep(i, n)negative[i] = false;
	rep(tmp, n) {
		rep(i, m) {
			if (dist[a[i] - 1] == INF)continue;
			if (dist[b[i] - 1] > dist[a[i] - 1] + c[i]) {
				dist[b[i] - 1] = dist[a[i] - 1] + c[i];
				negative[b[i] - 1] = true;
			}
			if (negative[a[i] - 1] == true) {
				negative[b[i] - 1] = true;
			}
		}
	}
	if (negative[n - 1])cout << "inf" << endl;
	else cout << ans * (-1) << endl;
	return 0;
}
