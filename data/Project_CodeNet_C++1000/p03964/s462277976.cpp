#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int u32;
typedef pair<int, int> p;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int Inf = 1000000000;
ll inf = 1000000000000;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
	int n;
	cin >> n;
	int i;
	int a[1100], b[1100];
	for (i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	ll T = 1;
	ll A = 1;
	for (i = 0; i < n; i++) {
		ll x = max((T + a[i] - 1) / a[i], (A + b[i] - 1) / b[i]);
		T = x * a[i];
		A = x * b[i];
	}
	cout << T + A;
	return(0);
}