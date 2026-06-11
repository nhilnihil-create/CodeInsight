#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

int main() {
	int n, a, x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a % 4 == 0) x++;
		else if (a % 2 != 0) y++;
	}
	if (y == x + 1 && x + y == n || x >= y) cout << "Yes" << endl;
	else cout << "No" << endl;
}