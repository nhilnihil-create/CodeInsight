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
	int a[26] = {};
	string b = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0 ; i < s.length() ; i++) {
		for (int j = 0 ; j < 26 ; j++) {
			if (s[i] == b[j]) {
				a[j]++;
				j = 26;
			}
		}
	}
	for (int i = 0 ; i < 26 ; i++) {
		if (a[i] == 0) {
			cout << b[i];
			return 0;
		}
	} 
	cout << "None";
}