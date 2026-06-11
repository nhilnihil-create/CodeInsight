#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_sandglass2(void) {
	int x, t;
	cin >> x >> t;
	cout << ((x - t<0)?0:x-t) << endl;
}

int main()
{
    a_sandglass2();
    return 0;
}