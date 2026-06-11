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
	
	int x = n / 100;
	int  y = (n - 100*x) / 10;
	int z = n - 100*x - 10*y;
	
	if (x == z) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}