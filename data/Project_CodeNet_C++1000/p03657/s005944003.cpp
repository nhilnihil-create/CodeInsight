#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_sharing_cookies(void) {
	int a, b;
	cin >> a >> b;

	if (a % 3 == 0) {
		cout << "Possible" << endl;
	}
	else if (b % 3 == 0) {
		cout << "Possible" << endl;
	}
	else if ((a + b) % 3 == 0) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}

int main()
{
    a_sharing_cookies();
    return 0;
}