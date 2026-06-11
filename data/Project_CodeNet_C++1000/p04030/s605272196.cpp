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
	string s;
	cin >> s;
	
	string ans = "";
	int n = (int)s.size();
	
	for(int i = 0; i < n; ++i) {
		if( s[i] == 'B' && !ans.empty() ) ans.pop_back(); 
		else if( s[i] == '0' || s[i] == '1' ) ans += s[i]; 
	}
	
	cout << ans << endl;
	
	return 0;
}
