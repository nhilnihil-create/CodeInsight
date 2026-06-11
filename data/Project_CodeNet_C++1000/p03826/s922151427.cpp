#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_two_rectangles(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sa = a * b;
	int sb = c * d;
	
	if (sa == sb) cout << sa << endl;
	else {
		cout << (sa > sb ? sa : sb) << endl;
	}
}

int main()
{
    a_two_rectangles();
    return 0;
}