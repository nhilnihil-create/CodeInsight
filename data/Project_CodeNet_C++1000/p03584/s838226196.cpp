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
#define TRUE__  "YES"
#define FALSE__ "NO"
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

int N, K;
vector<unsigned int> a, b;

void init()
{
	cin >> N >> K;
	a.resize(N);
	b.resize(N);
	rep(i, N) cin >> a[i] >> b[i];
}

unsigned int mask;

ll culc()
{
	ll res = 0;
	rep(i, N) {
		if ((mask & a[i]) == 0) res += b[i];
	}
	return res;
}

void solve()
{
	ll res = 0;
	unsigned int bit = 1 << 31;
	unsigned int pos = 1 << 31;
	while (true) {
		while ((bit & K) == 0 && bit != 0) bit >>= 1;
		if (bit == 0) break;
		while (pos >= bit) {
			mask |= pos;
			pos >>= 1;
		}
		res = max(res, culc());
		mask &= ~bit;
		bit >>= 1;
	}
	mask = ~K;
	res = max(culc(), res);
	cout << res << endl;
}

