#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	vector<int> a{ 0,1,3,1,2,1,2,1,1,2,1,2,1, };
	int x, y;
	cin >> x >> y;

	cout << (a[x] == a[y] ? "Yes" : "No") << endl;

}