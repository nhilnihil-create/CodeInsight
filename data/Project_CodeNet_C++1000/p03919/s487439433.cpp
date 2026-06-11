#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
#include <array>
#include <numeric>
#include <regex>
#include <bitset>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> p_ii;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;


int main() {
	
	int h, w;
	cin >> h >> w;
	string str[26][26];
	rep(i, h)rep(j, w)cin >> str[i][j];

	rep(i, h)rep(j, w) {
		if (str[i][j] == "snuke") {
			cout << (char)(j + 'A') << i + 1 << endl;
			return 0;
		}
	}

	return 0;
}