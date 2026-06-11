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
	int n;
	string s;
	cin >> n >> s;
	int tmp = 0;
	for (int i = 0; i < s.length(); i++) {
		// cout << i << " " << s << endl;
		if (s[i] == '(') {
			tmp++;
		} else {
			if (tmp == 0) {
				s = '(' + s;
				i++;
			} else {
				tmp--;
			}
		}
	}
	for (int i = 0; i < tmp; i++) {
		s = s + ')';
	}
	cout << s << endl;
}