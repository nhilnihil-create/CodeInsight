#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = s.length() - 1 ; i > 0 ; i--) {
		int y = 0;
		for (int j = 0 ; j < i / 2 ; j++) {
			if (s[j] == s[j + i / 2]) y++;
		}
		if (y == i / 2 && i % 2 == 0) {
			cout << i;
			return 0;
		}
	}
}