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

	int N;
	cin >> N;
	vector<int> T(N), A(N);
	rep(i, N) cin >> T[i];
	rep(i, N) cin >> A[i];

	vector<int> lower(N), upper(N);

	rep(i, N){
		if (i == 0 || T[i] != T[i - 1]){
			lower[i] = T[i];
			upper[i] = T[i];
		}
		else{
			lower[i] = 1;
			upper[i] = T[i];
		}
	}

	for (int i = N - 1; i >= 0; i--){
		if (i == N - 1 || A[i] != A[i + 1]){
			lower[i] = max(lower[i], A[i]);
			upper[i] = min(upper[i], A[i]);
		}
		else{
			lower[i] = max(lower[i], 1LL);
			upper[i] = min(upper[i], A[i]);
		}
	}

	int ans = 1;
	rep(i, N){
		ans *= max(0LL, upper[i] - lower[i] + 1);
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}