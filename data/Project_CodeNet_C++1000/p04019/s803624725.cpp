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
constexpr ll MOD_LL = ll(1e9) + 7;

int main(void) {
	string s;
	cin >> s;
	
	int n = s.size();
	int S = 0, N = 0, E = 0, W = 0;
	for(int i = 0; i < n; ++i) {
		if( s[i] == 'N' ) N = 1;
		if( s[i] == 'S' ) S = 1;
		if( s[i] == 'E' ) E = 1;
		if( s[i] == 'W' ) W = 1;
	}
	
	if( N + S == 1 || E + W == 1 ) cout << "No" << endl;
	else cout << "Yes" << endl;
	
	return 0;
}
