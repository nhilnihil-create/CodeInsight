#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_palindromic_number(void) {
	string n;
	cin >> n;

	if (n[0] == n[2]) cout << "Yes" << endl;
	else              cout << "No" << endl;
}

int main()
{
    a_palindromic_number();
    return 0;
}