#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;


int N, K;
int a[123456], sum[123456], sumplus[123456];

signed main(){

	cin >> N >> K;

	rep(i, N)
		cin >> a[i];

	rep(i, N){
		sum[i + 1] = sum[i] + a[i];
		sumplus[i + 1] = sumplus[i] + max(0LL, a[i]);
	}

	int ans = -INF;
	rep(i, N - K+1){
		ans = max(ans, sumplus[i] + (sum[i + K] - sum[i]) + sumplus[N] - sumplus[i + K]);
		ans = max(ans, sumplus[i] + sumplus[N] - sumplus[i + K]);
	}

	cout << ans << endl;



	return 0;
}