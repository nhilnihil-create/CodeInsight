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
	int a[26] = {};
	cin >> s;
	for (int i = 0 ; i < s.length() ; i++) a[s[i] - 96]++;
	for (int i = 0 ; i < 26 ; i++)  {
		if (a[i] > 1) {
			cout << "no\n";
			return 0;
		}
	}
	cout << "yes\n";
}
