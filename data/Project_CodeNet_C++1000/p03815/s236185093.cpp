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
	ll x, sum = 0;
	cin >> x;
	if ( x <= 6 ) cout << 1;
	else if ( x <= 11 ) cout << 2;
	else {
		sum += x/11;
		x%=11;
		if ( !x ) cout << sum * 2; 
		else if ( x <= 6 ) cout << sum * 2 + 1;
		else cout << sum * 2 + 2;
	}
}