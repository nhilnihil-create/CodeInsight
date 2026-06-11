#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	string s;
	cin >> s;

	string res = "";
	rep(i, s.length()) {
		if (i%2==0) res += s[i];
	}
	cout << res << endl;
}