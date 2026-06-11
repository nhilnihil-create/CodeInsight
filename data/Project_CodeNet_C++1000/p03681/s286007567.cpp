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
	int n, m;
	cin >> n >> m;
	if (abs(n - m) >= 2) cout << 0;
	else {
		ll x = 1;
		for (int i = 2 ; i <= n ; i++) x = x * i % 1000000007;
		for (int i = 2 ; i <= m ; i++) x = x * i % 1000000007;
		if (n - m) cout << x % 1000000007;
		else cout << x * 2 % 1000000007;
	}
}