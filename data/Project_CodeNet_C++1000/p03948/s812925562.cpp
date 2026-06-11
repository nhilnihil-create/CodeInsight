#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

signed main(){
	int N, T;
	cin >> N >> T;
	vector<int> A(N + 1), B(N + 1);
	A[0] = B[0] = (int)1e18;
	for(int i = 1; i <= N; ++i) {
		cin >> A[i];
		B[i] = min(A[i], B[i-1]);
	}
	int d = 0;
	for(int i = 1; i <= N; ++i) {
		d = max(d, A[i] - B[i - 1]);
	}
	int res = 0, u = A[N], ucnt = 0, lcnt = 0;
	for(int i = N; i >= 0; --i) {
		if(A[i] > u) {
			if(ucnt > 0 && lcnt > 0) {
				res += min(ucnt, lcnt);
			}
			ucnt = 1;
			lcnt = 0;
			u = A[i];
		} else if(A[i] == u) {
			++ucnt;
		} else if(A[i] == u - d) {
			++lcnt;
		}
	}
	cout << res << endl;
	return 0;
}
