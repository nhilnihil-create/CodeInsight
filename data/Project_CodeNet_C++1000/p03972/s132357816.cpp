#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define mkp(a,b) make_pair(a,b)
const long long mod = 1000000007;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<int ,P> PP;
struct edge { int to; int to2; int cost; };
int p[100005], q[100005];
signed main() {
	int w, h; cin >> w >> h;
	rep(i, w)cin >> p[i];
	rep(i, h)cin >> q[i];

	priority_queue<P, vector<P>, greater<P>>Q;
	rep(i, w)Q.push(P(p[i], 0));
	rep(i, h)Q.push(P(q[i], 1));
	int ans = 0;
	int uw = 0, uh = 0;
	while (Q.size()) {
		P x = Q.top();
		Q.pop();
		if (x.second) {
			ans += x.first*(w +1-uw);
			uh++;
		}
		else {
			ans += x.first*(h +1- uh);
			uw++;
		}
	}
	cout << ans << endl;
}