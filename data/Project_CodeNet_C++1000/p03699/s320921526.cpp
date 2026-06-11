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
	int n,b = 0;
	cin >> n;
	int a[n];
	for (int i = 0 ; i < n ; i++) cin >> a[i], b += a[i];
	sort(a, a + n);
	if (b % 10 != 0) {
		cout << b;
		return 0;
	}
	else {
		for (int j = 0 ; j < n ; j++) {
			for (int i = j ; i < n ; i++) {
				if ((b - a[i]) % 10 != 0) {
					cout << b - a[i];
					return 0;
				}
			}
			b -= a[j];
		}	
	} 
	cout << 0;
}
