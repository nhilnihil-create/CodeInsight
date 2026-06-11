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
	stack<char> st;
	
	for(int i = 0; i < n; ++i) {
		if( st.empty() ) st.push(x[i]);
		
		else {
			if( x[i] == 'S' ) st.push(x[i]); 
			if( x[i] == 'T' ) {
				if( st.top() == 'S' ) st.pop();
				else st.push(x[i]);
			}
		}
	}
	
	cout << (int)st.size() << endl;
	
	return 0;
}
