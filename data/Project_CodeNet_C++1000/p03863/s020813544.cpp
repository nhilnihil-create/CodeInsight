#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 1000000007
#define INIT -1

int main() {
	string s;
	cin >> s;
	int l = s.length();
	if (s[0] == s[l - 1]) {
		// ゲーム終了後の文字列の長さは奇数
		if (l % 2 == 0) {
			cout << "First" << endl;
		} else {
			cout << "Second" << endl;
		}
	} else {
		// ゲーム終了後の文字列の長さは偶数
		if (l % 2 == 0) {
			cout << "Second" << endl;
		} else {
			cout << "First" << endl;
		}
	}
}