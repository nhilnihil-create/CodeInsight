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
	vector<char> cargo;
	
	for(int i = 0; i < n; ++i) {
		if( cargo.empty() ) cargo.push_back(x[i]);
		
		else {
			if( x[i] == 'S' ) cargo.push_back(x[i]);
			if( x[i] == 'T' ) {
				if( cargo.back() == 'S' ) cargo.pop_back();
				else cargo.push_back(x[i]);
			}
		}
	}
	
	cout << (int)cargo.size() << endl;
	
	return 0;
}
