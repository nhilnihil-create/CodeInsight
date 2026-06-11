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
	int a, b, c[200000] = {0}, d[200000] = {0};
	for (int i = 0 ; i < m ; i++) {
		cin >> a >> b;
		if (a == 1) c[b - 1] = 1;
		if (b == n) d[a - 1] = 1; 
	}
	for (int i = 0 ; i < m ; i++) {
		if (c[i] == 1 && d[i] == 1) {
			cout << "POSSIBLE";
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}   