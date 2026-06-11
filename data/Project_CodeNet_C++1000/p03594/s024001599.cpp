#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<bitset>
#include<unordered_map>
#include <climits>
#include<fstream>
using namespace std;
//---------------------------------------------------
//library zone!!!!!
typedef long long ll;
typedef long double ld;
#define rep(i,j) for(ll i=0;i<(long long)(j);i++)
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
struct P {
	ll pos, cost;
};
bool operator<(P a, P b) { return a.cost < b.cost; }
bool operator>(P a, P b) { return a.cost > b.cost; }
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
};
bool operator<(E a, E b) {
	return a.cost < b.cost;
}
struct H {
	ll x, y;
};
bool operator<(H a, H b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool operator>(H a, H b) {
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}
bool operator==(H a, H b) {
	return a.x == b.x&&a.y == b.y;
}
bool operator!=(H a, H b) {
	return a.x != b.x || a.y != b.y;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j%i, i);
}
ld mod_pow(ld x, ll n, ll p) {
	ld res = 1;
	while (n > 0) {
		if (n & 1) res = res * x;
		x = x * x;
		n >>= 1;
	}
	return res;
}//x^n%p
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
signed main() {
	int h, w, d;
	cin >> h >> w >> d;
	char a[] = { 'R','G', 'B', 'Y' };
	char b[1000][1000];
	if (d % 2 == 1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << a[(i + j) % 2];
			}
			cout << endl;
		}
	}
	else {
		if (d == 2) {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if ((i / 2) % 2 == 0) {
						cout << a[j % 4];
					}
					else {
						cout << a[(j + 2) % 4];
					}
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					b[i][j] = '0';
				}
			}
			for (int i = 0; i < h; i += d) {
				int s = i, e = i + d - 2;
				int t = 0;
				bool inc = 0;
				for (int j = 0; j < w; j++) {
					if (j == 0) {
						t = (i / d) % 2;
					}
					for (int z = s; z <= e; z++) {
						b[z][j] = a[t];
					}
					if (inc) {
						if (e - s + 1 == d - 1) {
							inc = 0;
						}
						else { s--; e++; }
					}
					else {
						if (e - s + 1 == 1) {
							inc = 1;
							t = (t + 1) % 2;
						}
						else { s++; e--; }
					}
				}
			}
			for (int i = 0; i < h; i += d) {
				int s = i, e = i + d - 2;
				int r = 2;
				bool inc = 0;
				for (int j = 0; j < w; j++) {
					if (j == 0) {
						r = (((i / d)) % 2) + 2;
					}
					for (int z = s - 1; z >= 0; z--) {
						if (b[z][j] == '0') b[z][j] = a[r];
						else break;
					}
					for (int z = e + 1; z < h; z++) {
						if (b[z][j] == '0') b[z][j] = a[((r + 1)) % 2 + 2];
						else break;
					}
					if (inc) {
						if (e - s + 1 == d - 1) {
							inc = 0;
							r = ((r + 1) % 2) + 2;
						}
						else { s--; e++; }
					}
					else {
						if (e - s + 1 == 1) {
							inc = 1;
						}
						else { s++; e--; }
					}
				}
			}
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (b[i][j] == '0')
						b[i][j] = a[2];
					cout << b[i][j];
				}
				cout << endl;
			}
		}
	}
}
