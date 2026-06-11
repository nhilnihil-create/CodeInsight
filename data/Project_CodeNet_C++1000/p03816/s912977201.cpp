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
	int n , a[100001] , b[100001] = {} , x = 0 , y = 0;
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++) b[a[i]]++;
	for (int i=0;i<=100000;i++) {
		if (b[i]) {
			if (b[i]%2) x++;
			else y++;
		}
	}
	if (y%2) cout << x + y - 1;
	else cout << x + y;
}