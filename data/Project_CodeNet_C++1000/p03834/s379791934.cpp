#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string haiku;
	cin >> haiku;
	haiku[5] = ' ';
	haiku[13] = ' ';
	cout << haiku << endl;
	return 0;
}