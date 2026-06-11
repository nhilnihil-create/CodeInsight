#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int x, y;
	cin >> x >> y;
	set<int>a = { 4,6,9,11 };
	if (x == 2 || y == 2)cout << "No" << endl;
	else if (a.count(x) && a.count(y))cout << "Yes" << endl;
	else if (!a.count(x) && !a.count(y))cout << "Yes" << endl;
	else cout << "No" << endl;

}