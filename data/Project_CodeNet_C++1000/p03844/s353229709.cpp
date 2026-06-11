#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void a_addition_and_sub_easy(void) {
	int a, b;
	char op;
	cin >> a >> op >> b;
	if (op == '+') {
		cout << a + b << endl;
	}
	else {
		cout << a - b << endl;
	}
}

int main()
{
	a_addition_and_sub_easy();
    return 0;
}