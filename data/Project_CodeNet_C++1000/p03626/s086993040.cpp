#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
#define low lower_bound
#define upp upper_bound
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define Rep(i,n) for (int i = (int)(n); i >= 0; i--)
#define all(vec) vec.begin(),vec.end()
#define rever(vec) reverse(all(vec));
#define cend cout << endl;
#define prique(T) priority_queue<T,vector<T>,greater<T>>
struct edge { int to, cost; };
typedef pair<int, int> P;
const int mod = 1e9 + 7, inf = 1e16;

int modpow(int x, int n) {
	if (n == 0) return 1;
	if (n % 2) return (x * modpow(x * x % mod, n / 2) % mod + mod) % mod;
	return (modpow(x * x % mod, n / 2) + mod) % mod;
}

int fact(int n) {
	int ans = 1;
	rep(i, n) {
		ans *= (i + 1);
		ans %= mod;
	}
	return (ans + mod) % mod;
}

int comb(int n, int r) {
	if (n < r) swap(n, r);
	if (n - r < r) r = n - r;
	return fact(n) * modpow(fact(n - r), mod - 2) % mod * modpow(fact(r), mod - 2) % mod;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

template <typename T>
void greater_sort(vector<T>& vec) {
	sort(all(vec), greater<T>());
	return;
}

int n;
char c[2][62];
int w;
int ans = 1;

signed main() {
	cin >> n;
	w = 0;
	rep(i, 2) {
		rep(j, n) {
			cin >> c[i][j];
		}
	}
	if (n == 1) {
		cout << 3 << endl;
		return 0;
	}
	while (w < n) {
        if (w == n - 1) {
            if(c[0][w] == c[1][w]) {
                if(c[0][w - 1] == c[1][w - 1]) {
                    ans *= 2;
                    ans %= mod;
                    break;
                }
                else break;
            }
        }
		else if (c[0][w] == c[0][w + 1]) {
			if (w == 0) {
				ans = 6;
			}
			else {
				if (c[0][w - 1] == c[1][w - 1]) {
					ans *= 2;
				}
				else {
					ans *= 3;
				}
			}
			ans %= mod;
			w += 2;
		}
		else {
			if (w == 0) {
				ans = 3;
			}
			else {
				if (c[0][w - 1] == c[1][w - 1]) {
					ans *= 2;
					ans %= mod;
				}
			}
			w++;
		}
	}
	cout << ans << endl;
}
