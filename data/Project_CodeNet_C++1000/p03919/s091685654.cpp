#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <regex>
#include <stack>
#include <queue>
#include <vector>
#define MAX_N 100
#define INF 10000000

using namespace std;

string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int n,m;
string s;

void solve() {
	string a;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == "snuke") { y = i+1; x = j; }
		}
	}
	cout << ALP[x] << y << endl;
}

int main() {
	cin >> n>>m;
	solve();
	return 0;
}