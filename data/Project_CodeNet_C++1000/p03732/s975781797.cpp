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
typedef vector<int> VI;
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
//vector<vector<int> > dp;
//vector<vector<vector<int> > > vvvi;
//dp=vector<vector<int> >(N, vector<int>(M,0));
//vector<pair<int,int> > v;
//v.push_back(make_pair(x,y));



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, W;
	cin >> N >> W;
	VI A(N);
	VI V(N);
	VI a, b, c, d;
	a.push_back(0);
	b.push_back(0);
	c.push_back(0);
	d.push_back(0);
	int x = 0;
	REP(i, N) {
		cin >> A[i] >> V[i];
		if (i == 0)x = A[i];
		if (A[i] == x)
			a.push_back(V[i]);
		if (A[i] == x + 1)
			b.push_back(V[i]);
		if (A[i] == x + 2)
			c.push_back(V[i]);
		if (A[i] == x + 3)
			d.push_back(V[i]);
	}



	rSORT(a);
	rSORT(b);
	rSORT(c);
	rSORT(d);

	int ans = 0;
	REP(i, a.size()) {
		if (a[i] == 0)break;
		a[i + 1] += a[i];
	}
	REP(i, b.size()) {
		if (b[i] == 0)break;
		b[i + 1] += b[i];
	}
	REP(i, c.size()) {
		if (c[i] == 0)break;
		c[i + 1] += c[i];
	}
	REP(i, d.size()) {
		if (d[i] == 0)break;
		d[i + 1] += d[i];
	}




	FOR(i, 0, a.size() + 1) {
		int av, aw;
		if (i == 0) {
			av = 0;
			aw = 0;
		}
		else {
			av = a[i - 1];
			aw = i * A[0];
		}
		if (i == a.size()) aw -= A[0];

		//cout << "K" << endl;
		FOR(j, 0, b.size() + 1) {
			int bv, bw;
			if (j == 0) {
				bv = 0;
				bw = 0;
			}
			else {
				bv = b[j - 1];
				bw = j * (A[0] + 1);
			}
			if (j == b.size()) bw -= (A[0] + 1);


			FOR(k, 0, c.size() + 1) {
				int cv, cw;
				if (k == 0) {
					cv = 0;
					cw = 0;
				}
				else {
					cv = c[k - 1];
					cw = k * (A[0] + 2);
				}
				if (k == c.size()) cw -= (A[0] + 2);
				FOR(z, 0, d.size() + 1) {
					int dv, dw;
					if (z == 0) {
						dv = 0;
						dw = 0;
					}
					else {
						dv = d[z - 1];
						dw = z * (A[0] + 3);
					}
					if (z == d.size()) dw -= (A[0] + 3);
					//cout << av + bv + cv + dv << " " << aw << " " << bw << " " << cw << " " << dw << " " << i << " " << j << " " << k << " " << z << endl;
					if (aw + bw + cw + dw <= W) {
						ans = max(ans, av + bv + cv + dv);
					}

				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}

