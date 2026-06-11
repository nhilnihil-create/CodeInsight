#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void a_candy_and_two_children(void) {
	int a, b, c;
	cin >> a >> b >> c;
	string msg = "Yes";

	if (a + b == c) msg = "Yes";
	else if (a + c == b) msg = "Yes";
	else if (b + c == a) msg = "Yes";
	else                msg = "No";


	cout << msg << endl;
}

int main()
{
	a_candy_and_two_children();
    return 0;
}