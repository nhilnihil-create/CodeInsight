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
	vector<int> bell(3);
	cin >> bell[0] >> bell[1] >> bell[2];
	
	sort(bell.begin(), bell.end());
	
	cout << bell[0] + bell[1] << endl;
	
	return 0;
}
