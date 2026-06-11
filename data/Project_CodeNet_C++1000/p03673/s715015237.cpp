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
	
	deque<int> dq;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
	
		if( ( (i + 1) % 2 ) ^ ( (n - 1) % 2) ) dq.push_front(a);
		else  dq.push_back(a);
	}
	
	for(auto& ans : dq) {
		cout << ans << " ";
	}
	
	cout << endl;
	
	return 0;
}
