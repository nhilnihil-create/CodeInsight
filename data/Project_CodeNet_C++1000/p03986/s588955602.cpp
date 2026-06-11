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
	string x;
	cin >> x;
	
	int n = (int)x.size();
	int ans = n;
	int s = 0, t = 0;
	bool sflag = false, tflag = false;
	
	for(int i = 0; i < n; ++i) {
		if( x[i] == 'S' ) {
			if( tflag ) {
				ans -= 2 * min(s, t);
				s = max(0, s - min(s, t)), t = 0;
				tflag = false;
			}
			
			s++;
			sflag = true;
			
		} else if( x[i] == 'T' && sflag && s > t ) {
			t++;
			tflag = true;
		}
	}
	
	if( sflag && tflag ) {
		while( s != 0 && t != 0 ) {
			ans -= 2 * min(s, t);
			s = max(0, s - min(s, t)); t = max(0, t - min(s, t));
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
