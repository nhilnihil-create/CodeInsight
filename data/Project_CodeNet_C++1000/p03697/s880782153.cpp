#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_restricted(void) {
	int a, b;
	cin >> a >> b;
	int sum = a + b;

	if (sum >= 10) cout << "error" << endl;
	else           cout << sum << endl;
}

int main()
{
    a_restricted();
    return 0;
}