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

	string str = s.substr(0, s.size()-2);
	while (str.size() > 1) {
		string first = str.substr(0, str.size()/2);
		string second = str.substr(str.size()/2, str.size());
		if (first == second) {
			cout << str.size() << endl;
			return 0;
		}
 		str = str.substr(0, str.size()-2);
	}
}