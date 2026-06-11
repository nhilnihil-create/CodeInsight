#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	vector<int> v(3);
	cin >> v.at(0) >> v.at(1) >> v.at(2);

	sort(v.begin(), v.end());
	cout << v.at(0) + v.at(1) << endl;
}