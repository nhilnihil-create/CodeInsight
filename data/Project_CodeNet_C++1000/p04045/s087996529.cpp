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
	int n, k;
	cin >> n >> k;
	
	vector<int> ng(10, 0);
	for(int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		ng[a] = 1;
	}
	
	for(int i = n; i < 100000; ++i) {
		int tmp = i;
		bool ok = true;
		
		while( tmp ) {
			if( ng[tmp % 10] == 1 ) {
				ok = false;
				break;
			}
			
			tmp /= 10;
		}
		
		if( ok && n <= i ) {
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
