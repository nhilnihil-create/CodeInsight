#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n, m;
int a[100];

vector<int> solveA() {
	vector<int> b;
	int i;
	
	if (a[0] >= 2) {
		b.push_back(a[0] - 1);
	}
	for (i = 1; i < m; i++) {
		b.push_back(a[i]);
	}
	b.push_back(1);
	return b;
}

vector<int> solveB() {
	vector<int> b;
	int i;
	
	if (a[0] >= 2) {
		b.push_back(a[0] - 1);
	}
	for (i = 1; i < m; i++) {
		b.push_back(a[i]);
	}
	b.push_back(1);
	return b;
}

vector<int> solveC() {
	vector<int> b;
	int i;
	
	swap(a[1], a[m - 1]);
	
	if (a[0] >= 2) {
		b.push_back(a[0] - 1);
	}
	for (i = 1; i < m - 1; i++) {
		b.push_back(a[i]);
	}
	b.push_back(2);
	if (a[m - 1] >= 2) {
		b.push_back(a[m - 1] - 1);
	}
	return b;
}

int main() {
	int i;
	
	cin >> n >> m;
	rep(i, m) cin >> a[i];
	
	function<int(int, int)> comp = [](int x, int y) {
		if (x % 2 != y % 2) return x % 2 > y % 2;
		return x < y;
	};
	stable_sort(a, a + m, comp);
	
	if (m >= 3 && a[2] % 2 == 1) {
		cout << "Impossible" << endl;
		return 0;
	}
	
	vector<int> b;
	if (a[0] % 2 == 0) {
		b = solveA();
	}
	else if (m == 1 || a[1] % 2 == 0) {
		b = solveB();
	}
	else {
		b = solveC();
	}
	
	rep(i, m) {
		cout << a[i];
		if (i + 1 < m) cout << " ";
	}
	cout << endl;
	
	cout << b.size() << endl;
	rep(i, b.size()) {
		cout << b[i];
		if (i + 1 < b.size()) cout << " ";
	}
	cout << endl;
	
	return 0;
}