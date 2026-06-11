#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string a;
	cin >> a;
	
	int n = (int)a.size();
	vector< vector<int> > sum(n + 1, vector<int>(26, 0));
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 26; ++j) {
			sum[i + 1][j] += sum[i][j];
		}
		
		int x = (int)(a[i] - 'a');
		
		sum[i + 1][x] = sum[i][x] + 1;
	}
	
	
	ll ans = 1LL;
	for(int i = 0; i < n; ++i) {
		int v = (int)(a[i] - 'a');
		int b = n - i - 1 - (sum[n][v] - sum[i + 1][v]);
		ans += b;
	}

	cout << ans << endl;
	
	return 0;
}
