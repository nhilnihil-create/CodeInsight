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
#include<cassert>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<bitset>
#include<unordered_map>
using namespace std;
//---------------------------------------------------
//ライブラリゾーン！！！！
typedef long long ll;
typedef long double ld;
#define str string
#define rep(i,j) for(ll i=0;i<(long long)(j);i++)
#define all(a) (a).begin(),(a).end()
const ll Mod = 1000000007;
const ll gosenchou = 5000000000000000;
short gh[2][4] = { { 0,0,-1,1 },{ -1,1,0,0 } };
struct P {
	ll pos, cost;
};
bool operator<(P a, P b) { return a.cost < b.cost; }
bool operator>(P a, P b) { return a.cost > b.cost; }
struct B {//隣接リスト表現
	ll to, cost;
};
struct E {//辺の情報を入れる変数
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
ll gcm(ll i, ll j) {//最大公約数
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcm(j%i, i);
}
ld rad(H a, H b) {
	return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}//rad＝座標上の2点間の距離
ll ari(ll a, ll b, ll c) {
	return (a + b)*c / 2;
}//等差数列の和
ll fact(ll x, ll k, ll p) {//最大値、個数、あまり
	ll sum = 1;
	for (int i = 0; i < k; i++) {
		sum *= (x--);
		sum %= p;
	}
	return sum;
}//階乗(正）
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res*x%p;
		x = x*x%p;
		n >>= 1;
	}
	return res;
}//x^n%p
short ctos(char a) {
	return (int)(a - '0');
}
#define int long long
const long long Inf = 4523372036854775807;
const int inf = 15000000000;
//----------------------------------------------------
//++++++++++++++++++++++++++++++++++++++++++++++++++++
string s;
vector<int>a[26];
int b[26];
int c[26];
int d[300000];
int e[300000];
bool f[26];
signed main() {
	cin >> s;
	bool l = 0;
	int res = 0, rep = 1, sum = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (l) {
			rep++;
			l = 0;
		}
		int t = (int)(s[i] - 'a');
		a[t].push_back(i);
		if (!f[t]) {
			sum++;
			f[t] = 1;
		}
		if (sum == 26) {
			res++;
			l = 1;
			for (int i = 0; i < 26; i++) {
				f[i] = 0;
			}
			sum = 0;
		}
		e[i] = rep;
	}
	for (int i = 0; i < 26; i++) {
		a[i].push_back(250000);
		sort(all(a[i]));
	}
	res++;
	rep = res - 1;
	int k = 0;
	string h = "";
	for (int i = 0; i < res; i++) {
		for (int j = 0; j < 26; j++) {
			while (a[j][b[j]] < k) {
				b[j]++;
			}
			if (e[a[j][b[j]]] == rep) {
				h += (char)(j + 'a');
				k = a[j][b[j]] + 1;
				rep--;
				break;
			}
		}
	}
	cout << h << endl;
}