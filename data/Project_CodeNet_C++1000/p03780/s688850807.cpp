#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 5005;
const int MAX_K = 5005;

int N, K;
vector<int> a;
bool dp[MAX_N][MAX_K]; // dp[x][y] := x 枚目をみたとき、総和を y にできるか？

bool solve(int x){

	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	rep (j, N){
		rep (k, K){
			if (dp[j][k]){
				dp[j+1][k] |= true;
				if (x != j && k + a[j] < K) dp[j + 1][k + a[j]] |= true;
			} // end if
		} // end rep
	} // end rep

	rep (k, K){
		if (dp[N][k] && k + a[x] >= K){	
			return true;
		} // end if
	} // end for

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	a.clear(); a.resize(N, 0);
	rep (i, N){
		cin >> a[i];
	} // end rep

	sort(ALL(a));

	// 最小値を求める
	int ok = N;
	int ng = -1;	
	while(abs(ok - ng) > 1){
		int mid = (ok + ng) / 2;
		if (solve(mid)){
			ok = mid;
		}else{
			ng = mid;
		} // end if
	} // end while
	
	cout << ok << endl;

	return 0;
}