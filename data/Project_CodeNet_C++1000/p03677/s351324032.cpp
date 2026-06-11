#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
#define double long double
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000000
#define LLINF 9223372036854775807
#define mod 1000000007
#define eps 1e-12 
//priority_queue<int,vector<int>, greater<int> > q2;

struct segtree {
public:
	const int SIZE = 1 << 18;
	VI seg, lazy;
	//seg:区間の合計値 lazy:区間に対して、加える値でまだ遅延しているもの

	segtree() :seg(SIZE * 2), lazy(SIZE * 2) {}
	void lazy_evaluate(int k, int l, int r) {
		if (lazy[k] != 0) {
			seg[k] += lazy[k];
			//区間[l,r)にすべて同じ値を追加することになっていて、
			//segには合計値が入っているので、加える値を足す
			if (r - l > 1) {
				lazy[k * 2 + 1] += lazy[k];
				lazy[k * 2 + 2] += lazy[k];
			}
			lazy[k] = 0;
		}
	}

	void update(int a, int b, int k, int l, int r, int x) {
		lazy_evaluate(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x;
			lazy_evaluate(k, l, r);
		}
		else {
			update(a, b, k * 2 + 1, l, (l + r) / 2, x);
			update(a, b, k * 2 + 2, (l + r) / 2, r, x);
			seg[k] = seg[k * 2 + 1] + seg[k * 2 + 2];
		}
	}
	int query(int a, int b, int k, int l, int r) {
		lazy_evaluate(k, l, r);
		if (r <= a || b <= l)return 0;
		if (a <= l && r <= b)return seg[k];
		int x = query(a, b, k * 2 + 1, l, (l + r) / 2);
		int y = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return x + y;
	}

	void update(int a, int b, int x) { update(a, b, 0, 0, SIZE, x); }
	//update(a,b,x) := [a,b)を全てxを加える
	int query(int a, int b) { return query(a, b, 0, 0, SIZE); }
	//query(a,b) := [a,b)に対する合計値を求める

};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	VI A(N);
	REP(i, N) {
		cin >> A[i];
		A[i]--;
	}
	segtree seg1, seg2;

	REP(i, N - 1) {
		int s = A[i], t = A[i + 1];
		if (s < t) {
			seg1.update(0, s + 1, t - s);
			seg1.update(t + 1, M, t - s);
			seg2.update(s + 1, s + 2, t - s);
			seg2.update(s + 2, t + 2, -1);
		}
		else{
			int r = M - s + t;
			seg1.update(t + 1, s + 1, r);
			t += M;
			seg2.update(s + 1, s + 2, r);
			seg2.update(s + 2, t + 2, -1);
		}
	}

	int ans = INF;
	VI sum(M * 2);
	REP(i,2 * M) {
		sum[i] = seg2.query(i, i + 1);
		if (i != 0)sum[i] += sum[i - 1];
		
	}
	REP(i, M) {
		chmin(ans, sum[i] + sum[i + M] + seg1.query(i, i + 1));
		//cout << sum[i] + sum[i + M] << " " <<  seg1.query(i, i + 1) << endl;
	}

	cout << ans << endl;

	return 0;
}

