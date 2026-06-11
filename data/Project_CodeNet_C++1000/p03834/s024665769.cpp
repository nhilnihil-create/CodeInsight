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
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (s.at(i) != ',') cout << s.at(i);
		else cout << " ";
	}
	cout << endl;
	
}