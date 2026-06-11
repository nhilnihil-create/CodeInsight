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
int n;
int a[100000];
vector<int>b;
vector<H>ans;
signed main() {
	cin >> n;
	int ma = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > ma) {
			b.push_back(i);
			ma = a[i];
		}
	}
	priority_queue<int>p;
	int sum = 0;
	for (int i = n - 1; i > b[b.size() - 1]; i--) {
		p.push(a[i]);
	}
	for (int i = b.size() - 1; i > 0; i--) {
		int res = (a[b[i]] - a[b[i - 1]])*sum;
		while (!p.empty() && p.top() >= a[b[i - 1]]) {
			res += p.top() - a[b[i - 1]];
			sum++;
			p.pop();
		}
		for (int j = b[i]; j > b[i - 1]; j--) {
			if (a[j] >= a[b[i - 1]]) {
				res += a[j] - a[b[i - 1]];
				sum++;
			}
			else p.push(a[j]);
		}
		ans.push_back(H{ b[i], res });
	}
	int rep = a[0] * sum;
	p.push(a[0]);
	while (!p.empty()) {
		rep += p.top();
		p.pop();
	}
	ans.push_back(H{ 0,rep });
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i].y << endl;
		for (int j = ans[i].x + 1; j < (i == 0 ? n : ans[i - 1].x); j++) {
			cout << 0 << endl;
		}
	}
}