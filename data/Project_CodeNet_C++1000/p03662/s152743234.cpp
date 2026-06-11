
#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)


int n, a, b, d1[100009], d2[100009]; vector<int> g[100009];
void dfs(int pos, int pre, int m) {

	//初回以外は距離を加算する。
	//両端からやる操作で使いまわすためmで管理。
	if (pre != -1) {
		if (m == 0) d1[pos] = d1[pre] + 1;
		if (m == 1) d2[pos] = d2[pre] + 1;
	}

	//隣接リストが空なら勝手に次にいけないので、あえて指定しなくても勝手に止まる。

	//posから行ける頂点へ
	for (int i : g[pos]) {

		//逆流防止
		if (i == pre) continue;


		dfs(i, pos, m);
	}
}
int main() {
	
	//入力
	cin >> n;

	//無向グラフなので両方に辺を張る
	for (int i = 1; i < n; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	//フェネック側から探索
	dfs(0, -1, 0);

	//すぬけ側から探索
	dfs(n - 1, -1, 1);

	//全部の頂点について
	//どっちからいったほうが近いか数える。
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++) {
		if (d1[i] <= d2[i]) c1++;
		else c2++;
	}
	cout << (c1 > c2 ? "Fennec" : "Snuke") << endl;
	return 0;
}