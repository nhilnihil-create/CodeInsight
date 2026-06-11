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

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n;
	string s;
	cin >> n >> s;
	
	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if( s[i] == 'I' ) cnt++;
		else cnt--;
		
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;
	
	return 0;
}
