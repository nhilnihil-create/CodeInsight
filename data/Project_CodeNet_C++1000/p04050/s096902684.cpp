#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int n, m;
int cc;
int a[12000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		if (a[i] % 2 == 1)
			++cc;
	}
	if (cc >= 3) {
		cout << "Impossible\n";
		return 0;
	}
	cc = 0;
	for (int i = 0; i < m; ++i) {
		if (a[i] % 2 == 1) {
			++cc;
			if (cc == 1)
				swap(a[0], a[i]);
			else if (cc == 2)
				swap(a[i], a[m - 1]);
		}
	}
	for (int i = 0; i < m; ++i)
		cout << a[i] << " ";
	cout << "\n";
	vector<int> vv;
	if (a[0] != 1)
		vv.push_back(a[0] - 1);
	for (int i = 1; i < m - 1; ++i) {
		vv.push_back(a[i]);
	}
	if (m == 1) {
		vv.push_back(1);
	}
	else if (a[m - 1] % 2 == 1) {
		vv.push_back(a[m - 1] + 1);
	}
	else {
		vv.push_back(a[m - 1]);
		vv.push_back(1);
	}
	cout << vv.size() << "\n";
	for (int i: vv)
		cout << i << " ";
	cout << "\n";
	return 0;
}


