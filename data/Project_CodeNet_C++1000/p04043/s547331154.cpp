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
	vector<int> vec(3);

	for (int i = 0; i < 3; ++i) {
		cin >> vec.at(i);
	}

	sort(vec.begin(),vec.end());

	bool ans = true;

	for (int i = 0; i < 3; ++i) {
		if (i < 2) {
			if (vec.at(i) != 5) ans = false;
		}
		else {
			if (vec.at(i) != 7) ans = false;
		}
	}

	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	
}