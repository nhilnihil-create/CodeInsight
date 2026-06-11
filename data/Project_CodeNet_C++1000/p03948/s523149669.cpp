#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl


signed main(){

	int N, T;
	cin >> N >> T;
	vector<int> A(N, 0);
	rep(i, N) cin >> A[i];
	vector<int> B(N, 0);

	// iで売った場合
	int mi = A[0];
	for (int i = 1; i < N; i++){
		B[i] = A[i] - mi;
		mi = min(mi, A[i]);
	}

	sort(B.begin(), B.end(), greater<>());

	int ans = 1;
	for (int i = 1; i < N; i++){
		if (B[i] != B[0]) break;
		else ans = i+1;
	}
	cout << ans << endl;


	

	return 0;
}