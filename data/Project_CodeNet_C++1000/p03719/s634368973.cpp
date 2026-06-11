#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_between_two_intergers(void) {
	int a, b, c;
	cin >> a >> b >> c;

	if ((c >= a) && (c <= b)) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}

int main()
{
    a_between_two_intergers();
    return 0;
}