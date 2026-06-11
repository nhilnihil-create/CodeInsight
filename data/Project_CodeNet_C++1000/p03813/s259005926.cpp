#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_abc_arc(void) {
	int x;
	cin >> x;
	cout << (x < 1200 ? "ABC" : "ARC") << endl;
}

int main()
{
    a_abc_arc();
    return 0;
}