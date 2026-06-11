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
	int a, b, c;
	cin >> a >> b >> c;
	
	bool yes = false;
	int i = 1;
	while( i * a <= a * b ) {
		if( (i * a) % b == c ) {
			yes = true;
			break;
		}
		
		i++;
	}
	
	if( yes ) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
