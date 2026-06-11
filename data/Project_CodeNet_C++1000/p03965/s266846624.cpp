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
	int x = 0;
	for (int i = 0 ; i < s.length() ; i++) {
		if (s[i] == 'g') x++;
		else x--;
	} 
	cout << x / 2;
}