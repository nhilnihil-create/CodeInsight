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

	string sub = s.substr(1, s.size()-2);
	string sub_len = to_string(sub.size());
	string res = s[0] + sub_len + s[s.size()-1];
	cout << res << endl;
}