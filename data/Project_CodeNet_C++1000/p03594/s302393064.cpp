#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init();
void solve();

#define rep(i, a) for (int i = 0; i < (int) (a); i++)
#define reps(i, a, b) for (int i = (int) (a); i < (int) (b); i++)
#define rrep(i, a) for (int i = (int) a-1; i >= 0; i--)
#define rreps(i, a, b) for (int i = (int) (a)-1; i >= (int) (b); i--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x

#ifdef LOCAL
#define lcout(a) cout << a
#define lcoutln(a) cout << a << endl
#define lcerr(a) cerr << a
#define lcerrln(a) cerr << a << endl
#else
#define lcout(a) 
#define lcoutln(a) 
#define lcerr(a) 
#define lcerrln(a) 
#endif
#define MOD 1000000007
#define PI 3.141592653589793238462643383

signed main()
{
	init();
	solve();
}

int H, W, d;
vector<vector<int> > che;

void init()
{
	cin >> H >> W >> d;
	int n = H + W - 1;
	che.resize(n);
	rep(i, n) {
		che[i].resize(n);
	}
	int col[2][2] = {{0, 1}, {2, 3}};
	rep(i, n) {
		int rcol = (i / d) % 2;
		rep(j, n) {
			int ccol = (j / d) % 2;
			che[i][j] = col[rcol][ccol];
		}
	}
}

void solve()
{
	char col[4] = {'R', 'B', 'G', 'Y'};
	int r = 0;
	int c = H - 1;
	rep(i, H) {
		rep(j, W) {
			cout << col[che[r][c]];
			r++;
			c++;
		}
		r = i + 1;
		c = H - i - 2;
		cout << endl;
	}
}


