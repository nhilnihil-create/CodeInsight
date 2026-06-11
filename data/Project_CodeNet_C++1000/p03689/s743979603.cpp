//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
//#define double long double



template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a>b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a<b) a = b; }

const int MOD = 1e9 + 7;
const ll INF = 1e17;
const int INT_INF = 1e9;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 200020;

int A[505][505];
void test() {
	std::random_device rnd;
	while (true) {
		int H, W, h, w;
		H = (rnd() % 20)+1;
		W = (rnd() % 20) + 1;
		h = (rnd() % 20) + 1;
		w = (rnd() % 20) + 1;
		if (h > H || w > W)continue;
		pe(H)pe(W)pe(h)print(w);
		bool ok = false;
		if ((h>H / 2 && h<H) || (w>W / 2 && w<W))ok = true;
		if ((h == H && w < W / 2) || (w == W && h < H / 2))ok = false;
		if (ok) {
			//print("Yes");
			REP(i, H) {
				REP(j, W) {
					A[i][j] = 1000;
				}
			}
			int hr = max(h - 1, H - h) + 1, hl = min(h - 1, H - h);
			int wr = max(w - 1, W - w) + 1, wl = min(w - 1, W - w);
			int num = (hr - hl)*(wr - wl);
			int sum = H * W * 1000 - num * 1000;
			int val = sum / num;
			if (val*num == sum)val--;
			FOR(i, hl, hr) {
				FOR(j, wl, wr) {
					A[i][j] = -val;
				}
			}
			sum = 0;
			REP(i, H) {
				REP(j, W)sum += A[i][j];
			}
			if (sum <= 0) {
				cerr << "sum is too small" << endl;
				goto END;
			}
			REP(i, H - h) {
				REP(j, W - w) {
					int sum = 0;
					FOR(x, i, i + h) {
						FOR(y, j, j + w) {
							sum += A[x][y];
						}
					}
					//pe(i)pe(j)print(sum);
					if (sum >= 0) {
						print("sum>=0"); goto END;
					}
				}
			}
			REP(i, H) {
				REP(j, W) {
					if (abs(A[i][j]) > 1e9) {
						print("value out of range"); goto END;
					}
					//pe(A[i][j]);
				}//cout << endl;
			}
		}
		//else print("No");
	}
END:;
}
void solve() {
	int H, W, h, w; cin >> H >> W >> h >> w;
	bool ok = false;
	if ((H%h!=0)||(W%w!=0))ok = true;
	if (ok) {
		print("Yes");
		REP(i, H)REP(j, W) {
			A[i][j] = -1000;
		}
		if (H%h != 0) {
			for (int i = 0; i<H; i +=h) {
				REP(j, W) {
					A[i][j] = h * 1000 - 1001;
				}
			}
		}
		else {
			for (int j = 0; j <W; j+=w) {
				REP(i, H) {
					A[i][j] = w * 1000 - 1001;
				}
			}
		}
		REP(i, H) {
			REP(j, W) {
				pe(A[i][j]);
			}cout << endl;
		}
	}
	else {
		print("No");
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}
