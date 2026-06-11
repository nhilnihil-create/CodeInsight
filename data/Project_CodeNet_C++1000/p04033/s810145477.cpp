#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void agc_a_range_product(void) {
	long long a, b;
	cin >> a >> b;

	if (a > 0) cout << "Positive" << endl;
	else if ((a <= 0) && (b >= 0)) cout << "Zero" << endl;
	else {
		int step = abs(b - a)+1;
		if ((step & 0x1) == 0x0) cout << "Positive" << endl;
		else                     cout << "Negative" << endl;
	}

}

int main()
{
    agc_a_range_product();
    return 0;
}