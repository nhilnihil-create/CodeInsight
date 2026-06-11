#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_ringring(void) {
	int a, b, c;
	cin >> a >> b >> c;

	int sum = a + b + c;
	int max_val = max(a, b);
	max_val = max(max_val, c);
	sum -= max_val;

	cout << sum << endl;
}

int main()
{
    a_ringring();
    return 0;
}