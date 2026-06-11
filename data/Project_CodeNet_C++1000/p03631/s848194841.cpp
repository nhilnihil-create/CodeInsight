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
	string a = s;
	reverse(a.begin(), a.end());
	if (a == s) cout << "Yes";
	else cout << "No";
}   