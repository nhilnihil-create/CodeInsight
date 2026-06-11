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
	cin >> n;
	
	vector<int> cnt(9, 0);
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		
		if( a / 400 >= 8 ) cnt[8]++;
		else cnt[a / 400]++;
	}
	
	int minans = 0;
	for(int i = 0; i < 8; ++i) {
		if( cnt[i] ) minans++;
	}
	
	int maxans = minans + cnt.back();
	if( minans == 0 ) {
		minans++;
	}
	
	cout << minans << " " << maxans << endl;
	
	return 0;
}
