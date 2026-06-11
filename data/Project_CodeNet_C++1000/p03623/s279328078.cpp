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
	int x, a, b;
	cin >> x >> a >> b;
	
	if( abs(x - a) > abs(x - b) ) {
		cout << "B" << endl;
	} else {
		cout << "A" << endl;
	}
	
	return 0;
}
