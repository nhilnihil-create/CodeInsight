#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int u32;
typedef pair<int, int> p;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int Inf = (1<<30);
ll inf = (1LL<<60);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll modpow(ll a, ll b, ll M) {
	ll res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1) res = (res * a) % M;
		a = a * a % M;
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	int i;
	int count[110000];
	bool zero = false;
	for (i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (count[a] == 2) {
			cout << 0;
			return 0;
		}
		if (n % 2 == 0) {
			int N = n / 2;
			if (a > 1 + N * 2 || a % 2 == 0) {
				cout << 0;
				return 0;
			}
			count[a]++;
		}
		else {
			if (a == 0) {
				if (zero) {
					cout << 0;
					return 0;
				}
				else zero++;
			}
			else {
				int N = n / 2;
				if (a > N * 2 || a % 2 != 0) {
					cout << 0;
					return 0;
				}
				count[a]++;
			}
		}
	}
	if (n == 1)  cout << 1;
	else cout << modpow(2, n / 2, 1000000007);
	return 0;
}