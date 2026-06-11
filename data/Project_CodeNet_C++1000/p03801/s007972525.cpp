#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
const ll MOD = 1000000007;

int main(){
	int N, mx = 0;
	cin >> N;
	vector<ll> A(N + 1, 0), mv = A, mxv = { 0 }, mxvr(N + 1, -1);
	for (int i = 1;i <= N;i++) {
		cin >> A[i];
		mv[i] = A[i];
		if (mx < A[i]) {
			mx = A[i];
			mxv.push_back(i);
			mxvr[i] = mxv.size() - 1;
		}
	}
	sort(all(mv));

	ll cnt = 0;
	for (int i = 1;i <= N;i++) {
		cnt = 0;
		if (mxvr[i] >= 0) {
			int a = mxvr[i];
			auto it1 = upper_bound(all(mv), A[mxv[a - 1]]);
			auto it2 = upper_bound(all(mv), A[mxv[a]]);
			cnt += (mv.end() - it2)*(A[mxv[a]] - A[mxv[a - 1]]);
			while (it1 != it2) {
				cnt += *it1 - A[mxv[a - 1]];
				it1++;
			}
		}
		cout << cnt << endl;
	}
}