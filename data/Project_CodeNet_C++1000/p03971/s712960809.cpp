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
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	
	int passed = 0;
	int passed_b = 0;
	for(int i = 0; i < n; ++i) {
		if( s[i] == 'a' ) {
			if( passed < a + b ) { 
				cout << "Yes" << endl;
				passed++;
			} else {
				cout << "No" << endl;
			}
		} else if( s[i] == 'b' ) {
			if( passed < a + b && passed_b < b ) { 
				cout << "Yes" << endl;
				passed++;
				passed_b++;
			} else {
				cout << "No" << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}
