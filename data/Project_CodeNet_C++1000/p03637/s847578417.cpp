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
	int a[n], x = 0, y = 0, z = 0;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
		if (a[i] % 4 == 0) x++;
		else if (a[i] % 2 == 0) y++;
		else z++; 
	}
	if(z <= x) cout << "Yes\n";
    else if(y == 0 && z <= x + 1) cout << "Yes\n";
    else cout << "No\n";
}   