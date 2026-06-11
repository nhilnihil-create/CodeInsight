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
 
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for (int i=0;i<s.length();i++) {
		if (s[i]!=',') cout << s[i];
		else cout << ' ';
	}
}