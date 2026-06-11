#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
using ll = long long;
#define int ll

#define rep(i, a) for (int i = 0; (i) < (int)(a); (i)++)
#define reps(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a) for (int i = (int)a - 1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int)(a)-1; (i) >= (int)(b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) \
	sort(all(v)); \
(v).erase(unique(all(v)), v.end())
#define CIN(type, x) \
	type x;          \
cin >> x
#define TRUE__ "Yes"
#define FALSE__ "No"
#define PRINT(f)                  \
	if ((f))                      \
{                             \
	cout << (TRUE__) << endl; \
}                             \
else                          \
{                             \
	cout << FALSE__ << endl;  \
}
#define RS resize
#define CINV(v, N)             \
	do                         \
{                          \
	v.RS(N);               \
	rep(i, N) cin >> v[i]; \
} while (0);
#define RCINV(v, N)             \
	do                          \
{                           \
	v.RS(N);                \
	rrep(i, N) cin >> v[i]; \
} while (0);
	template <typename T>
inline T GET()
{
	T val;
	cin >> val;
	return val;
}

void init();
void solve();

signed main()
{
	init();
	solve();
}

int H, W, N;
map<pair<int, int>, int> m;
map<pair<int, int>, int> cnt;
int res[10];

void init()
{
	cin >> H >> W >> N;
	rep(i, N) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		m[MP(a, b)] = 1;
	}
}

int calc(int r, int c)
{
	if (r <= 0 || r >= H-1 || c <= 0 || c >= W-1) {
		return 0;
	}
	int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
	int dc[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
	int x = 0;
	rep(i, 9) {
		x += m.count(MP(r+dr[i], c+dc[i]));
	}
	res[x]++;
	return x;
}

void solve()
{
	for (auto x : m) {
		int a, b;
		a = x.first.first;
		b = x.first.second;
		int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
		int dc[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
		rep(i, 9) {
			if (cnt[MP(a+dr[i], b+dc[i])] == 0) {
				cnt[MP(a+dr[i], b+dc[i])] = calc(a+dr[i], b+dc[i]);
			}
		}
	}
	int sum = 0;
	rep(i, 10) {
		sum += res[i];
	}
	res[0] = (H - 2) * (W - 2) - sum;
	rep(i, 10) {
		cout << res[i] << endl;
	}
}
