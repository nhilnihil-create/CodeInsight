# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
using namespace std;
typedef long long int ll;
const int INF = 1 << 30;
#define rep(i,n) for(int i=(ll)0;i<(ll)n;++i)
#define ALL(x) x.begin(),x.end()
int main() {
	int n;
	int pos[510] = {};
	int dp[510] = {};
	int ans[251000] = {};
	cin >> n;
	rep(i, n) {
		cin >> pos[i];
		pos[i]--;
		dp[i] = i;
	}
	rep(i, n*n) {
		int mn=INF,mnp=INF;
		bool fl = 0;
		for (int j = 0; j < n; ++j) {
			if (dp[j] != 0&&i!=pos[j]) {
				int num;
				if (i < pos[j])num = pos[j] - i;
				else num = INF - j-1;
				if (mn > num) { mn = num; mnp = j; }
			}
			if (i == pos[j]) { dp[j] = n - j - 1; ans[i] = j + 1; fl = 1; }
		}
		if (fl)continue;
		if (mn == INF) { cout << "No" << endl; return 0; }
		dp[mnp] -= 1;
		ans[i] = mnp + 1;
	}
	cout << "Yes" << endl;
	rep(i, n*n) {
		cout << ans[i]<<" ";
	}
	cout<<""<<endl;
	return 0;
}