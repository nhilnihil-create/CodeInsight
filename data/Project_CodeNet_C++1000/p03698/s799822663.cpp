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

	sort(s.begin(), s.end());
	string res = "yes";
	rep(i, s.size()-1) {
		if (s[i]==s[i+1]) res = "no";
	}
	cout << res << endl;
}