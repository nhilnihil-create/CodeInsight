#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()
#define INF ((ll)(1e18))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N; cin >> N;
	vector<ll> a(3*N, 0LL);
	rep (i, 3*N) cin >> a[i];

	priority_queue<ll, vector<ll>, greater<ll> > p; // 前半分
	priority_queue<ll> q;	// 後ろ半分
	ll qsum = 0LL;
	ll psum = 0LL;
	rep (i, 3 * N){
		if (i < N){
			p.push(a[i]);
			psum += a[i];
		} // end if
		if (i >= 2 * N){
			q.push(a[i]);
			qsum += a[i];
		} // end if
	} // end for

	vector<ll> pm(N + 1, 0LL);
	pm[0] = psum;
	for (int k = N; k < 2 * N; ++k){
		p.push(a[k]); psum += a[k];
		psum -= p.top(); p.pop();
		pm[k - N + 1] = psum;
	} // end for

	vector<ll> qm(N + 1, 0LL);
	qm[N] = qsum;
	for (int k = 2 * N - 1; k >= N; --k){
		q.push(a[k]); qsum += a[k];
		qsum -= q.top(); q.pop();
		qm[k - N] = qsum;
	} // end for

	ll res = -INF;
	rep (i, N + 1){
//		cerr << pm[i] << ' ' << qm[i] << endl;
		ll curr = pm[i] - qm[i];
		res = max(res, curr);
	} // end rep
	cout << res << endl;
	
	return 0;
}