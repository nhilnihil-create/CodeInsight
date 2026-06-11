#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>
#include <cstring> 

using namespace std;

#ifdef DEBUG_MODE
#define DBG(n) n;
#else
#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;

vector<vector<int>> v(111111);

ll graphType[3];
ll pointColor[111111];

int main() {

	ll n, m; cin >> n >> m;

	REP(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		v[a].PB(b);
		v[b].PB(a);
	}

	REP(i, n) {
		if (pointColor[i] == 0) {
			queue<int> que;
			que.push(i);
			pointColor[i] = 1;
			int thisType = 1;
			while (!que.empty()) {
				auto now = que.front(); que.pop();

				REP(j, v[now].size()) {
					if (pointColor[v[now][j]] == 0) {
						pointColor[v[now][j]] = -pointColor[now];
						que.push(v[now][j]);
					}
					else {
						if (pointColor[v[now][j]] == pointColor[now]) {
							thisType = 2;
						}
					}
				}

			}
			if (v[i].size() == 0) {
				graphType[0]++;
			}
			else {
				graphType[thisType]++;
			}
		}
	}

	ll ans = 0;


	ans += 2 * graphType[0] * (n - graphType[0]);
	ans += graphType[0] * graphType[0];
	ans += 2 * graphType[1] * graphType[1];
	ans += 2 * graphType[1] * graphType[2];
	ans += graphType[2] * graphType[2];

//	SHOW1d(graphType, 3);
//	SHOW1d(pointColor, n);

	cout << ans << endl;

	return 0;
}
