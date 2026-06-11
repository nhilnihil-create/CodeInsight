#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using tp3=tuple<ll, ll, ll>;

int main()
{
	int W, H;
	cin >> W >> H;
	vector<ll> p(W), q(H);
	rep(i, W)cin >> p[i];
	rep(j, H)cin >> q[j];

	priority_queue<tp3, vector<tp3>, greater<tp3>> pq;
	rep(i, W)pq.push(make_tuple(p[i], i, 0));
	rep(j, H)pq.push(make_tuple(q[j], j, 1));

	ll res = 0;
	H++; W++;
	while (!pq.empty()) {
		ll num, pos, kind;
		tie(num, pos, kind) = pq.top(); pq.pop();
		if (kind == 0) {
			res += num * H;
			W--;
		}
		else {
			res += num * W;
			H--;
		}
	}
	cout << res << endl;
	return 0;
}
