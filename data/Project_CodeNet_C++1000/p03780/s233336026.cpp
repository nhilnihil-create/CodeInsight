
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl;
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)
#define INF INT_MAX/2

int n, k;
vector<int>a;
int dp[5050][5050];
int check(int ex) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i, 0, n - 1)rep(x,0,k+1) {
		int ind = (i < ex) ? i : i + 1;
		dp[i + 1][x] = max(dp[i][x],dp[i+1][x]);
		if (x + a[ind] < 5050) {
			dp[i + 1][x + a[ind]] = max(dp[i + 1][x + a[ind]], dp[i][x]);
		}
	}
	for (int i = max(0, k - a[ex]); i < k;i++) {
		if (dp[n-1][i])return 1;
	}
	return 0;
}

int main() {
	cin >> n >> k;
	a.resize(n);
	rep(i, 0, n)cin >> a[i];
	sort(all(a));

	if (check(0)) {
		puts(0);
	}
	else if (!check(n-1)) {
		puts(n);
	}
	else {
		int noneed = 0, need = n - 1;
		while (need - noneed > 1) {
			int mid = (need + noneed) / 2;
			if (check(mid))need = mid;
			else noneed = mid;
		}
		puts(noneed + 1);
	}

	return 0;
}
