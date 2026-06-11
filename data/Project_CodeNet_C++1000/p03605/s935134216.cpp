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
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i = 0 ; i < s.length() ; i++) {
		if (s[i] == '9') {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}