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
	string a, b, c;
	cin >> a >> b >> c;
	
	cout << (char)((a[0] - 'a') + 'A');
	cout << (char)((b[0] - 'a') + 'A');
	cout << (char)((c[0] - 'a') + 'A') << endl;
	
	return 0;
}
