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
	string a,b;
	cin >> a >> b;
	bool y=1;
	if (a.length()>b.length()) {
		cout << "GREATER\n";
		y=0;
	}
	else if (b.length()>a.length()) {
		cout << "LESS\n";
		y=0;
	}
	else {
		for (int i=0;i<=a.length();i++) {
			if (a[i]-'0'>b[i]-'0') {
				cout << "GREATER\n";
				y=0;
				break;
			} else if (b[i]-'0'>a[i]-'0') {
				cout << "LESS\n";
				y=0;
				break;
			}
		}
	}
	if (y) cout << "EQUAL\n";
}