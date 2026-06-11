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
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	
	int cur = 0;
	int os = 0;
	for(int i = 0; i < n; ++i) {
		if( cur < a + b && s[i] == 'a' ) {
			cout << "Yes" << endl;
			cur++;
		} else if( cur < a + b && os < b && s[i] == 'b' ) {
			cout << "Yes" << endl;
			cur++; os++;
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}
