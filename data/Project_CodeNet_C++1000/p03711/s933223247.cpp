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
	int x, y;
	cin >> x >> y;
	int a[7] = {1, 3, 5, 7, 8, 10, 12}, b[4] = {4, 6, 9, 11}, c = 0, d = 1;
	for (int i = 0 ; i < 7 ; i++) {
		if (a[i] == x) c++;
		if (a[i] == y) c++;
	}
	if (c == 2) cout << "Yes\n", d = 0;
	c = 0;
	for (int i = 0 ; i < 4 ; i++) {
		if (b[i] == x) c++;
		if (b[i] == y) c++;
	}
	if (c == 2 && d) cout << "Yes\n", d = 0;
	if (x == 2 && y == 2 && d) cout << "Yes\n", d = 0;
	if (d) cout << "No\n";  
}
