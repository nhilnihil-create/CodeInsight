#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_beetween_a_and_b(void) {
	long int a, b, x;
	cin >> a >> b >> x;
	long int cnt = 0;
	long int div_a=0;
	long int div_b = b / x;
	if (a == 0) div_b += 1;
	else {
		div_a = (a - 1) / x;
	}
	cout << div_b-div_a << endl;
}

int main()
{
	b_beetween_a_and_b();
    return 0;
}