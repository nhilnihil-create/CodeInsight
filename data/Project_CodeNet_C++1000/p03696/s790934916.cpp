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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0 ; i < n ; i++) {
		if (s[i] == '(') b++;
		else b--;
		if (b < 0) {
			b = 0;
			a++;
		}
		
	}
	while (a--) cout << '(';
	cout << s;
	while (b--) cout << ')';
}