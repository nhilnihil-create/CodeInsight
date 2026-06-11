#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <functional>
#include <ctime>
using namespace std;

#define REP(i,n) for(int (i) = 0; (i) < (n); ++(i))

long long dfs(long long a, long long b, long long sum, string s) {
	if(a == s.size()) return sum;
	long long x = 0;
	int tmp = s[a] - '0';
	if(a + 1 != s.size()) x += dfs(a + 1, b * 10 + tmp, sum, s);
	x += dfs(a + 1, 0, sum + b * 10 + tmp, s);
	return x;
}

void solve() {
	string s;
	cin >> s;
	cout << dfs(0, 0, 0, s) << endl;
}

int main() {
	solve();
	return 0;
}
