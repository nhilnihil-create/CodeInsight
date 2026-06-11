#include <iostream>
#include <algorithm>
#include <string> 
#include <vector>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

int main()
{
	string S;
	cin >> S;
	string ex = "YAKI";
	if (S.size() < 4) {
		cout << "No" << endl;
	}
	else {
		if (S.substr(0, 4) == ex) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}