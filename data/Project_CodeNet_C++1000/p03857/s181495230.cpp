#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
//---------------------------------------------------
//ライブラリゾーン！！！！
#define int long long
#define str string
#define rep(i,j) for(int i=0;i<(int)(j);i++)
typedef long long ll;
typedef long double ld;
const ll inf = 4523372036854775807;
const ll Mod = 1000000007;
short gh[2][4] = { { 0,0,-1,1 },{ -1,1,0,0 } };
struct P {
	ll pos, cost;
};
bool operator<(P a, P b) { return a.cost < b.cost; }
bool operator>(P a, P b) { return a.cost > b.cost; }
struct B {//隣接リスト表現
	ll to, cost;
};
struct S {//辺の情報を入れる変数
	int from, to, cost;
};
struct H {
	int x, y;
};
bool operator<(H a, H b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool operator>(H a, H b) {
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}
ll gcm(ll i, ll j) {//最大公約数
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcm(j%i, i);
}
ld rad(ld a, ld b, ld c, ld d) {
	return sqrt(pow(a - c, 2) + pow(b - d, 2));
}//rad＝座標上の2点間の距離
int ari(int a, int b, int c) {
	return (a + b)*c / 2;
}//等差数列の和
bool suf(ld a, ld b, ld c, ld d) {
	if (b <= c || d <= a) return 0;
	return 1;
}//[a,b),[c,d)
//---------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++
int pa[300000], n, k, l, ch[300000], pa2[300000];
int root(int x) {
	if (pa[x] == x)
		return x;
	return pa[x] = root(pa[x]);
}
void unite(int x, int y) {
	x = root(x); y = root(y);
	pa[x] = y;
}
int root2(int x) {
	if (pa2[x] == x)
		return x;
	return pa2[x] = root2(pa2[x]);
}
void unite2(int x, int y) {
	x = root2(x); y = root2(y);
	pa2[x] = y;
}
H a[300000];
signed main() {
	cin >> n >> k >> l;
	for (int i = 1; i <= n; i++)
		pa[i] = i, ch[i] = 1, pa2[i] = i;
	for (int i = 0; i < k; i++) {
		int p, q;
		cin >> p >> q;
		unite(p, q);
	}
	for (int i = 0; i < l; i++) {
		int s, r;
		cin >> s >> r;
		unite2(s, r);
	}
	for (int i = 1; i <= n; i++)
		a[i] = H{ root(i),root2(i) };
	sort(a + 1, a + n + 1);
	cout << upper_bound(a + 1, a + n + 1, H{ root(1),root2(1) }) - lower_bound(a + 1, a + n + 1, H{ root(1),root2(1) });
	for (int i = 2; i <= n; i++)
		cout << " " << upper_bound(a + 1, a + n + 1, H{ root(i),root2(i) }) - lower_bound(a + 1, a + n + 1, H{ root(i),root2(i) });
	cout << endl;
	getchar(); getchar();
}