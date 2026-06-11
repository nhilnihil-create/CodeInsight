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
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	bool up = false, down = false;
	for(int i = 0; i < n - 1; ++i) {
		if( a[i] < a[i + 1] ) {
			up = true;
		} else if( a[i] > a[i + 1] ) {
			down = true;
		} 
		
		if( up && down ) { 
			ans++;
			up = false; down = false;
		}
	}
	
	cout << ans + 1 << endl;
	
	return 0;
}
