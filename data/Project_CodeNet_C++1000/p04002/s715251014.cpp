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
const ld pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989;
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
ll gcm(ll i, ll j) {//最大公約数
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcm(j%i, i);
}
//---------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++
struct A {
	int x, y;
};
bool operator<(A a, A b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool operator==(A a, A b) { return a.x == b.x&&a.y == b.y; }
vector<A>a;
int b[10];
signed main() {
	int h, w, n, x, y;
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x--; y--;
		if (x > 1 && y > 1)
			a.push_back(A{ x - 2,y - 2 });
		if (x > 1 && y > 0 && y < w - 1)
			a.push_back(A{ x - 2,y - 1 });
		if (x > 1 && y + 2 < w)
			a.push_back(A{ x - 2,y });
		if (x > 0 && x + 1 < h&&y > 1)
			a.push_back(A{ x - 1,y - 2 });
		if (x > 0 && x + 1 < h&&y > 0 && y + 1 < w)
			a.push_back(A{ x - 1,y - 1 });
		if (x > 0 && x + 1 < h&&y + 2 < w)
			a.push_back(A{ x - 1,y });
		if (x + 2 < h&&y > 1)
			a.push_back(A{ x,y - 2 });
		if (x + 2 < h&&y > 0 && y + 1 < w)
			a.push_back(A{ x,y - 1 });
		if (x + 2 < h&&y + 2 < w)
			a.push_back(A{ x,y });
	}
	sort(a.begin(), a.end());
	int sum = 0;
	for (int i = 0; i < a.size();) {
		int j = i;
		while (j < a.size() && a[j] == a[i])
			j++;
		sum++;
		b[j - i]++;
		i = j;
	}
	b[0] = (h - 2)*(w - 2) - sum;
	for (int i = 0; i < 10; i++)
		cout << b[i] << endl;
	getchar(); getchar();
}