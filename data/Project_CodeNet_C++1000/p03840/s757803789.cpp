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

	int ai, ao, at, aj, al, as, az;
	cin >> ai >> ao >> at >> aj >> al >> as >> az;
	int ans = 0;
	ans += ao;
	// JJかLLかJILかII

	//JILが1個のとき
	if (ai > 0 && aj > 0 && al > 0){
		ans += 3;
		ans += ((ai - 1) / 2) * 2
			+ ((aj - 1) / 2) * 2
			+ ((al - 1) / 2) * 2;
	}

	// JILが0個のとき
	int ans2 = ao;
	// II
	ans2 += (ai / 2) * 2; ai %= 2;;
	// JJ
	ans2 += (aj / 2) * 2; aj %= 2;
	// LL
	ans2 += (al / 2) * 2; al %= 2;

	cout << max(ans, ans2) << endl;

	return 0;
}