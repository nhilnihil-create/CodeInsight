#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_meal_delivery(void) {
	int x, a, b;
	cin >> x >> a >> b;

	if (abs(x - a) < abs(x - b)) cout << "A" << endl;
	else                         cout << "B" << endl;
}

int main()
{
    a_meal_delivery();
    return 0;
}