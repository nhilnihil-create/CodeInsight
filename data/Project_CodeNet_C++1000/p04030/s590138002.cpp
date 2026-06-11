#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string s, ans;

	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s.at(i) == '0') { ans.push_back('0'); }
		else if (s.at(i) == '1') { ans.push_back('1'); }
		else if (s.at(i) == 'B' && ans.size() >0) { ans.pop_back(); }
	}

	cout << ans << endl;

}
