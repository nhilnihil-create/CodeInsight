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
	int a, b, c, d = 20000;
	cin >> a >> b >> c;
	if (a + b < d) d = a + b;
	if (a + c < d) d = a + c;
	if (b + c < d) d = b + c;
	cout << d; 
}