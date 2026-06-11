#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

#define rep(i, a) for (int i = 0; (i) < (int) (a); (i)++)
#define reps(i, a, b) for (int i = (int) (a); (i) < (int) (b); (i)++)
#define rrep(i, a) for (int i = (int) a-1; (i) >= 0; (i)--)
#define rreps(i, a, b) for (int i = (int) (a)-1; (i) >= (int) (b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define YES(f) if((f)){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(f) if((f)){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define MINV(v) min_element(all(v))
#define MAXV(v) max_element(all(v))
#define MIN3(a, b, c) min(min(a, b), c)
#define MIN4(a, b, c, d) min(MIN3(a, b, c), d)
#define MIN5(a, b, c, d, e) min(MIN4(a, b, c, d), e)
#define MIN6(a, b, c, d, e, f) min(MIN5(a, b, c, d, e), f)
#define MAX3(a, b, c) max(max(a, b), c)
#define MAX4(a, b, c, d) max(MAX3(a, b, c), d)
#define MAX5(a, b, c, d, e) max(MAX4(a, b, c, d), e)
#define MAX6(a, b, c, d, e, f) max(MAX5(a, b, c, d, e), f)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmin3(a, b, c) a = MIN3(a, (b), (c))
#define chmin4(a, b, c, d) a = MIN4(a, (b), (c), (d))
#define chmin5(a, b, c, d, e) a = MIN5(a, (b), (c), (d), (e))
#define chmin6(a, b, c, d, e, f) a = MIN6(a, (b), (c), (d), (e), (f))
#define chmax(a, b) a = max(a, (b))
#define chmax3(a, b, c) a = MAX3(a, (b), (c))
#define chmax4(a, b, c, d) a = MAX4(a, (b), (c), (d))
#define chmax5(a, b, c, d, e) a = MAX5(a, (b), (c), (d), (e))
#define chmax6(a, b, c, d, e, f) a = MAX6(a, (b), (c), (d), (e), (f))

#define RS resize
#define CINV(v, N) do {\
	v.RS(N);\
	rep(i, N) cin >> v[i];\
} while (0);
#define RCINV(v, N) do {\
	v.RS(N);\
	rrep(i, N) cin >> v[i];\
} while (0);

#define MOD 1000000007

template<class T>
inline T GET() {
	T x;
	cin >> x;
	return x;
}

void init();
void solve();

signed main()
{
	init();
	solve();
}

#define INF 1123456789
int N;
vector<int> T, A;

void init()
{
	cin >> N;
	rep(i, N) {
		T.PB(GET<int>());
	}
	rep(i, N) {
		A.PB(GET<int>());
	}
}

int calc()
{
	vector<int> v(N);
	v[0] = -T[0];
	reps(i, 1, N) {
		if (T[i] != T[i-1]) {
			v[i] = -T[i];
		} else {
			v[i] = T[i];
		}
	}
	if (v.back() < 0 && A.back() != -v.back() || v.back() > 0 && A.back() > v.back()) return 0;
	v.back() = -A.back();
	rrep(i, N-1) {
		if (A[i] != A[i+1]) {
			if (v[i] < 0 && A[i] != -v[i] || v[i] > 0 && A[i] > v[i]) {
				return 0;
			}
			v[i] = -A[i];
		}
		else {
			if (v[i] < 0 && A[i] < -v[i]) {
				return 0;
			}
			chmin(v[i], A[i]);
		}
	}
	int res = 1;
	rep(i, N) {
		if (v[i] > 0) res *= v[i];
		res %= MOD;
	}
	return res;
}

void solve()
{
	cout << calc() << endl;
}



