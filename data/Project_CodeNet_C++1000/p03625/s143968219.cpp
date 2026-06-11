#include <iostream>
#include<cmath>
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
	ll n, l1 = 0, l2 = 0;
	cin >> n;
	ll a[n] = {};
	for (ll i = 0 ; i < n ; i++) cin >> a[i]; 
	sort(a, a + n);
	for (ll i = n - 1 ; i >= 0 ; i--) {
		if (a[i] == a[i - 1]) {
			if (l1 == 0) {
				l1 = a[i];
				i -= 1;
			}
			else {
				l2 = a[i];
				cout << l1 * l2;
				return 0;
			} 
		}
	}
	cout << 0;
}
