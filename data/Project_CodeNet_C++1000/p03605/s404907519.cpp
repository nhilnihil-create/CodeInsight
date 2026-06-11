#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib> 
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	str = to_string(n);
	
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '9') {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}