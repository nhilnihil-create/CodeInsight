#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_remaining_time(void) {
	int a, b;
	cin >> a >> b;

	cout << (a + b) % 24 << endl;
}

int main()
{
    a_remaining_time();
    return 0;
}