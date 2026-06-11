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
	int k;
	cin >> s >> k;
	int l = s.length();
	for (int i = 0; i < l - 1; i++) {
		int tmp = ('a' - s[i] + 26) % 26;
		if (tmp <= k) {
			k -= tmp;
			s[i] = 'a';
		}
	}
	s[l - 1] = 'a' + ((s[l - 1] - 'a' + k) % 26);
	cout << s << endl;
}