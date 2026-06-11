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
	int k, t;
	cin >> k >> t;
	
	priority_queue< pair<int, int> > pq;
	for(int i = 0; i < t; ++i) {
		int a;
		cin >> a;
		pq.push({a, i});
	}
	
	int ans = 0;
	int last = -1;
	while( !pq.empty() ) {
		pair<int, int> x = pq.top();
		pq.pop();
		
		if( x.second != last ) {
			x.first -= 1;
			last = x.second;
			
			if( x.first > 0 ) pq.push(x);
		} else {
			if( pq.empty() ) {
				ans += x.first;
				break;
			}
			
			pair<int, int> y = pq.top();
			pq.pop();
			
			y.first -= 1;
			last = y.second;
			pq.push(x);
			
			if( y.first > 0 ) pq.push(y);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
